%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    extern int br_count;
    extern vector<pair<int,int> > br_list;
    int yylex();
    int yyerror( char const * );
    map<pair<string,int>,TreeNode*> id_list;
    void add_id(TreeNode* t){
        auto x=make_pair(t->var_name,t->scope.first);
        if(id_list.find(x)==id_list.end())id_list[x]=t;
        else cout<<"Variable "<<t->var_name<<" repeated definition"<<endl;
    }
    TreeNode* find_id(TreeNode* t){
        auto s=make_pair(-1,-1);
        if(id_list.find(make_pair(t->var_name,0))!=id_list.end())s=make_pair(0,0);
        for(auto x:br_list){
            //cout<<x.first<<" "<<x.second<<endl;
            auto y=make_pair(t->var_name,x.first);
            if(id_list.find(y)!=id_list.end())s=x;
        }
        //cout<<s.first<<" ss "<<s.second<<endl;
        t->scope=s;
        if(s.first==-1)cout<<"Variable "<<t->var_name<<" undefinied"<<endl;
        return t;
    }
    
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
%token BIT_NOT LOG_NOT
%token INCR DECR
%token LEFTBR RIGHTBR
%token LBRACE RBRACE
%token M_LBR M_RBR

%token SEMICOLON

%token COMMA

%token IDENTIFIER INTEGER CHAR BOOL STRING HEX_INTEGER
%token IF WHILE FOR RETURN CONST

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
%right ADDR
%right LEFTBR RIGHTBR
%right LOG_NOT BIT_NOT
%right UMINUS UADD
%right INCR DECR
%left M_LBR M_RBR
%left BACK_INCR BACK_DECR


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
: T IDENTIFIER for_LEFTBR PARMS for_RIGHTBR block{
    TreeNode* node = new TreeNode($1->lineno, NODE_FUNC);
    add_id($2);
    node->var_name=$2->var_name;
    node->type=$1->type;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    node->addChild($6);
    $$=node;
}
;

PARMS
: T IDENTIFIER{
    TreeNode* node = new TreeNode($1->lineno, NODE_PARA);
    add_id($2);
    node->addChild($1);
    node->addChild($2);
    $$=node;
}
| PARMS COMMA T IDENTIFIER{
    $$=$1;
    add_id($4);
    $1->addChild($3);
    $1->addChild($4);
}
| {$$ = new TreeNode(lineno, NODE_PARA);}
;

block_item
: statement {$$=$1;}
| declaration SEMICOLON {$$ = $1;}
;

block_items
: block_item {$$=$1;}
| block_items block_item {$$=$1; $$->addSibling($2);}
;

block
:LBRACE block_items RBRACE{
    TreeNode* node = new TreeNode(lineno, NODE_STMT); 
    node->stype = STMT_BLOCK;
    node->addChild($2);
    $$=node;
}

