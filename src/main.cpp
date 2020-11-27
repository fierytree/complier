#include "common.h"
#include <fstream>

extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();
extern map<pair<string,int>,TreeNode*> id_list2;
int TreeNode::node_num=0;
vector<int> TreeNode::visited=vector<int>();
using namespace std;
int main(int argc, char *argv[])
{
    TreeNode* print=new TreeNode(0,NODE_FUNC);
    print->var_name="printf";
    TreeNode* scan=new TreeNode(0,NODE_FUNC);
    print->var_name="scanf";
    id_list2[make_pair("printf",0)]=print;
    id_list2[make_pair("scanf",0)]=scan;
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
        root->visited.clear();
        root->printAST();
    }
    return 0;
}