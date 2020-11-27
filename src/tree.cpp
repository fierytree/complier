#include "tree.h"

void TreeNode::addChild(TreeNode* child) {
    if(this->child==nullptr)this->child=child;    
    else this->child->addSibling(child);
}

void TreeNode::addSibling(TreeNode* sibling){
    siblings.push_back(sibling);
}

TreeNode::TreeNode(int lineno, NodeType type) {
    this->lineno=lineno;
    this->nodeType=type;
    nodeID=node_num;
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
            cout<<"var "<<"\t";
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
            cout<<"name:"<<var_name<<"\t";      
            break;
        }
        case NODE_PARA:{
            cout<<"para"<<"\t";
            cout<<"type:"+sType2String(stype)<<"\t";    
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
    if(child!=nullptr){
        cout<<child->nodeID;
        for(auto x:child->siblings){
            cout<<","<<x->nodeID;
        }
    }
    cout<<"\t"<<endl;
}

void TreeNode::printAST() {
    printNodeInfo();
    printChildrenId();
    visited.push_back(this->nodeID);
    sort(visited.begin(),visited.end());

    if(child!=nullptr){
        queue<TreeNode*>q;
        if(find(visited.begin(),visited.end(),child->nodeID)==visited.end())q.push(child);
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            x->printAST();
            for(auto &y:x->siblings){
                if(find(visited.begin(),visited.end(),y->nodeID)==visited.end())q.push(y);
            }
        }
    }
}

// You can output more info...
void TreeNode::printSpecialInfo() {
    switch(this->nodeType){
        case NODE_CONST:
            break;
        case NODE_VAR:
            break;
        case NODE_EXPR:
            break;
        case NODE_STMT:
            break;
        case NODE_TYPE:
            break;
        default:
            break;
    }
}

string TreeNode::sType2String(StmtType t) {
    string stype_name[]={"skip","decl","while","for","if","return"};
    return stype_name[t];
}


string TreeNode::nodeType2String (NodeType t){
    string nodeType_name[]={"const","var","expr","type","stmt","para","func","prog"};
    return nodeType_name[t];
}

string TreeNode::opType2String (OperatorType t){
    string optype_name[]={
	"mul","div","sur","add","sub","lshift","rshift","le","ge",	
    "lt","gt","eq","ueq","log_and","log_or","bit_and","bit_or",	
    "bit_xor","ass","add_ass","sub_ass","mul_ass","div_ass","sur_ass",	
    "ls_ass","rs_ass","and_ass","or_ass","xor_ass","minus_sign","pos_sign","br"    
    };
    return optype_name[t];
}