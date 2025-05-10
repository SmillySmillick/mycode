#include<stdio.h>
#define M 10000
int gcd(int a,int b){
    if (b==0){
        return a;
    }
    int c;
    if(a<b){
       c=a;
       a=b;
       b=c;
    }
    gcd(b,a%b);
};
int main(){
    int n;
    //printf("%d",gcd(8,25));
    scanf("%d",&n);
    int a[M];
    int d=1;
    int s=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(j==i){
              d=a[i];
              s+=(i+1)*(i+1)*d;
              //printf("m %d\n",(i+1)*(i+1)*d);
              if(s>=998244353)
              {s=s%998244353;}
            }else{
                d=a[i];
                for(int k=i;k<=j;k++){
                d=gcd(d,a[k]);
            }
            s+=(i+1)*(j+1)*d;
            //printf("%d %d\n",d,(i+1)*(j+1)*d);
            if(s>=998244353)
             {s=s%998244353;}
            }
            
        }
    }
   printf("%d",s);
}