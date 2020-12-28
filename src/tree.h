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
    NODE_ARRAY,

    NODE_STMT,
    NODE_PARA,
    NODE_FUNC,
    NODE_PROG,
};

enum OperatorType
{
	OP_MUL,
	OP_DIV,
	OP_SUR,
	OP_ADD,
	OP_SUB,
	OP_LSHIFT,
	OP_RSHIFT,
	OP_LE,
	OP_GE,
	OP_LT,
	OP_GT,
	OP_EQ,
	OP_UEQ,
	OP_LOG_AND,
	OP_LOG_OR,
	OP_BIT_AND,
	OP_BIT_OR,
	OP_BIT_XOR,
	OP_LOP_ASS,
	OP_ADD_ASS,
	OP_SUB_ASS,
	OP_MUL_ASS,
	OP_DIV_ASS,
	OP_SUR_ASS,
	OP_LS_ASS,
	OP_RS_ASS,
	OP_AND_ASS,
	OP_OR_ASS,
	OP_XOR_ASS,
    OP_UMINUS,
    OP_UADD,
    OP_LOG_NOT,
    OP_BIT_NOT,
    OP_ADDR,
    OP_STAR,
    OP_INCR,
    OP_DECR,
    OP_BACK_INCR,
    OP_BACK_DECR,
    OP_BR    
};

enum StmtType {
    STMT_SKIP,
    STMT_DECL,
    STMT_WHILE,
    STMT_FOR,
    STMT_IF,
    STMT_RETURN,
    STMT_BLOCK,
    STMT_FUNC_USE,
    STMT_BREAK,
    STMT_CONTINUE
}
;

struct TreeNode {
public:
    int nodeID;  // 用于作业的序号输出
    int lineno;
    NodeType nodeType;

    TreeNode* child=nullptr;
    TreeNode* siblings=nullptr;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
    void printNodeInfo();
    void printChildrenId();

    void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo();
    void printType();

public:
    OperatorType optype;  // 如果是表达式
    Type* type=nullptr;  // 变量、类型、表达式结点，有类型。
    StmtType stype;
    int int_val;
    char ch_val;
    bool b_val;
    string str_val;
    string var_name;
    pair<int,int> scope;
    bool is_const;
    int array_dim;
    TreeNode* pa_func=nullptr;
    TreeNode* pa_loop=nullptr;
    string place;
    int stack_size;
    int reg_count;
    int start_labal;
    int quit_labal;

public:
    static string nodeType2String (NodeType t);
    static string opType2String (OperatorType t);
    static string sType2String (StmtType t);

    static int node_num;
    bool rd2();
    bool rd();
    int val();
public:
    TreeNode(int lineno, NodeType type);
    TreeNode(){}
};

#endif