const int a=1<<12+1;
const char c='s';
int e[10][10];
void main(){
    int c=a+0xFF;
    int d=a+011;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            e[i][j]=1;
        }
    }
    return ;
}