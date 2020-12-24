%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
int br_count=0;
typedef pair<int,int> br;
br global=make_pair(0,1);
vector<br> br_list;
%}
BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

INTEGER [0-9]+
HEX_INTERGER 0x[A-Fa-f0-9]+|0X[A-Fa-f0-9]+

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
"const" return CONST;
"else" return ELSE;

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
    br_list.push_back(make_pair(++br_count,lineno));
    return LBRACE;
}
"}" {
    br_list.pop_back();
    return RBRACE;
}

"[" return M_LBR;
"]" return M_RBR;

"," return COMMA;

{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    if(yytext[0]!='0')node->int_val = atoi(yytext);
    else{
        int tmp=0;
        string x=yytext;
        for(unsigned i=1;i<x.size();i++){
            tmp=tmp*8+x[i]-'0';
        }
        node->int_val=tmp;
    }
    yylval = node;
    return INTEGER;
}

{HEX_INTERGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    int tmp=0;
    string x=yytext;
    for(unsigned i=2;i<x.size();i++){
        if(x[i]>='0'&&x[i]<='9')tmp=tmp*16+x[i]-'0';
        else if(x[i]>='A'&&x[i]<='F')tmp=tmp*16+x[i]-'A'+10;
        else if(x[i]>='a'&&x[i]<='f')tmp=tmp*16+x[i]-'a'+10;
        else cout<<"wrong hex integer!"<<endl;
    }
    node->int_val=tmp;
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
    br sc=br_list.empty()?global:br_list.back();
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    node->scope=sc;
    yylval = node;
    return IDENTIFIER;
}

{WHILTESPACE} /* do nothing */

{EOL} lineno++;

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%