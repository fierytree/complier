#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"

enum NodeType
{
    NODE_CONST, 
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,

    NODE_STMT,
    NODE_PARA,
    NODE_FUNC,
    NODE_PROG,
};

enum OperatorType
{
    OP_EQ,  // ==
    OP_LOP_ASS,  //=
};

enum StmtType {
    STMT_SKIP,
    STMT_DECL,
}
;

struct TreeNode {
public:
    int nodeID;  // 用于作业的序号输出
    int lineno;
    NodeType nodeType;

    TreeNode* child=nullptr;
    vector<TreeNode*> siblings;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
    void printNodeInfo();
    void printChildrenId();

    void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo();

public:
    OperatorType optype;  // 如果是表达式
    Type* type;  // 变量、类型、表达式结点，有类型。
    StmtType stype;
    int int_val;
    char ch_val;
    bool b_val;
    string str_val;
    string var_name;

public:
    static string nodeType2String (NodeType t);
    static string opType2String (OperatorType t);
    static string sType2String (StmtType t);

    static int node_num;
public:
    TreeNode(int lineno, NodeType type);
    TreeNode(){}
};

#endif