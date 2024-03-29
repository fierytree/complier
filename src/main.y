%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    extern int br_count;
    extern ofstream fout;
    extern vector<pair<int,int> > br_list;
    int yylex();
    int yyerror( char const * );
    map<pair<string,int>,TreeNode*> id_list;
    map<string,TreeNode*>struct_list;
    void add_id(TreeNode* t){
        fout<<t->nodeID<<" "<<t->var_name<<endl;
        auto x=make_pair(t->var_name,t->scope.first);
        if(id_list.find(x)==id_list.end())id_list[x]=t;
        else cerr<<"in line"<<lineno<<", Variable "<<t->var_name<<" repeated definition"<<endl,exit(0);
    }
    TreeNode* find_id(TreeNode* t){
        auto s=make_pair(-1,-1);
        Type* tp=nullptr;
        auto y=make_pair(t->var_name,0);
        //for(auto x:id_list)fout<<x.first.first<<" "<<x.first.second<<endl;
        if(id_list.find(y)!=id_list.end())s=make_pair(0,0),tp=id_list[y]->type;
        for(auto x:br_list){
            auto y=make_pair(t->var_name,x.first);
            if(id_list.find(y)!=id_list.end())s=x,tp=id_list[y]->type;
        }
        if(s.first==-1&&t->type!=nullptr&&t->type->type==COMPOSE_FUNCTION)return t;
        if(s.first==-1){
            auto y=make_pair(t->var_name,br_count+1);
            if(id_list.find(y)!=id_list.end()){
                t->scope=id_list[y]->scope;
                t->type=id_list[y]->type;
                cerr<<"in line"<<id_list[y]->lineno;
                cerr<<", warning，use bracket when write a statement."<<endl;
                return t;
            }
            else cerr<<"in line"<<lineno<<", Variable "<<t->var_name<<" undefinied"<<endl,exit(0);
        }
        t->scope=s;t->type=tp;
        fout<<"577 "<<t->type->getTypeInfo()<<" "<<t->nodeID<<endl;
        return t;
    }
    inline bool rd(TreeNode* t1,TreeNode* t2){
        return t1->nodeType==NODE_CONST&&t2->nodeType==NODE_CONST;
    }
    inline bool rd(TreeNode* t){
        return t->nodeType==NODE_CONST;
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
%token ADDR STAR
%token LEFTBR RIGHTBR
%token LOG_NOT BIT_NOT
%token UMINUS UADD
%token INCR DECR
%token LBRACE RBRACE
%token ST_MB STP_MB
%token M_LBR M_RBR
%token BACK_INCR BACK_DECR

%token SEMICOLON
%token COMMA
%token IDENTIFIER INTEGER CHAR BOOL STRING HEX_INTEGER
%token IF WHILE FOR RETURN CONST ELSE BREAK CONTINUE STRUCT

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
%right ADDR STAR
%right LEFTBR RIGHTBR
%right LOG_NOT BIT_NOT
%right UMINUS UADD
%right INCR DECR
%left ST_MB STP_MB
%left M_LBR M_RBR
%left BACK_INCR BACK_DECR

%precedence IF
%precedence ELSE


%%

program
: units {root = new TreeNode(0, NODE_PROG); root->addChild($1);root->type=TYPE_VOID;};
;

program_unit:function
| declaration SEMICOLON{$$=$1;}
| struct SEMICOLON{$$=$1;}
;

units:program_unit
| units program_unit {$$=$1;$$->addSibling($2);}
;

struct_items: declaration SEMICOLON{
    TreeNode* node=new TreeNode(lineno,NODE_PARA);
    node->addChild($1);
    node->type=new Type(COMPOSE_UNION);
    
    TreeNode* tmp=$1->child->siblings;
    while(tmp!=nullptr){
        Type* mb=new Type($1->child->type->type);
        if(tmp->child==nullptr)mb->name=tmp->var_name;
        else mb->name=tmp->child->var_name;
        tmp=tmp->siblings;
        node->type->childType.push_back(mb);
    }
    $$=node;
}
| struct_items declaration SEMICOLON{
    $$=$1;$$->addChild($2);
    TreeNode* tmp=$2->child->siblings;
    while(tmp!=nullptr){
        Type* mb=new Type($2->child->type->type);
        if(tmp->child==nullptr)mb->name=tmp->var_name;
        else mb->name=tmp->child->var_name;
        tmp=tmp->siblings;
        $$->type->childType.push_back(mb);
    }
}
;

struct: STRUCT IDENTIFIER LBRACE struct_items RBRACE{
    TreeNode* node=new TreeNode($2->lineno,NODE_STRUCT);
    struct_list[$2->var_name]=node;
    node->addChild($2);
    node->addChild($4);
    node->type=new Type(COMPOSE_STRUCT);
    node->type->name=$2->var_name;
    node->type->paramType=$4->type;
    $$=node;
}

function
: T IDENTIFIER for_LEFTBR PARMS for_RIGHTBR block{
    TreeNode* node = new TreeNode($1->lineno, NODE_FUNC);
    
    $2->type=new Type(COMPOSE_FUNCTION);
    $2->type->retType=$1->type;
    $2->type->paramType=$4->type;
    add_id($2);

    $6->pa_func=node;
    $2->pa_func=node;
    node->stack_size=0;
    node->reg_count=0;
    node->var_name=$2->var_name;
    node->type=$2->type->retType;
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

    node->type=new Type(COMPOSE_UNION);
    node->type->addChild($1->type);
    $2->type=$1->type;
    add_id($2);
    node->addChild($1);
    node->addChild($2);
    $$=node;
}
| PARMS COMMA T IDENTIFIER{
    $$=$1;
    add_id($4);
    $4->type=$3->type;
    $1->addChild($3);
    $1->addChild($4);
    $1->type->addChild($3->type);
}
| {$$ = new TreeNode(lineno, NODE_PARA);$$->type=new Type(COMPOSE_UNION);}
;

block_item
: statement {$$=$1;}
| declaration SEMICOLON {$$ = $1;}
;

block_items
: {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
| block_items block_item {
    if($1->nodeType==NODE_STMT&&$1->stype == STMT_SKIP)$$=$2;
    else{
        $$=$1; $$->addSibling($2);
    }   
}
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
    $5->pa_loop=node;
    $$=node;
}
| FOR for_LEFTBR for_expr SEMICOLON for_expr SEMICOLON for_expr for_RIGHTBR statement{
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    node->stype=STMT_FOR;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    node->addChild($9);
    $9->pa_loop=node;
    $$=node;
    for(auto x:id_list){
        if(x.first.second==br_count+1){
            ++br_count;
            fout<<"omit bracket"<<endl;break;
        }
    }
}
| IF LEFTBR expr RIGHTBR statement{
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($3);
    node->addChild($5);
    $$=node;
}
| IF LEFTBR expr RIGHTBR statement ELSE statement{
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    node->stype=STMT_IF;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    $$=node;
}
| RETURN expr SEMICOLON{
    TreeNode* node = new TreeNode($2->lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    node->addChild($2);
    $$=node;
}
| RETURN SEMICOLON{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype=STMT_RETURN;
    $$=node;
}
| BREAK SEMICOLON{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype=STMT_BREAK;
    $$=node;
}
| CONTINUE SEMICOLON{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype=STMT_CONTINUE;
    $$=node;
}
| expr SEMICOLON{
    $$=$1;
}
;

for_expr
: declaration
| expr
| {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;$$->place="$1";}
;

for_LEFTBR:LEFTBR{$$=$1;br_list.push_back(make_pair(br_count+1,lineno));};
for_RIGHTBR:RIGHTBR{$$=$1;br_list.pop_back();};

declaration
: T IDENTIFIERS {
    fout<<"444 "<<endl;
    TreeNode* node = new TreeNode($2->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    TreeNode* tmp=$2;
    while(tmp!=nullptr){
        tmp->type=$1->type;
        if(tmp->child!=nullptr)tmp->child->type=$1->type;
        tmp=tmp->siblings;
    }
    $$ = node;   
}
| T ARRAY {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $2->type->addret($1->type);
    $$ = node;
}
| CONST T_INT IDENTIFIER LOP_ASS CONST_EXP{
    TreeNode* node1 = new TreeNode($3->lineno, NODE_TYPE);node1->type=TYPE_INT;    
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    TreeNode* node2 = new TreeNode($3->lineno, NODE_EXPR);
    node2->optype=OP_LOP_ASS;
    $3->is_const=1;
    $3->type=TYPE_INT;
    add_id($3);
    node->stype = STMT_DECL;
    node->addChild(node1);
    node->addChild(node2);
    node2->addChild($3);
    node2->addChild($5);
    $$ = node;
}
| CONST T_CHAR IDENTIFIER LOP_ASS CHAR{
    TreeNode* node1 = new TreeNode($3->lineno, NODE_TYPE);node1->type=TYPE_CHAR;    
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    TreeNode* node2 = new TreeNode($3->lineno, NODE_EXPR);
    node2->optype=OP_LOP_ASS;
    $3->is_const=1;
    $3->type=TYPE_CHAR;
    add_id($3);
    node->stype = STMT_DECL;
    node->addChild(node1);
    node->addChild(node2);
    node2->addChild($3);
    node2->addChild($5);
    $$ = node;
}
| CONST T_BOOL IDENTIFIER LOP_ASS INTEGER{
    TreeNode* node1 = new TreeNode($3->lineno, NODE_TYPE);node1->type=TYPE_BOOL;    
    TreeNode* node = new TreeNode($3->lineno, NODE_STMT);
    TreeNode* node2 = new TreeNode($3->lineno, NODE_EXPR);
    node2->optype=OP_LOP_ASS;
    $3->is_const=1;
    $3->type=TYPE_BOOL;
    add_id($3);
    node->stype = STMT_DECL;
    node->addChild(node1);
    node->addChild(node2);
    node2->addChild($3);
    node2->addChild($5);
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
    node->int_val=$1->int_val+$3->int_val;
    $$ = node;
}
| CONST_EXP SUB CONST_EXP{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_SUB;
    node->addChild($1);
    node->addChild($3);
    node->int_val=$1->int_val-$3->int_val;
    $$ = node;
}
| CONST_EXP MUL CONST_EXP{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_MUL;
    node->addChild($1);
    node->addChild($3);
    node->int_val=$1->int_val*$3->int_val;
    $$ = node;
}
| CONST_EXP DIV CONST_EXP{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_DIV;
    node->addChild($1);
    node->addChild($3);
    node->int_val=$1->int_val/$3->int_val;
    $$ = node;
}
| CONST_EXP LSHIFT CONST_EXP{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LSHIFT;
    node->addChild($1);
    node->addChild($3);
    node->int_val=$1->int_val<<$3->int_val;
    $$ = node;
}
| SUB CONST_EXP %prec UMINUS{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_UMINUS;
    node->addChild($2);
    node->int_val=-$2->int_val;
    $$ = node;
}
| LEFTBR CONST_EXP RIGHTBR{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_BR;
    node->addChild($2);
    node->int_val=$2->int_val;
    $$ = node;
}
;

ARRAY
: IDENTIFIER M_LBR CONST_EXP M_RBR{
    TreeNode* node = new TreeNode($1->lineno, NODE_ARRAY);

    $1->type=new Type(COMPOSE_ARRAY);
    $1->type->size=$3->int_val;
    $1->array_dim=1;
    
    add_id($1);
    node->array_dim=1;
    node->addChild($1);
    node->addChild($3);
    node->type=$1->type;
    $$=node;
}
| ARRAY M_LBR CONST_EXP M_RBR{
    $1->array_dim+=1;
    $$=$1;
    $1->addChild($3);
    Type* at=new Type(COMPOSE_ARRAY);
    at->size=$3->int_val;
    $1->type->addret(at);
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
    $1->addChild($3);
}

struct_mem: IDENTIFIER ST_MB IDENTIFIER{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype=OP_ST_MB;
    node->addChild(find_id($1));
    node->addChild($3);
    $$=node;
}
| IDENTIFIER STP_MB IDENTIFIER{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype=OP_STP_MB;
    node->addChild(find_id($1));
    node->addChild($3);
    $$=node;
}
;

LVAL: ARRAY2 
| IDENTIFIER {$$=find_id($1);}
| struct_mem
;

decl_item
: IDENTIFIER {$$=$1;add_id($1);fout<<"444 "<<endl;}
| IDENTIFIER LOP_ASS expr{
    TreeNode* node=new TreeNode($1->lineno,NODE_EXPR);
    node->addChild($1);
    node->addChild($3);
    node->optype=OP_LOP_ASS;
    add_id($1);
    $$=node;
}
;

IDENTIFIERS: decl_item
| IDENTIFIERS COMMA decl_item{
    $$=$1;
    $$->addSibling($3);
}
;

PAS
: {$$ = new TreeNode(lineno, NODE_PARA);$$->type=new Type(COMPOSE_UNION);}
| PAS COMMA expr {$$=$1;$1->addChild($3);}
| expr {
    TreeNode* node=new TreeNode(lineno, NODE_PARA);
    node->type=new Type(COMPOSE_UNION);
    node->addChild($1);
    $$=node;
}
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
| ARRAY2{
    $$ = $1;
}
| struct_mem{
    $$ = $1;
}
| IDENTIFIER LEFTBR PAS RIGHTBR{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype=STMT_FUNC_USE;
    node->var_name=$1->var_name;
    $1->type=new Type(COMPOSE_FUNCTION);
    node->addChild(find_id($1));
    node->addChild($3);
    $$=node;
}
| expr ADD expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_ADD;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()+$3->val();
}
| expr SUB expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_SUB;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()-$3->val();
}
| expr MUL expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_MUL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()*$3->val();
}
| expr DIV expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_DIV;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()/$3->val();
}
| expr SUR expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_SUR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()%$3->val();
}
| expr LSHIFT expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LSHIFT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()<<$3->val();
}
| expr RSHIFT expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_RSHIFT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()>>$3->val();
}
| expr BIT_AND expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_BIT_AND;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()&$3->val();
}
| expr BIT_OR expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_BIT_OR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()|$3->val();
}
| expr BIT_XOR expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_BIT_XOR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()^$3->val();
}
| expr EQ expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_EQ;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()==$3->val();
}
| expr UEQ expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_UEQ;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()!=$3->val();
}
| expr LT expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()<$3->val();
}
| expr GT expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_GT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()>$3->val();
}
| expr LE expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LE;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()<=$3->val();
}
| expr GE expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_GE;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()>=$3->val();
}
| expr LOG_AND expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LOG_AND;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()&&$3->val();
}
| expr LOG_OR expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
	node->optype = OP_LOG_OR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    if(node->rd2())node->int_val=$1->val()||$3->val();
}
| LVAL LOP_ASS expr {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    if($1->is_const)fout<<"const Variable can't be assigned!"<<endl;
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
    if(node->rd())node->int_val=-$2->val();
}
| ADD expr %prec UADD {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_UADD;
    node->addChild($2);
    $$ = node;
    if(node->rd())node->int_val=$2->val();
}
| LOG_NOT expr {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_LOG_NOT;
    node->addChild($2);
    $$ = node;
    if(node->rd())node->int_val=!$2->val();
}
| BIT_NOT expr {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_BIT_NOT;
    node->addChild($2);
    $$ = node;
    if(node->rd())node->int_val=~$2->val();
}
| BIT_AND expr %prec ADDR {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_ADDR;
    node->addChild($2);
    $$ = node;
}
| MUL expr %prec STAR {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
	node->optype = OP_STAR;
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
    if(node->rd())node->int_val=$2->val();
}
;

T: T1
| T1 MUL %prec STAR{
    TreeNode* node = new TreeNode(lineno, NODE_TYPE);
    node->type=new Type(COMPOSE_POINTER);
    node->type->retType=$1->type;
    $$=node;
}
;

T1: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
| T_STRING {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_STRING;}
| T_VOID {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_VOID;}
| STRUCT IDENTIFIER{
    if(struct_list.find($2->var_name)==struct_list.end()){
        cerr<<"in line"<<lineno<<endl;
        cerr<<"undefined struct name "<<$2->var_name<<endl;
        exit(0);
    }
    $$ = new TreeNode(lineno, NODE_TYPE); 
    $$->type = struct_list[$2->var_name]->type;
    fout<<"555 "<<$$->type->getTypeInfo()<<endl;
}
;

%%

int yyerror(char const* message)
{
  fout << message << " at line " << lineno << endl;
  return -1;
}