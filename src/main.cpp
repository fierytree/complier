#include "common.h"
#include <fstream>

extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();
extern map<pair<string,int>,TreeNode*> id_list;
int TreeNode::node_num=0;
using namespace std;

void raise_error(int ln,string s){
    cerr<<"in line"<<ln<<", ";
    cerr<<s<<endl;
    exit(0);
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
    int ln=cur->lineno;
    switch(cur->nodeType){
        case NODE_PROG:case NODE_FUNC:case NODE_PARA:{
            check_children(cur);
            if(cur->nodeType==NODE_PROG)cout<<"type check pass!"<<endl;
            return TYPE_VOID;
        }
        case NODE_CONST:case NODE_TYPE:case NODE_VAR:{
            return cur->type;
        }
        case NODE_STMT:{
            switch (cur->stype){
                case STMT_SKIP:case STMT_BLOCK:case STMT_FOR:{
                    check_children(cur);break;
                }
                case STMT_DECL:{
                    Type* t=check(cur->child);
                    TreeNode* tmp=cur->child->siblings;
                    while(tmp!=nullptr){
                        Type* t2=check(tmp);
                        judge(ln,t,t2,"declaration type ");
                        tmp=tmp->siblings;
                    }break;
                }
                case STMT_WHILE:{
                    Type* expr=check(cur->child);
                    check(cur->child->siblings);
                    judge(ln,TYPE_BOOL,expr,"while expression type ");break;
                }
                case STMT_IF:{
                    Type* expr=check(cur->child);
                    check(cur->child->siblings);
                    if(cur->child->siblings->siblings!=nullptr)check(cur->child->siblings->siblings);
                    judge(ln,TYPE_BOOL,expr,"if expression type ");break;
                }
                case STMT_RETURN:{
                    Type* t=cur->child==nullptr?TYPE_VOID:check(cur->child);
                    judge(ln,cur->func_type->retType,t,"return type ");break;
                }
                case STMT_FUNC_USE:return check_func(cur);                    
            }
            return TYPE_VOID;
        }
        case NODE_EXPR:{           
            TreeNode* tmp=cur->child;
            if(cur->optype==OP_LOP_ASS){
                Type* t1=check(tmp);
                Type* t2=check(tmp->siblings);
                if(*t1!=*t2){
                    if(t1->type+t2->type==1)return TYPE_INT;
                    string s1=t1->getTypeInfo();
                    string s2=t2->getTypeInfo();
                    raise_error(ln,s1+" can't be assigned with "+s2);
                }
                return t2;
            }
            Type* cur=TYPE_BOOL;
            while(tmp!=nullptr){
                Type* t=check(tmp);
                if(*t==*TYPE_INT)cur=TYPE_INT;
                else if(*t!=*TYPE_BOOL){
                    raise_error(ln,"expression element can't be "+t->getTypeInfo());
                }
                tmp=tmp->siblings;
            }
            return cur;
        }
        case NODE_ARRAY:{
            return check_array(cur);
        }
    }
    return TYPE_VOID;
}
void check_children(TreeNode* cur){
    TreeNode* tmp=cur->child;
    while(tmp!=nullptr){
        check(tmp);
        tmp=tmp->siblings;
    }
}
Type* check_union(TreeNode* cur){
    if(cur->type->type!=COMPOSE_UNION)raise_error(cur->lineno," function parament type error");
    Type *t1=new Type(COMPOSE_UNION);
    TreeNode* tmp=cur->child;
    while(tmp!=nullptr){
        t1->addChild(check(tmp));
        tmp=tmp->siblings;
    }
    return t1;
}
Type* check_func(TreeNode* cur){
    Type* t=check(cur->child);
    string name=cur->child->var_name;
    if(name=="printf"||name=="scanf")return TYPE_VOID;
    int ln=cur->lineno;
    Type *t1=check_union(cur->child->siblings);
    if(*t1!=*t->paramType)raise_error(ln,"function "+name+" parament type didn't match");
    return t->retType; 
}
Type* check_array(TreeNode* cur){
    Type* t1=cur->child->type;
    string name=cur->child->var_name;
    int ln=cur->lineno;
    TreeNode* tmp=cur->child->siblings;
    while(tmp!=nullptr){
        if(t1==nullptr)raise_error(ln,"array "+name+" type didn't match");
        Type* t=(check(tmp));
        if(*t!=*TYPE_INT&&*t!=*TYPE_BOOL){
            raise_error(ln,"array sub should be integer");
        }
        t1=t1->retType;
        tmp=tmp->siblings;
    }
    return t1;
}
int main(int argc, char *argv[])
{
    TreeNode* print=new TreeNode(0,NODE_FUNC);
    print->var_name="printf";
    TreeNode* scan=new TreeNode(0,NODE_FUNC);
    scan->var_name="scanf";
    id_list[make_pair("printf",0)]=print;
    id_list[make_pair("scanf",0)]=scan;
    cout<<setiosflags(ios::left);
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
    cout<<"file has been opened"<<endl;
    yyparse();
    if(root != NULL) {
        root->printAST();
    }
    check(root);
    return 0;
}