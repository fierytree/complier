#include "common.h"
#include <fstream>

extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();
int TreeNode::node_num=0;
using namespace std;
int main(int argc, char *argv[])
{
    cout<<setiosflags(ios::left);
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin != nullptr)
        {
            yyin = fin;
        }
        else
        {
            cerr << "failed to open file: " << argv[1] << endl;
        }
    }
    cout<<"file has been opened"<<endl;
    yyparse();
    if(root != NULL) {
        root->printAST();
    }
    return 0;
}