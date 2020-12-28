#include "common.h"
#include <fstream>
#define pb code.push_back
#define c1 cur->child
#define c2 cur->child->siblings
#define c3 cur->child->siblings->siblings

ofstream fout("debug.txt");
extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();
extern map<pair<string,int>,TreeNode*> id_list;
extern TreeNode* find_id(TreeNode* t);
int TreeNode::node_num=0;
int tmp_var;
int labal;
bool put;
vector<string> code;
using namespace std;
string reg[]={"%eax","%ecx","%edx","%ebx","%edi","%esi"};
vector<TreeNode*> global_var;
map<string,string> str_list;
string op_inst[]={
	"imull","idivl","idivl","addl","subl","sall","salr","setle","setge","setl",
    "setg","sete","setne","log_and","log_or","andl","orl","xorl","ass",
    "addl","subl","imull","idiv","idiv","sall","salr",
    "andl","orl","xorl","negl","pos_sign","sete",
    "notl","addr","star","incl","decl","incl","decl" ,"br"   
};

bool ptr(TreeNode*cur){
    if(cur->type==nullptr)return 0;
    if(cur->type->type==COMPOSE_POINTER)return 1;
    if(cur->nodeType==NODE_VAR&&cur->type->type==COMPOSE_ARRAY)return 1;
    if(cur->nodeType==NODE_ARRAY){
        Type*t=id_list[make_pair(c1->var_name,c1->scope.first)]->type;
        int dim=0;
        while(t->type==COMPOSE_ARRAY)dim++,t=t->retType;
        return dim>cur->array_dim;
    }
    return 0;
}
void resize(TreeNode* cur){
    if(tmp_var>=4){
        cur->pa_func->stack_size=4*(tmp_var-3);
        cur->pa_func->reg_count=min(max(cur->reg_count,tmp_var),6);
    }
}
void new_temp(TreeNode* cur){
    fout<<"tmp_var:"<<tmp_var<<endl;
    if(cur->nodeType==NODE_VAR)return;
    if(tmp_var<6){
        cur->place=reg[tmp_var++];resize(cur);
    }            
    else{
        tmp_var++;resize(cur);
        cur->place=(-cur->pa_func->stack_size)+"(%ebp)";
    }
    if(cur->array_dim>=1)fout<<"array "<<cur->nodeID<<" "<<cur->place<<endl;
    else if(cur->nodeType==NODE_STMT&&cur->stype==STMT_FUNC_USE)
    fout<<"func ret"<<cur->nodeID<<" "<<cur->place<<endl;
    else fout<<cur->opType2String(cur->optype)<<" "<<cur->nodeID<<" "<<cur->place<<endl;
}
void del_temp(TreeNode* cur){
    if(!cur->place.empty()&&cur->nodeType==NODE_VAR
    &&cur->type->type==COMPOSE_ARRAY)tmp_var--;
    else if(!cur->place.empty()&&cur->nodeType==NODE_EXPR)tmp_var--;
    else if(cur->nodeType==NODE_STMT&&cur->stype==STMT_FUNC_USE)tmp_var--;
}