statement
: SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
| block {$$=$1;}
| WHILE LEFTBR expr RIGHTBR statement{
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    node->stype=STMT_WHILE;
    node->addChild($3);
    node->addChild($5);
    $$=node;
}
| FOR for_LEFTBR for_expr SEMICOLON for_expr SEMICOLON for_expr for_RIGHTBR statement{
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    node->addChild($9);
    $$=node;
}
| IF LEFTBR expr RIGHTBR statement{
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($3);
    node->addChild($5);
    $$=node;
}
| RETURN expr SEMICOLON{
    TreeNode* node = new TreeNode($2->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    node->addChild($2);
    $$=node;
}
| RETURN SEMICOLON{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    $$=node;
}
| expr SEMICOLON{
    $$=$1;
}
;

for_expr
: declaration
| expr
|
;

for_LEFTBR:LEFTBR{$$=$1;br_list.push_back(make_pair(br_count+1,lineno));};
for_RIGHTBR:RIGHTBR{$$=$1;br_list.pop_back();};

declaration
: T IDENTIFIER LOP_ASS expr{ 
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    add_id($2);
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
| T ARRAY {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $$ = node;
}
| CONST T_INT IDENTIFIER LOP_ASS CONST_EXP{
    TreeNode* node1 = new TreeNode($3->lineno, NODE_TYPE);node1->type=TYPE_INT;    
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    $3->is_const=1;
    add_id($3);
    node->stype = STMT_DECL;
    node->addChild(node1);
    node->addChild($3);
    node->addChild($5);
    $$ = node;
}
| CONST T_CHAR IDENTIFIER LOP_ASS CHAR{
    TreeNode* node1 = new TreeNode($3->lineno, NODE_TYPE);node1->type=TYPE_CHAR; 
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    $3->is_const=1;
    add_id($3);
    node->stype = STMT_DECL;
    node->addChild(node1);
    node->addChild($3);
    node->addChild($5);
    $$ = node;
}
| CONST T_BOOL IDENTIFIER LOP_ASS INTEGER{
    TreeNode* node1 = new TreeNode($3->lineno, NODE_TYPE);node1->type=TYPE_BOOL; 
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    $3->is_const=1;
    add_id($3);
    node->stype = STMT_DECL;
    node->addChild(node1);
    node->addChild($3);
    node->addChild($5);
    $$ = node;
}
;
CONST_EXP
: INTEGER {$$=$1;}
| CONST_EXP ADD CONST_EXP{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_ADD;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| CONST_EXP SUB CONST_EXP{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_SUB;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| CONST_EXP MUL CONST_EXP{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_MUL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| CONST_EXP DIV CONST_EXP{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_DIV;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| CONST_EXP LSHIFT CONST_EXP{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LSHIFT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| SUB CONST_EXP %prec UMINUS{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_UMINUS;
    node->addChild($2);
    $$ = node;
}
| LEFTBR CONST_EXP RIGHTBR{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_BR;
    node->addChild($2);
    $$ = node;
}
;

ARRAY
: IDENTIFIER M_LBR CONST_EXP M_RBR{
    TreeNode* node = new TreeNode($1->lineno, NODE_ARRAY);
    add_id($1);
    node->array_dim=1;
    node->addChild($1);
    node->addChild($3);
    $$=node;
}
| ARRAY M_LBR CONST_EXP M_RBR{
    $1->array_dim+=1;
    $$=$1;
    $1->addSibling($3);
}
;

ARRAY2
: IDENTIFIER M_LBR expr M_RBR {
    TreeNode* node = new TreeNode($1->lineno, NODE_ARRAY);
    node->array_dim=1;
    node->addChild(find_id($1));
    node->addChild($3);
    $$=node;
}
| ARRAY2 M_LBR expr M_RBR {
    $1->array_dim+=1;
    $$=$1;
    $1->addSibling($3);
}

LVAL
: ARRAY2 {$$=$1;}
| IDENTIFIER {$$=$1;}

IDENTIFIERS
: IDENTIFIER{
    $$=$1;
    add_id($1);
}
| IDENTIFIERS COMMA IDENTIFIER{
    $$=$1;
    $$->addSibling($3);
    add_id($3);
}
;

PAS
: expr {$$=$1;}
| PAS COMMA expr {$$=$1;$1->addSibling($3);}
;

expr
: IDENTIFIER {
    $$=find_id($1);
}
| INTEGER {
    $$ = $1;
}
| HEX_INTEGER {
    $$ = $1;
}
| CHAR {
    $$ = $1;
}
| STRING {
    $$ = $1;
}
| IDENTIFIER LEFTBR PAS RIGHTBR{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_FUNC_USE;
    node->var_name=$1->var_name;
    node->addChild(find_id($1));
    node->addChild($3);
    $$=node;
}
| IDENTIFIER LEFTBR RIGHTBR{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_FUNC_USE;
    node->var_name=$1->var_name;
    node->addChild(find_id($1));
    $$=node;
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
| LVAL LOP_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    if($1->is_const)cout<<"const Variable can't be assigned!"<<endl;
	node->optype = OP_LOP_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVAL ADD_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_ADD_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVAL SUB_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_SUB_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVAL MUL_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_MUL_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVAL DIV_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_DIV_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVAL SUR_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_SUR_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVAL LS_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LS_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVAL RS_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_RS_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVAL OR_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_OR_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVAL AND_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_AND_ASS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVAL XOR_ASS expr {
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
| LOG_NOT expr {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_LOG_NOT;
    node->addChild($2);
    $$ = node;
}
| BIT_NOT expr {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_BIT_NOT;
    node->addChild($2);
    $$ = node;
}
| BIT_AND expr %prec ADDR {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_ADDR;
    node->addChild($2);
    $$ = node;
}
| INCR expr {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_INCR;
    node->addChild($2);
    $$ = node;
}
| DECR expr {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_DECR;
    node->addChild($2);
    $$ = node;
}
| expr INCR %prec BACK_INCR {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_BACK_INCR;
    node->addChild($1);
    $$ = node;
}
| expr DECR %prec BACK_DECR {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_BACK_DECR;
    node->addChild($1);
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
| T_VOID {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_VOID;}
;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}