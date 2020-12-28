#include "tree.h"
extern ofstream fout;
void TreeNode::addChild(TreeNode* child) {
    if(this->child==nullptr)this->child=child;    
    else this->child->addSibling(child);
}

void TreeNode::addSibling(TreeNode* sibling){
    TreeNode* tmp=this;
    while(tmp->siblings!=nullptr)tmp=tmp->siblings;   
    tmp->siblings=sibling;
}

TreeNode::TreeNode(int lineno, NodeType type) {
    this->lineno=lineno;
    this->nodeType=type;
    nodeID=node_num;
    is_const=0;
    stack_size=-1,reg_count=-1;
    start_labal=-1,quit_labal=-1;
    node_num++;
}

void TreeNode::printNodeInfo() {
    fout<<"@"<<nodeID<<"\t"<<"lineno:"<<lineno<<"\t";
    switch(this->nodeType){
        case NODE_CONST:{
            fout<<"const"<<"\t";
            string t=type->getTypeInfo();
            fout<<t<<"\t";
            fout<<"val:";
            if(t=="int ")fout<<int_val<<"\t";
            else if(t=="char")fout<<ch_val<<"\t";
            else if(t=="bool")fout<<b_val<<"\t";
            else if(t=="string")fout<<str_val<<"\t";
            else fout<<"errorType" ;
            break;
        }
            
        case NODE_VAR:{
            if(is_const)fout<<"const var"<<"\t";
            else fout<<"var "<<"\t";
            fout<<"name:"<<var_name<<"\t";
            if(scope.first==0)fout<<"scope:global"<<"\t";
            else fout<<"scope:br"<<scope.first<<" in line"<<scope.second<<"\t";
            break;
        }
        case NODE_EXPR:{
            fout<<"expr"<<"\t";
            fout<<"op:"+opType2String(optype)<<"\t";    
            break;
        }
        case NODE_STMT:{
            fout<<"stmt"<<"\t";
            fout<<"type:"+sType2String(stype)<<"\t";
            if(stype==STMT_FUNC_USE)fout<<"name:"<<var_name<<"\t";      
            break;
        }
        case NODE_PARA:{
            fout<<"para"<<"\t";   
            break;
        }
        case NODE_FUNC:{
            fout<<"func"<<"\t";
            fout<<"type:"+type->getTypeInfo()<<"\t";
            fout<<"name:"<<var_name<<"\t";    
            break;
        }
        case NODE_TYPE:{
            fout<<"type"<<"\t";
            fout<<type->getTypeInfo()<<"\t";
            break;
        }
        case NODE_ARRAY:{
            fout<<"array"<<"\t";
            fout<<"dimen:"<<array_dim<<"\t";
            break;
        }
        case NODE_PROG:{
            fout<<"prog"<<"\t";
            break;
        }
        case NODE_STRUCT:{
            fout<<"struct"<<"\t";
            fout<<"member:"<<"\t";
            for(auto x:type->paramType->childType)
            fout<<x->name<<":\t"<<x->getTypeInfo()<<"\t";
            break;
        }
        default:{
            fout<<"error nodetype"<<"\t";
            break;
        }
    }
}

void TreeNode::printChildrenId() {
    fout<<"children:";
    vector<int> re;
    TreeNode* tmp=child;
    while(tmp!=nullptr){
        re.push_back(tmp->nodeID);
        tmp=tmp->siblings;
    }
    //sort(re.begin(),re.end());
    for(unsigned i=0;i<re.size();i++){
        fout<<re[i];
        if(i!=re.size()-1)fout<<",";
    }
    fout<<"\t"<<endl;
}
bool cmp(TreeNode* t1,TreeNode* t2){
    return t1->nodeID<t2->nodeID;
}
void TreeNode::printAST() {
    queue<TreeNode*> q;
    q.push(this);
    while(!q.empty()){
        TreeNode* cur=q.front();
        cur->printNodeInfo();
        cur->printChildrenId();
        q.pop();
        vector<TreeNode*> v;
        TreeNode* tmp=cur->child;
        while(tmp!=nullptr){
            v.push_back(tmp);
            if(cur->pa_func!=nullptr)tmp->pa_func=cur->pa_func;
            if(cur->pa_loop!=nullptr&&tmp->pa_loop==nullptr)tmp->pa_loop=cur->pa_loop;
            if(tmp->nodeType==NODE_STMT&&tmp->stype==STMT_BREAK)
            tmp->pa_loop->quit_labal=-2;
            if(tmp->nodeType==NODE_STMT&&tmp->stype==STMT_CONTINUE)
            tmp->pa_loop->start_labal=-2;
            tmp=tmp->siblings;
        }
        for(auto& x:v)q.push(x);
    }
}

void TreeNode::printType() {
    queue<TreeNode*> q;
    q.push(this);
    while(!q.empty()){
        TreeNode* cur=q.front();
        fout<<cur->nodeID<<" ";
        if(cur->type!=nullptr)
        fout<<cur->type->getTypeInfo()<<" "<<cur->place<<endl;
        q.pop();
        TreeNode* tmp=cur->child;
        while(tmp!=nullptr)q.push(tmp),tmp=tmp->siblings;
    }
}

bool TreeNode::rd2(){
    return is_const=child->nodeType==NODE_CONST&&child->siblings->nodeType==NODE_CONST;
}

bool TreeNode::rd(){
    return is_const=child->nodeType==NODE_CONST;
}

int TreeNode::val(){
    int v=0;
    if(*type==*TYPE_INT)v=int_val;
    else if(*type==*TYPE_CHAR)v=ch_val;
    else if(*type==*TYPE_BOOL)v=b_val;
    return v;
}

string TreeNode::sType2String(StmtType t) {
    string stype_name[]={"skip","decl","while","for","if","return","block",
    "func_use","break","continue"};
    return stype_name[t];
}


string TreeNode::nodeType2String (NodeType t){
    string nodeType_name[]={"const","var","expr","type","array","stmt",
    "para","func","prog","struct"};
    return nodeType_name[t];
}

string TreeNode::opType2String (OperatorType t){
    string optype_name[]={
	"mul","div","sur","add","sub","lshift","rshift","le","ge","lt","gt",
    "eq","ueq","log_and","log_or","bit_and","bit_or","bit_xor","ass",
    "add_ass","sub_ass","mul_ass","div_ass","sur_ass","ls_ass","rs_ass",
    "and_ass","or_ass","xor_ass","minus_sign","pos_sign","log_not",
    "bit_not","addr","star","incr","decr","b_incr","b_decr" ,"br","st_mb","stp_mb"   
    };
    return optype_name[t];
}