void raise_error(int ln,string s){
    cerr<<"in line"<<ln<<", ";
    cerr<<s<<endl;
    exit(0);
}
string get_val(int ln,TreeNode* cur){
    if(cur->is_const)return "$"+to_string(cur->int_val);
    if(cur->nodeType==NODE_EXPR)return cur->place;
    Type* t=cur->type;
    int v=0;
    if(*t==*TYPE_INT)v=cur->int_val;
    else if(*t==*TYPE_CHAR)v=cur->ch_val;
    else if(*t==*TYPE_BOOL)v=cur->b_val;
    else if(*t==*TYPE_STRING)return "$"+str_list[cur->str_val];
    else raise_error(ln,"error value type");
    return "$"+to_string(v);
}
void judge(int ln,Type* t1,Type* t2,string s){
    string s1=t1->getTypeInfo();
    string s2=t2->getTypeInfo();
    if(*t1!=*t2&&t1->type+t2->type!=1)raise_error(ln,s+"expect "+s1+" get "+s2);
}
void check_children(TreeNode* cur);
Type* check_array(TreeNode* cur);
Type* check_func(TreeNode* cur);
Type* check_union(TreeNode* cur);
Type* check(TreeNode* cur){
    //fout<<"check "<<cur->nodeID<<endl;
    int ln=cur->lineno;
    switch(cur->nodeType){
        case NODE_PROG:case NODE_FUNC:case NODE_PARA:{
            check_children(cur);
            if(cur->nodeType==NODE_PROG)fout<<"type check pass!"<<endl;
            return TYPE_VOID;
        }
        case NODE_CONST:{
            if(*cur->type==*TYPE_STRING){
                int k=str_list.size();
                if(str_list.find(cur->str_val)==str_list.end())
                str_list[cur->str_val]=".STR"+to_string(k);                
            }
            cur->place=get_val(ln,cur);
            return cur->type;
        }
        case NODE_TYPE:{
            return cur->type;
        }
        case NODE_VAR:{
            if(cur->type->type==COMPOSE_FUNCTION){
                auto y=make_pair(cur->var_name,0);
                if(id_list.find(y)==id_list.end()||id_list[y]->lineno>cur->lineno){
                    raise_error(ln,"undifined fuction!"+cur->var_name);
                }
                else{
                    cur->scope=id_list[y]->scope;
                    cur->type=id_list[y]->type;
                }
            }
            else if(cur->type->type==COMPOSE_ARRAY)new_temp(cur);
            return cur->type;
        }
        case NODE_STMT:{
            switch (cur->stype){
                case STMT_SKIP:case STMT_BLOCK:case STMT_FOR:{
                    check_children(cur);break;
                }
                case STMT_BREAK:case STMT_CONTINUE:break;
                case STMT_DECL:{
                    Type* t=check(c1);
                    TreeNode* tmp=c2;
                    while(tmp!=nullptr){
                        if(tmp->child!=nullptr&&!tmp->child->is_const){
                            Type* t2=check(tmp);                        
                            judge(ln,t,t2,"declaration type ");
                        }
                        tmp=tmp->siblings;
                    }break;
                }
                case STMT_WHILE:{
                    Type* expr=check(c1);
                    check(c2);
                    judge(ln,TYPE_BOOL,expr,"while expression type ");break;
                }
                case STMT_IF:{
                    Type* expr=check(c1);
                    check(c2);
                    if(c3!=nullptr)check(c3);
                    judge(ln,TYPE_BOOL,expr,"if expression type ");break;
                }
                case STMT_RETURN:{
                    Type* t=c1==nullptr?TYPE_VOID:check(c1);
                    judge(ln,cur->pa_func->type,t,"return type ");break;
                }
                case STMT_FUNC_USE:return check_func(cur);                    
            }
            tmp_var=0;
            return TYPE_VOID;
        }
        case NODE_EXPR:{           
            TreeNode* tmp=c1;
            Type* ret;
            if(cur->optype==OP_ADD||cur->optype==OP_ADD_ASS
            ||cur->optype==OP_SUB||cur->optype==OP_SUB_ASS){
                Type* t1=check(c1);
                Type* t2=check(c2);
                if(ptr(c1))ret=t1;
                else if(ptr(c2))ret=t2;
                else judge(ln,TYPE_INT,t1,"add/sub obj type "),
                judge(ln,TYPE_INT,t2,"add/sub obj type "),ret=TYPE_INT;
            }
            else if(cur->optype>=OP_INCR&&cur->optype<=OP_BACK_DECR){
                Type* t1=check(c1);
                if(t1->type==COMPOSE_POINTER)return t1;
                else judge(ln,TYPE_INT,t1,"inc/dec obj type "),ret=TYPE_INT;
            }
            else if(cur->optype>=OP_LOP_ASS&&cur->optype<=OP_XOR_ASS){
                Type* t1=check(c1);
                if(c1->is_const==1)raise_error(ln,"const var can't be assigned");
                ret=check(c2);
                if(*t1!=*ret){
                    if(t1->type+ret->type==1)return TYPE_INT;
                    string s1=t1->getTypeInfo();
                    string s2=ret->getTypeInfo();
                    raise_error(ln,s1+" can't be assigned with "+s2);
                }
            }
            else if(cur->optype==OP_ADDR){
                check(c1);
                if(c1->nodeType!=NODE_VAR)
                raise_error(ln,"addr operation object must be a var");
                Type* t=new Type(COMPOSE_POINTER);
                t->retType=c1->type;
                ret=t;
            }
            else if(cur->optype==OP_STAR){
                check(c1);
                if(c1->nodeType!=NODE_VAR||c1->type->type!=COMPOSE_POINTER)
                raise_error(ln,"dereference operation object must be a pointer");
                ret=c1->type->retType;
            }
            else{
                ret=TYPE_BOOL;
                while(tmp!=nullptr){
                    Type* t=check(tmp);
                    if(*t==*TYPE_INT)ret=TYPE_INT;
                    else if(*t!=*TYPE_BOOL){
                        raise_error(ln,"expression element can't be "+t->getTypeInfo());
                    }
                    tmp=tmp->siblings;
                }
            }
            tmp=c1;
            while(tmp!=nullptr){
                if(tmp->nodeType==NODE_ARRAY){
                    TreeNode* tmp2=tmp->child->siblings;
                    while(tmp2!=nullptr)del_temp(tmp2),tmp2=tmp2->siblings;
                }
                if(tmp->reg_count==-2||(tmp->nodeType==NODE_STMT&&tmp->stype==STMT_FUNC_USE)){
                    cur->reg_count=-2;
                }
                del_temp(tmp),tmp=tmp->siblings;
            }
            if(cur->reg_count==-2){
               tmp=c1;
               while(tmp!=nullptr){
                   new_temp(tmp);
                   if(tmp->place=="%eax")new_temp(tmp);
                   tmp=tmp->siblings;
               }
               tmp=c1;
               while(tmp!=nullptr)del_temp(tmp),tmp=tmp->siblings;
            }
            new_temp(cur);
            cur->type=ret;
            return ret;
        }
        case NODE_ARRAY:{
            return check_array(cur);
        }
    }
    return TYPE_VOID;
}
void check_children(TreeNode* cur){
    TreeNode* tmp=c1;
    while(tmp!=nullptr){
        check(tmp);
        if(tmp->nodeType==NODE_EXPR)tmp_var=0;
        tmp=tmp->siblings;
    }
}
Type* check_union(TreeNode* cur){
    if(cur->type->type!=COMPOSE_UNION)raise_error(cur->lineno," function parament type error");
    Type *t1=new Type(COMPOSE_UNION);
    TreeNode* tmp=c1;
    while(tmp!=nullptr){
        t1->addChild(check(tmp));
        tmp=tmp->siblings;
    }
    return t1;
}
Type* check_func(TreeNode* cur){
    Type* t=check(c1);
    string name=c1->var_name;
    int ln=cur->lineno;
    if(name=="printf"||name=="scanf"){
        TreeNode* pa=c2;
        Type* t=check(pa->child);
        if(*t!=*TYPE_STRING)raise_error(ln,"the first parament should be string");
        string str=pa->child->str_val;
        int cnt=0,k=0;
        for(auto x:str)if(x=='%')++cnt;
        TreeNode* tmp=pa->child->siblings;
        while(tmp!=nullptr)++k,check(tmp),tmp=tmp->siblings;
        if(k!=cnt)raise_error(ln,"inconsistent string format");
        return TYPE_VOID;
    }
    Type *t1=check_union(c2);
    if(*t1!=*t->paramType)raise_error(ln,"function "+name+" parament type didn't match");
    new_temp(cur);if(cur->place=="%eax")new_temp(cur);
    cur->type=t->retType;
    return t->retType; 
}
Type* check_array(TreeNode* cur){
    Type* t1=c1->type;
    string name=c1->var_name;
    int ln=cur->lineno;
    TreeNode* tmp=c2;
    while(tmp!=nullptr){
        if(t1==nullptr)raise_error(ln,"array "+name+" type didn't match");
        Type* t=(check(tmp));
        if(*t!=*TYPE_INT&&*t!=*TYPE_BOOL){
            raise_error(ln,"array sub should be integer");
        }
        t1=t1->retType;
        tmp=tmp->siblings;
    }
    cur->type=t1;
    new_temp(cur);
    return t1;
}

