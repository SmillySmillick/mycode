//csp35«©µΩÃ‚
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char x[21];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>x;
        int len=strlen(x);
        int t[128]={0};
        int f1=0,f2=0,f3=0,f4=1;
        for(int j=0;j<len;j++){
            t[x[j]]++;
        }
         for(int k=48;k<=57;k++){
            if(t[k]>=1){
                f1=1;
            }
            if(t[k]>=2){
                f4=0;
            }
            }
            for(int k=97;k<=122;k++){
            if(t[k]>=1){
                f2=1;
            }
             if(t[k]>=2){
                f4=0;
            }}
            for(int k=65;k<=90;k++){
            if(t[k]>=1){
                f2=1;
            }
             if(t[k]>=2){
                f4=0;
            }}
            if(t['#']>=1||t['*']>=1){
                f3=1;
            }
            if(t['#']>=2||t['*']>=2){
                f4=0;
            }
            printf("%d %d %d %d\n",f1,f2,f3,f4);
            if(f1&&f2&&f3&&f4){
                printf("2\n");
            }
            else if(f1&&f2&&f3){
                printf("1\n");
            }else {
                printf("0\n");
            }
                
        }
    }


