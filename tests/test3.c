int a=0;
int f(int x,int y){
    x=2;
    return 1;
}
void main(){
    int s=f(1,2);
    printf("result is: %d\n", s);
}