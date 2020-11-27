%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
    map<pair<string,int>,TreeNode*> id_list2;
%}
%token T_CHAR T_INT T_STRING T_BOOL T_VOID

%token LOP_ASS ADD_ASS SUB_ASS MUL_ASS DIV_ASS SUR_ASS LS_ASS RS_ASS AND_ASS OR_ASS XOR_ASS
%token LOG_OR
%token LOG_AND
%token BIT_OR
%token BIT_XOR
%token BIT_AND
%token EQ UEQ
%token GT LT GE LE
%token LSHIFT RSHIFT 
%token ADD SUB
%token MUL DIV SUR
%token LEFTBR RIGHTBR
%token LBRACE RBRACE

%token SEMICOLON

%token COMMA

%token IDENTIFIER INTEGER CHAR BOOL STRING
%token IF WHILE FOR RETURN

%right LOP_ASS ADD_ASS SUB_ASS MUL_ASS DIV_ASS SUR_ASS LS_ASS RS_ASS AND_ASS OR_ASS XOR_ASS
%left LOG_OR
%left LOG_AND
%left BIT_OR
%left BIT_XOR
%left BIT_AND
%left EQ UEQ
%left GT LT GE LE
%left LSHIFT RSHIFT 
%left ADD SUB
%left MUL DIV SUR
%left LEFTBR RIGHTBR
%left LBRACE RBRACE
%right UMINUS UADD


%%

program
: units {root = new TreeNode(0, NODE_PROG); root->addChild($1);};
;

units
: declaration SEMICOLON{$$=$1;};
| function {$$=$1;}
| units declaration SEMICOLON{$$=$1;$$->addSibling($2);}
| units function {$$=$1;$$->addSibling($2);}
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

statements
:  statement {$$=$1;}
|  statements statement {$$=$1; $$->addSibling($2);}
;

statement
: SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
| declaration SEMICOLON {$$ = $1;}
| WHILE LEFTBR expr RIGHTBR LBRACE statements RBRACE{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_WHILE;
    node->addChild($3);
    node->addChild($6);
    $$=node;
}
| FOR LEFTBR expr SEMICOLON expr SEMICOLON expr RIGHTBR LBRACE statements RBRACE{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    node->addChild($10);
    $$=node;
}
| IF LEFTBR expr RIGHTBR LBRACE statements RBRACE{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($3);
    node->addChild($6);
    $$=node;
}
| RETURN expr SEMICOLON{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    node->addChild($1);
    $$=node;
}
| expr SEMICOLON{
    $$=$1;
}
;

declaration
: T IDENTIFIER LOP_ASS expr{  
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    auto x=make_pair($2->var_name,$2->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=$2;
    else cout<<"Variable "<<$2->var_name<<" repeated definition"<<endl;
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $$ = node;   
} 
| T IDENTIFIERS {
    TreeNode* node = new TreeNode($2->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $$ = node;   
}
;

IDENTIFIERS
: IDENTIFIER{
    $$=$1;
    auto x=make_pair($1->var_name,$1->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=$1;
    else cout<<"Variable "<<$1->var_name<<" repeated definition"<<endl;
}
| IDENTIFIERS COMMA IDENTIFIER{
    $$=$1;
    $$->addSibling($3);
    auto x=make_pair($3->var_name,$3->scope.first);
    if(id_list2.find(x)==id_list2.end())id_list2[x]=$3;
    else cout<<"Variable "<<$3->var_name<<" repeated definition"<<endl;
}
;

expr
: IDENTIFIER {
    int s=-1;
    TreeNode* v=nullptr;
    for(auto &x:id_list2){
        if(x.first.first==$1->var_name){
            if(x.first.second>s){
                s=x.first.second;
                v=new TreeNode($1->lineno, NODE_VAR);
                v->var_name=x.second->var_name;
                v->scope=x.second->scope;
            }
        }
    }
    if(s==-1||v==nullptr)cout<<"Variable "<<$1->var_name<<" undefinied"<<endl;
    else $$=v;
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
| expr ADD expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_ADD;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr SUB expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_SUB;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr MUL expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_MUL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr DIV expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_DIV;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr SUR expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_SUR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr LSHIFT expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LSHIFT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr RSHIFT expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_RSHIFT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr BIT_AND expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_BIT_AND;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr BIT_OR expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_BIT_OR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr BIT_XOR expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_BIT_XOR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr EQ expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_EQ;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr UEQ expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_UEQ;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr LT expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr GT expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_GT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr LE expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LE;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr GE expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_GE;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr LOG_AND expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LOG_AND;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr LOG_OR expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LOG_OR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr LOP_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LOP_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr ADD_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_ADD_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr SUB_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_SUB_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr MUL_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_MUL_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr DIV_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_DIV_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr SUR_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_SUR_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr LS_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LS_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr RS_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_RS_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr OR_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_OR_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr AND_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_AND_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr XOR_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_XOR_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| SUB expr %prec UMINUS {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_UMINUS;
    node->addChild($2);
    $$ = node;
}
| ADD expr %prec UADD {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_UADD;
    node->addChild($2);
    $$ = node;
}
| LEFTBR expr RIGHTBR {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_BR;
    node->addChild($2);
    $$ = node;
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