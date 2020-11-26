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

    if(child!=nullptr){
        child->printAST();
        for(auto &x:child->siblings){
            x->printAST();
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
    string stype_name[]={"skip","decl"};
    return stype_name[t];
}


string TreeNode::nodeType2String (NodeType t){
    string nodeType_name[]={"const","var","expr","type","stmt","prog"};
    return nodeType_name[t];
}

string TreeNode::opType2String (OperatorType t){
    string optype_name[]={"EQ","LOP_ASS"};
    return optype_name[t];
}