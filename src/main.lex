%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
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

"(" return LEFTBR;
")" return RIGHTBR;
"=" return LOP_ASSIGN;

";" return  SEMICOLON;
"{" return LBRACE;
"}" return RBRACE;


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

{IDENTIFIER} {
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    yylval = node;
    return IDENTIFIER;
}

{WHILTESPACE} /* do nothing */

{EOL} lineno++;

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%