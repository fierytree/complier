%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
int br_count=0;
typedef pair<int,int> br;
br global=make_pair(0,1);
stack<br> br_list;
map<pair<string,int>,TreeNode*> id_list;
vector<br> br_list2;
%}
BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

INTEGER [0-9]+

CHAR \'.?\'
STRING \".+\"

IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
%%

{BLOCKCOMMENT}  /* do nothing */
{LINECOMMENT}  /* do nothing */


"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;
"void" return T_VOID;

"if" return IF;
"while" return WHILE;
"for" return FOR;
"return" {TreeNode* node = new TreeNode(lineno, NODE_CONST);yylval=node;return RETURN;}

"(" return LEFTBR;
")" return RIGHTBR;
"++" return INCR;
"--" return DECR;
"*" return MUL;
"/" return DIV;
"%" return SUR;
"+" return ADD;
"-" return SUB;
"<<" return LSHIFT;
">>" return RSHIFT;
"<=" return LE;
">=" return GE;
"<" return LT;
">" return GT;
"==" return EQ;
"!=" return UEQ;
"&&" return LOG_AND;
"||" return LOG_OR;
"&" return BIT_AND;
"|" return BIT_OR;
"^" return BIT_XOR;

"=" return LOP_ASS;
"+=" return ADD_ASS;
"-=" return SUB_ASS;
"*=" return MUL_ASS;
"/=" return DIV_ASS;
"%=" return SUR_ASS;
"<<=" return LS_ASS;
">>=" return RS_ASS;
"&=" return AND_ASS;
"|=" return OR_ASS;
"^=" return XOR_ASS;
"!" return LOG_NOT;
"~" return BIT_NOT;

";" return  SEMICOLON;
"{" {
    br_list.push(make_pair(++br_count,lineno));
    br_list2.push_back(make_pair(br_count,lineno));
    return LBRACE;
}
"}" {
    br_list.pop();
    return RBRACE;
}


"," return COMMA;

{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = atoi(yytext);
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->ch_val = yytext[1];
    yylval = node;
    return CHAR;
}

{STRING} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_STRING;
    string tmp = yytext;
    node->str_val=tmp.substr(1,tmp.size()-2);
    yylval = node;
    return STRING;
}

{IDENTIFIER} {
    br sc=br_list.empty()?global:br_list.top();
    auto x=make_pair(yytext,sc.first);
    if(id_list.find(x)==id_list.end()){
        TreeNode* node = new TreeNode(lineno, NODE_VAR);
        id_list[x]=node;
        node->var_name = string(yytext);
        node->scope=sc;
        yylval = node;
    }
    else{
        TreeNode* node = new TreeNode(lineno, NODE_VAR);
        node->var_name = string(yytext);
        node->scope=id_list[x]->scope;
        yylval = node;
    }
    return IDENTIFIER;
}

{WHILTESPACE} /* do nothing */

{EOL} lineno++;

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%