%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
%}
%token T_CHAR T_INT T_STRING T_BOOL T_VOID

%token LEFTBR RIGHTBR
%token LBRACE RBRACE

%token LOP_ASSIGN 

%token SEMICOLON

%token COMMA

%token IDENTIFIER INTEGER CHAR BOOL STRING

%left LOP_EQ

%%

program
: statements {root = new TreeNode(0, NODE_PROG); root->addChild($1);};

statements
:  statement {$$=$1;}
|  statements statement {$$=$1; $$->addSibling($2);}
;

statement
: SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
| declaration SEMICOLON {$$ = $1;}
| function {$$ = $1;}
;

function
: T IDENTIFIER LEFTBR PARMS RIGHTBR LBRACE statements RBRACE{
    TreeNode* node = new TreeNode($1->lineno, NODE_FUNC);
    node->var_name=$2->var_name;
    node->type=$1->type;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    node->addChild($7);
    $$=node;
}
| T IDENTIFIER LEFTBR RIGHTBR LBRACE statements RBRACE{
    TreeNode* node = new TreeNode($1->lineno, NODE_FUNC);
    node->var_name=$2->var_name;
    node->type=$1->type;
    node->addChild($1);
    node->addChild($2);
    node->addChild($6);
    $$=node;
}
| T_VOID IDENTIFIER LEFTBR PARMS RIGHTBR LBRACE statements RBRACE{
    TreeNode* node = new TreeNode($1->lineno, NODE_FUNC);
    TreeNode* node2 = new TreeNode(lineno, NODE_TYPE); node2->type = TYPE_VOID;
    node->var_name=$2->var_name;
    node->type=node2->type;
    node->addChild(node2);
    node->addChild($2);
    node->addChild($4);
    node->addChild($7);
    $$=node;
}
| T_VOID IDENTIFIER LEFTBR RIGHTBR LBRACE statements RBRACE{
    TreeNode* node = new TreeNode($1->lineno, NODE_FUNC);
    TreeNode* node2 = new TreeNode(lineno, NODE_TYPE); node2->type = TYPE_VOID;
    node->var_name=$2->var_name;
    node->type=node2->type;
    node->addChild(node2);
    node->addChild($2);
    node->addChild($6);
    $$=node;
}
;

PARMS
: T IDENTIFIER{
    TreeNode* node = new TreeNode($1->lineno, NODE_PARA);
    node->addChild($1);
    node->addChild($2);
}
| PARMS COMMA T IDENTIFIER{
    $$=$1;
    TreeNode* node = new TreeNode($1->lineno, NODE_PARA);
    node->addChild($3);
    node->addChild($4);
    $$->addSibling(node);
}
;
declaration
: T IDENTIFIER LOP_ASSIGN expr{  // declare and init
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $$ = node;   
} 
| T IDENTIFIERS {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $$ = node;   
}
;
IDENTIFIERS
: IDENTIFIER{
    $$=$1;
}
| IDENTIFIERS COMMA IDENTIFIER{
    $$=$1;
    $$->addSibling($3);
}
;

expr
: IDENTIFIER {
    $$ = $1;
}
| INTEGER {
    $$ = $1;
}
| CHAR {
    $$ = $1;
}
| STRING {
    $$ = $1;
}
;

T: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
| T_STRING {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_STRING;}
;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}