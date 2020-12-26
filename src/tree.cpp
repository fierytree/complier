#include "tree.h"

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
    node_num++;
}

void TreeNode::printNodeInfo() {
    cout<<"@"<<nodeID<<"\t"<<"lineno:"<<lineno<<"\t";
    switch(this->nodeType){
        case NODE_CONST:{
            cout<<"const"<<"\t";
            string t=type->getTypeInfo();
            cout<<t<<"\t";
            cout<<"val:";
            if(t=="int ")cout<<int_val<<"\t";
            else if(t=="char")cout<<ch_val<<"\t";
            else if(t=="bool")cout<<b_val<<"\t";
            else if(t=="string")cout<<str_val<<"\t";
            else cout<<"errorType" ;
            break;
        }
            
        case NODE_VAR:{
            if(is_const)cout<<"const var"<<"\t";
            else cout<<"var "<<"\t";
            cout<<"name:"<<var_name<<"\t";
            if(scope.first==0)cout<<"scope:global"<<"\t";
            else cout<<"scope:br"<<scope.first<<" in line"<<scope.second<<"\t";
            break;
        }
        case NODE_EXPR:{
            cout<<"expr"<<"\t";
            cout<<"op:"+opType2String(optype)<<"\t";    
            break;
        }
        case NODE_STMT:{
            cout<<"stmt"<<"\t";
            cout<<"type:"+sType2String(stype)<<"\t";
            if(stype==STMT_FUNC_USE)cout<<"name:"<<var_name<<"\t";      
            break;
        }
        case NODE_PARA:{
            cout<<"para"<<"\t";   
            break;
        }
        case NODE_FUNC:{
            cout<<"func"<<"\t";
            cout<<"type:"+type->getTypeInfo()<<"\t";
            cout<<"name:"<<var_name<<"\t";    
            break;
        }
        case NODE_TYPE:{
            cout<<"type"<<"\t";
            cout<<type->getTypeInfo()<<"\t";
            break;
        }
        case NODE_ARRAY:{
            cout<<"array"<<"\t";
            cout<<"dimen:"<<array_dim<<"\t";
            break;
        }
        case NODE_PROG:{
            cout<<"prog"<<"\t";
            break;
        }
        default:{
            cout<<"error nodetype"<<"\t";
            break;
        }
    }
}

void TreeNode::printChildrenId() {
    cout<<"children:";
    vector<int> re;
    TreeNode* tmp=child;
    while(tmp!=nullptr){
        re.push_back(tmp->nodeID);
        tmp=tmp->siblings;
    }
    //sort(re.begin(),re.end());
    for(unsigned i=0;i<re.size();i++){
        cout<<re[i];
        if(i!=re.size()-1)cout<<",";
    }
    cout<<"\t"<<endl;
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
            tmp=tmp->siblings;
        }
        sort(v.begin(),v.end(),cmp);
        for(auto& x:v)q.push(x);
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
    string stype_name[]={"skip","decl","while","for","if","return","block","func_use"};
    return stype_name[t];
}


string TreeNode::nodeType2String (NodeType t){
    string nodeType_name[]={"const","var","expr","type","array","stmt","para","func","prog"};
    return nodeType_name[t];
}

string TreeNode::opType2String (OperatorType t){
    string optype_name[]={
	"mul","div","sur","add","sub","lshift","rshift","le","ge","lt","gt",
    "eq","ueq","log_and","log_or","bit_and","bit_or","bit_xor","ass",
    "add_ass","sub_ass","mul_ass","div_ass","sur_ass","ls_ass","rs_ass",
    "and_ass","or_ass","xor_ass","minus_sign","pos_sign","log_not",
    "bit_not","addr","incr","decr","b_incr","b_decr" ,"br"   
    };
    return optype_name[t];
}