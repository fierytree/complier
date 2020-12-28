int main(){
    int c[10][10];
    int *point=2+c;
    int *p2=c[3]+1;
    for(int i=0;i<100;i++)c[i/10][i%10]=i;
    for(int i=0;i<10;i=i+1){
        p2++;
        point+=2;
        printf("%d\n",*point);
        printf("%d\n",*p2);
    }
    return 0;
}