void gen_children(TreeNode* cur);
inline void new_labal(){
    pb(".L"+to_string(labal++)+":");
}
inline void mov(string a,string b){
    if(a!=b){
        if(a[0]!='%'&&a[0]!='$'&&b[0]!='%'&&b[0]!='$'){
            pb("\tpushl\t%eax");
            pb("\tmovl\t"+a+", %eax");
            pb("\tmovl\t%eax, "+b);
            pb("\tpopl\t%eax");
        }
        else pb("\tmovl\t"+a+", "+b);
    }
}
void cast2(string dst,string s1,string op,int k){
    if(k==1)pb("\t"+op+"\t"+s1),mov(s1,dst);
    else if(k==0) mov(s1,dst),pb("\t"+op+"\t"+s1);
    else mov(s1,dst),pb("\t"+op+"\t"+dst);
}
void cast3(string dst,string s1,string s2,string op){
    if(dst==s2){
        if(op=="sall"||op=="sarl"||op=="subl"){
            if(s1[0]=='%'){
                pb("\t"+op+"\t"+s2+", "+s1),mov(s1,dst);
                mov("0(%esp)",s1);
            }
            else{
                pb("\tpushl\t"+s1);
                pb("\t"+op+"\t"+s2+", "+s1),mov(s1,dst);
                pb("\tpopl\t"+s1);
            }
        }
        else pb("\t"+op+"\t"+s1+", "+dst);
    }
    else mov(s1,dst),pb("\t"+op+"\t"+s2+", "+dst);
}
bool gen_pointer(TreeNode* cur);
void gen_arr_ass(TreeNode* cur);
void gen_op_inst(TreeNode* cur){
    string op=op_inst[cur->optype];
    if(op=="idivl"){
        if(c1->place=="%eax"&&c2->place=="%ecx"){
            pb("\tcltd\t");
            pb("\tidivl\t%ecx");
            if(cur->optype==OP_SUR)mov("%edx","%eax");
            return;
        }
        pb("\tpushl\t%eax");
        pb("\tpushl\t%ecx");
        pb("\tpushl\t%edx");
        pb("\tpushl\t"+c1->place);
        pb("\tpushl\t"+c2->place);
        mov("0(%esp)","%ecx");
        mov("4(%esp)","%eax");
        pb("\tcltd\t");
        pb("\tidivl\t%ecx");
        string p=cur->optype==OP_DIV||cur->optype==OP_DIV_ASS?"%eax":"%edx";
        string s=cur->place;
        if(cur->place=="%eax")s="16(%esp)";
        else if(cur->place=="%ecx")s="12(%esp)";
        else if(cur->place=="%edx")s="8(%esp)";
        mov(p,cur->place);
        mov(cur->place,s);
        pb("\taddl\t$8, %esp");
        pb("\tpopl\t%edx");
        pb("\tpopl\t%ecx");
        pb("\tpopl\t%eax");
        return;
    }
    cast3(cur->place,c1->place,c2->place,op_inst[cur->optype]);
}
void gen_cmp_inst(TreeNode* cur){
    string op=op_inst[cur->optype];
    string s1=c1->place,s2=c2->place;
    if(s1[0]!='$'&&s1[0]!='%'&&s2[0]!='%'){
        if(cur->place!="%eax")pb("\tpushl\t%eax");
        mov(s2,"%eax");
        pb("\tcmpl\t%eax, "+s1);
        pb("\t"+op+"\t%al");
        pb("\tmovzbl %al, %eax");
        mov("%eax",cur->place);
        if(cur->place!="%eax")pb("\tpopl\t%eax");
        return;
    }
    pb("\tcmpl\t"+s2+", "+s1);
    if(cur->place!="%eax"){
        pb("\tpushl\t%eax");
        pb("\t"+op+"\t%al");
        pb("\tmovzbl %al, "+cur->place);
        pb("\tpopl\t%eax");
        return;
    }
    pb("\t"+op+"\t%al");
    pb("\tmovzbl %al, %eax");
}
void locate(){
    for(auto x:id_list){
        TreeNode* cur=x.second;
        if(cur->type->type!=COMPOSE_FUNCTION){
            //fout<<x.first.first<<endl;
            if(cur->scope.first==0){
                global_var.push_back(x.second);
                cur->place=x.first.first;
            }
            else if(cur->pa_func!=nullptr){
                if(cur->array_dim>=1){
                    cur->pa_func->stack_size+=cur->type->sz()/4*4;
                }
                else{
                    cur->pa_func->stack_size+=4;
                }
                cur->place="-"+to_string(cur->pa_func->stack_size)+"(%ebp)";
            }
        }
    }
    for(auto x:id_list){
        if(x.second->type->type==COMPOSE_FUNCTION){
            if(x.first.first=="printf"||x.first.first=="scanf"){
                x.second->place=x.second->var_name;continue;
            }
            TreeNode* para=x.second->pa_func->child->siblings->siblings;
            TreeNode* tmp=para->child;
            int cnt=4;
            while(tmp!=nullptr){               
                if(tmp->nodeType==NODE_VAR){
                    cnt+=4;
                    auto y=make_pair(tmp->var_name,tmp->scope.first);
                    id_list[y]->place=tmp->place=to_string(cnt)+"(%ebp)";
                }
                tmp=tmp->siblings;
            }
            global_var.push_back(x.second);
            x.second->place=x.second->var_name;
        }
    }
}
string cal_arr_place(TreeNode* cur);
void gen_code(TreeNode* cur){
    fout<<"gencode id "<<cur->nodeID<<endl;
    int ln=cur->lineno;
    switch(cur->nodeType){
        case NODE_PROG:{
            pb("\t.text");
            gen_children(cur);
            pb("\t.section\t.note.GNU-stack,\"\",@progbits");
            fout<<"code has been generated"<<endl;
            return ;
        }
        case NODE_FUNC:{
            string name=cur->var_name;
            if(str_list.size()!=0&&!put){
                pb("\t.section\t.rodata\t");
                for(auto x:str_list){
                    pb(x.second+":");
                    pb("\t.string\t\""+x.first+"\"");
                }
                put=1;
            }
            pb("\t.text\t");
            pb("\t.globl\t"+name);
            pb("\t.type\t"+name+", @function");
            pb(name+":");
            pb("\tendbr32");
            pb("\tpushl\t%ebp");
            pb("\tmovl\t%esp, %ebp");
            for(int j=3;j<cur->reg_count;j++){
                pb("\tpushl\t"+reg[j]);
            }
            int s=cur->stack_size-cur->reg_count*4;
            if(s>0)pb("\tsubl\t$"+to_string(s)+", %esp");

            gen_code(c3->siblings);
            return;
        }
        case NODE_PARA:{
            return;
        }
        case NODE_CONST:case NODE_TYPE:{
            return;
        }
        case NODE_VAR:{
            if(cur->type->type==COMPOSE_ARRAY){
                string s=id_list[make_pair(cur->var_name,cur->scope.first)]->place;
                pb("\tleal\t"+s+", "+cur->place);
            }
            else if(cur->place.empty())
            cur->place=id_list[make_pair(cur->var_name,cur->scope.first)]->place;
            return;
        }
        case NODE_STMT:{
            switch (cur->stype){
                case STMT_SKIP:break;
                case STMT_BLOCK:{
                    gen_children(cur);return;
                }
                case STMT_FOR:{
                    gen_code(c1);
                    bool q=cur->quit_labal==-2;
                    bool st=cur->start_labal==-2;
                    int lb=labal;labal+=q||st?4:2;
                    if(st)cur->start_labal=lb+3;
                    if(q)cur->quit_labal=lb+2;
                    pb("\tjmp\t.L"+to_string(lb));
                    pb(".L"+to_string(lb+1)+":");
                    gen_code(c3->siblings);
                    if(st)pb(".L"+to_string(lb+3)+":");
                    gen_code(c3);
                    pb(".L"+to_string(lb)+":");
                    gen_code(c2);
                    pb("\tcmpl\t$1, "+c2->place);
                    pb("\tje\t.L"+to_string(lb+1));
                    if(q)pb(".L"+to_string(lb+2)+":"),pb("\tnop");break;
                }
                case STMT_DECL:{
                    TreeNode* tmp=c2;
                    if(c2->array_dim>=1&&c2->pa_func!=nullptr)break;
                    if(cur->pa_func!=nullptr){gen_children(cur);break;}
                    string val,name;
                    while(tmp!=nullptr){
                    if(tmp->child!=nullptr)val=get_val(ln,tmp->child->siblings),name=tmp->child->var_name;                    
                    else val="$0",name=tmp->var_name;
                    if(val[0]!='$')raise_error(ln,"global var ass error");
                    if(c2->array_dim>=1){
                        pb("\t.comm\t"+name+','+to_string(c2->child->type->sz())+",32");
                        return;
                    }
                    pb("\t.globl\t"+name);
                    pb("\t.data\t");
                    pb("\t.align 4");
                    pb("\t.type\t"+name+", @object");
                    pb(name+":");
                    if(*c1->type==*TYPE_CHAR)pb("\t.byte\t"+val.substr(1));
                    else pb("\t.long\t"+val.substr(1));
                    tmp=tmp->siblings;
                    }
                    break;
                }
                case STMT_WHILE:{
                    bool q=cur->quit_labal==-2;                    
                    int lb=labal;labal+=q?3:2;
                    cur->start_labal=lb+1;
                    pb("\tjmp\t.L"+to_string(lb));
                    pb(".L"+to_string(lb+1)+":");
                    gen_code(c2);
                    pb(".L"+to_string(lb)+":");
                    gen_code(c1);
                    pb("\tcmpl\t$1, "+c1->place);
                    pb("\tje\t.L"+to_string(lb+1));
                    if(q)pb(".L"+to_string(lb+2)+":"),pb("\tnop");break;
                }
                case STMT_IF:{
                    bool el=c3!=nullptr;
                    int lb=labal;labal+=el?2:1;
                    gen_code(c1);
                    pb("\tcmpl\t$0, "+c1->place);
                    if(el){
                        pb("\tje\t.L"+to_string(lb));
                        gen_code(c2);
                        pb("\tjmp\t.L"+to_string(lb+1));
                        pb(".L"+to_string(lb)+":");
                        gen_code(c3);
                        pb(".L"+to_string(lb+1)+":");
                    }
                    else{
                        pb("\tje\t.L"+to_string(lb));
                        gen_code(c2);
                        pb(".L"+to_string(lb)+":");
                    }break;
                }
                case STMT_RETURN:{
                    gen_children(cur);
                    if(c1!=nullptr){
                        string s=get_val(ln,c1);
                        mov(c1->place,"%eax");
                    }
                    int s=cur->pa_func->stack_size-cur->pa_func->reg_count*4;
                    if(s>0)pb("\taddl\t$"+to_string(s)+", %esp");
                    for(int j=3;j<cur->pa_func->reg_count;j++){
                        pb("\tpopl\t"+reg[j]);
                    }
                    pb("\tpopl\t%ebp");
                    pb("\tret");
                    break;
                }
                case STMT_BREAK:{
                    pb("\tjmp\t.L"+to_string(cur->pa_loop->quit_labal));break;
                }
                case STMT_CONTINUE:{
                    pb("\tjmp\t.L"+to_string(cur->pa_loop->start_labal));break;
                }
                case STMT_FUNC_USE:{
                    gen_code(c1);
                    TreeNode* tmp=c2->child;
                    vector<string> pa;
                    while(tmp!=nullptr){
                        gen_code(tmp);
                        pa.push_back(tmp->place);
                        tmp=tmp->siblings;
                    }
                    for(int i=pa.size()-1;i>=0;i--)pb("\tpushl\t"+pa[i]);
                    pb("\tcall\t"+c1->place);
                    if(cur->place.size()>0)mov("%eax",cur->place);
                    pb("\taddl\t$"+to_string(pa.size()*4)+", %esp");break;
                }                  
            }
            return;
        }
        case NODE_EXPR:{
            if(cur->is_const){
                mov(get_val(ln,cur),cur->place);
                return;
            }
            if(gen_pointer(cur))return;
            if(cur->optype<OP_LOP_ASS||cur->optype>OP_XOR_ASS)gen_children(cur);
            switch(cur->optype){
                case OP_ADD:case OP_SUB:case OP_MUL:case OP_DIV:case OP_SUR:
                case OP_LSHIFT:case OP_RSHIFT:
                case OP_BIT_OR:case OP_BIT_AND:case OP_BIT_XOR:{
                    gen_op_inst(cur);break;
                }
                case OP_GT:case OP_LT:case OP_GE:case OP_LE:case OP_EQ:case OP_UEQ:{
                    gen_cmp_inst(cur);break;
                }
                case OP_ADD_ASS:case OP_SUB_ASS:case OP_DIV_ASS:case OP_SUR_ASS:
                case OP_MUL_ASS:case OP_LS_ASS:case OP_RS_ASS:case OP_AND_ASS:
                case OP_OR_ASS:case OP_XOR_ASS:{
                    gen_arr_ass(cur);
                    gen_op_inst(cur);
                    mov(cur->place,c1->place);break;                    
                }
                case OP_LOP_ASS:{
                    gen_arr_ass(cur);
                    mov(c2->place,c1->place);
                    mov(c2->place,cur->place);break;
                }
                case OP_BR:case OP_UADD:{
                    mov(c1->place,cur->place);break;
                }
                case OP_INCR:case OP_BACK_INCR:case OP_DECR:case OP_BACK_DECR:{
                    int a[]={1,1,0,0};
                    cast2(cur->place,c1->place,op_inst[cur->optype],
                    a[cur->optype-OP_INCR]);break;
                }
                case OP_BIT_NOT:case OP_UMINUS:{
                    cast2(cur->place,c1->place,op_inst[cur->optype],2);break;
                }
                case OP_LOG_OR:{
                    int lb=labal;labal+=3; 
                    pb("\tcmpl\t$0, "+c1->place);
                    pb("\tjne\t.L"+to_string(lb));
                    pb("\tcmpl\t$0, "+c2->place);
                    pb("\tje\t.L"+to_string(lb+1));
                    pb(".L"+to_string(lb)+":");
                    mov("$1",cur->place);
                    pb("\tjmp\t.L"+to_string(lb+2));
                    pb(".L"+to_string(lb+1)+":");
                    mov("$0",cur->place);
                    pb(".L"+to_string(lb+2)+":");break;
                }
                case OP_LOG_AND:{
                    int lb=labal;labal+=2;
                    pb("\tcmpl\t$0, "+c1->place);
                    pb("\tje\t.L"+to_string(lb));
                    pb("\tcmpl\t$0, "+c2->place);
                    pb("\tje\t.L"+to_string(lb));
                    mov("$1",cur->place);
                    pb("\tjmp\t.L"+to_string(lb+1));
                    pb(".L"+to_string(lb)+":");
                    mov("$0",cur->place);
                    pb(".L"+to_string(lb+1)+":");break;
                }
                case OP_LOG_NOT:{
                    TreeNode* t=new TreeNode(0,NODE_CONST);
                    t->place="$0";
                    c2=t;
                    gen_cmp_inst(cur);
                    delete t;break;
                }
                case OP_ADDR:{
                    if(cur->place[0]!='%'){
                        pb("\tpushl\t%eax");
                        pb("\tleal\t"+c1->place+", %eax");
                        mov("%eax",cur->place);
                        pb("\tpopl\t%eax");
                    }
                    else pb("\tleal\t"+c1->place+", "+cur->place);break;
                }
                case OP_STAR:{
                    if(c1->place[0]!='%'&&cur->place[0]=='%'){
                        mov(c1->place,cur->place);
                        mov('('+cur->place+')',cur->place);
                    }
                    else if(cur->place[0]!='%'){
                        pb("\tpushl\t%eax");
                        mov(c1->place,"%eax");
                        mov("(%eax)",cur->place);
                        pb("\tpopl\t%eax");
                    }
                    else mov('('+c1->place+')',cur->place);
                    break;
                }
                default:
                break;
            }
            return ;
        }
        case NODE_ARRAY:{
            string p=cal_arr_place(cur);
            mov(p,cur->place);
            return;
        }
    }
}
void gen_children(TreeNode* cur){
    TreeNode* tmp=c1;
    while(tmp!=nullptr){
        //fout<<"gencode id "<<tmp->nodeID<<endl;
        gen_code(tmp);
        //fout<<"gencode id over "<<tmp->nodeID<<endl;
        tmp=tmp->siblings;
    }
}
string cal_arr_place(TreeNode* cur){
    string s=id_list[make_pair(c1->var_name,c1->scope.first)]->place;
    c1->place=s;
    string p="";
    TreeNode* tmp=c2;
    while(tmp!=nullptr)gen_code(tmp),tmp=tmp->siblings;
    Type* arr=c1->type;
    tmp=c2;
    mov(tmp->place,cur->place);tmp=tmp->siblings;
    while(arr->retType->type==COMPOSE_ARRAY&&tmp!=nullptr){
        cast3(cur->place,"$"+to_string(arr->size),cur->place,"imull");
        cast3(cur->place,cur->place,tmp->place,"addl");
        tmp=tmp->siblings,arr=arr->retType;
    }
    if(arr->retType->type!=COMPOSE_ARRAY){
        string sz=to_string(arr->retType->sz());
        if(c1->scope.first==0)p=c1->var_name+"(,"+cur->place+","+sz+")";
        else{
            p=s.substr(0,s.size()-1)+","+cur->place+","+sz+")";
        }
    }
    else{
        while(arr->retType->type==COMPOSE_ARRAY){
            cast3(cur->place,"$"+to_string(arr->size),cur->place,"imull");
            arr=arr->retType;
        }
        cast3(cur->place,"$"+to_string(arr->retType->sz()),cur->place,"imull");
        if(cur->place[0]!='%'){
            pb("\tpushl\t%eax");
            pb("\tleal\t"+c1->place+", %eax");
            pb("\taddl\t%eax, "+cur->place);
            pb("\tpopl\t%eax");
        }
        else{
            pb("\tpushl\t"+cur->place);
            pb("\tleal\t"+c1->place+", "+cur->place);
            pb("\taddl\t0(%esp), "+cur->place);
            pb("\taddl\t$4, %esp");
        }
        p=cur->place;
    }
    return p; 
}
void gen_arr_ass(TreeNode* cur){
    if(c1->array_dim>=1){
        string p=cal_arr_place(c1);
        c1->place=p;
        gen_code(c2);
    }
    else gen_children(cur);
}
bool gen_pointer(TreeNode* cur){
    if(c2==nullptr&&!ptr(c1))return 0;
    if(c2!=nullptr&&!ptr(c1)&&!ptr(c2))return 0;
    if(cur->optype==OP_LOP_ASS||cur->optype==OP_ADDR||cur->optype==OP_STAR)return 0;
    //fout<<"gen pointer "<<cur->opType2String(cur->optype)<<endl;
    gen_children(cur);
    if(cur->optype>=OP_INCR&&cur->optype<=OP_BACK_DECR){
        string op[]={"addl","subl","addl","subl"};
        int sz=c1->type->retType->sz();
        cast3(c1->place,c1->place,'$'+to_string(sz),op[cur->optype-OP_INCR]);return 1;
    }
    string s1=c1->place;string s2=c2->place;
    int sz=4;
    if(ptr(c2))sz=c2->type->retType->sz(),swap(s1,s2);   
    else sz=c1->type->retType->sz();
    //fout<<c1->nodeID<<" "<<c1->type->getTypeInfo()<<endl;
    if(cur->optype==OP_ADD||cur->optype==OP_SUB){
        if(s2[0]=='$'){
            sz=atoi(s2.substr(1).c_str())*sz;
            cast3(cur->place,s1,'$'+to_string(sz),op_inst[cur->optype]);
        }
        else{
            cast3(cur->place,s2,'$'+to_string(sz),"imul");
            cast3(cur->place,cur->place,s1,op_inst[cur->optype]);
        }
    }
    else if(cur->optype==OP_ADD_ASS||cur->optype==OP_SUB_ASS){
        if(s2[0]=='$'){
            sz=atoi(s2.substr(1).c_str())*sz;
            cast3(c1->place,c1->place,'$'+to_string(sz),op_inst[cur->optype]);
            mov(c1->place,cur->place);
        }
        else{
            cast3(cur->place,s2,'$'+to_string(sz),"imul");
            cast3(c1->place,cur->place,cur->place,op_inst[cur->optype]);
            mov(c1->place,cur->place);
        }
    }
    else return 0;
    return 1;
}
TreeNode* new_func(string name){
    TreeNode* t=new TreeNode(0,NODE_FUNC);
    t->var_name=name;
    t->type=TYPE_VOID;
    t->child=new TreeNode(0,NODE_TYPE);
    t->child->type=TYPE_VOID;
    t->child->siblings=new TreeNode(0,NODE_VAR);
    t->child->siblings->var_name=name;
    t->child->siblings->type=new Type(COMPOSE_FUNCTION);
    t->child->siblings->pa_func=t;
    t->child->siblings->siblings=new TreeNode(0,NODE_PARA);
    return t->child->siblings;
}
int main(int argc, char *argv[])
{
    TreeNode* print=new_func("printf");
    TreeNode* scan=new_func("scanf");
    id_list[make_pair("printf",0)]=print;
    id_list[make_pair("scanf",0)]=scan;
    fout<<setiosflags(ios::left);
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin != nullptr)
        {
            yyin = fin;
        }
        else
        {
            cerr << "failed to open file: " << argv[1] << endl;
        }
    }
    fout<<"file has been opened"<<endl;
    yyparse();
    if(root != NULL) {
        root->printAST();
    }

    fout<<endl;check(root);
    root->printType();

    fout<<endl;locate();
    fout<<"place:"<<endl;
    for(auto x:id_list)fout<<x.second->var_name<<" "<<x.second->place<<endl;

    gen_code(root);
    for(auto x:code)cout<<x<<endl;
    return 0;
}