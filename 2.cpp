#include<stdio.h>
#define M 100
int main(){
    int n,m;
    int a[M];
    double l[M];
    int ed=0;
    scanf("%d %d",&n,&m);
    int r1=0,r2=m;
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
        l[i]=(double)a[i]/(double)(i+1);
    }
while(n!=0){
    r1=0;
    for(int j=0;j<(r2+1);j++){
        if(l[j]>l[r1]){
            r1=j;
        }
    }
    r2=0;
    int s[M];
    for(int k=0;k<(r1+1);k++){
       s[k]=((int)(n/(k+1)))*a[k];
       //printf("%d\n",s[k]);
    }
    
    for(int i=0;i<(r1+1);i++){
       if(s[i]>s[r2]){
        r2=i;
       }else if(s[i]==s[r2]&&n%(i+1)>n%(r2+1)){
        r2=i;
       }
    }
    ed+=s[r2];
    //printf("%d\n",r2);
    n=n%(r2+1);
    if(n<r2){
        r2=n;
    }
    }
    printf("%d",ed);
}