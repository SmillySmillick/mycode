#include<stdio.h>
int fun(int x,int b,int c);
int main(){
    int b,c,l,r;
    scanf("%d %d %d %d",&b,&c,&l,&r);
    int cur=0;
    if(l%2!=0){
        cur=l+1;
    }else{
        cur=l;
    }
    long s=0;
    for(;cur<=r;cur+=2){
        //printf("%d ",cur);
       s+=fun(cur,b,c);
    }
    s=s*2;
    printf("%ld",s);
}
int fun(int x,int b,int c){
    int tem1,tem2,tem3;
    tem1=x*x;
    tem2=x*b;
    tem3=tem1+tem2+c;
    //printf("%d\n",tem3);
    return tem3;
}