#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 6000
#define M 1000
#define L 50
int main(){
    int n;
    char c[M][L];
    char w[M],b[M],d[M];
    char t[M];
    int p[M];
    scanf("%d",&n);
    int count=0,cur=0,i=0,flag=0;
    scanf("%s",w);
    for (;i<n;)
    {   
        if (w[0]=='1'){
            flag=0;
           scanf("%s",b);
           for(int i=0;i<count;i++)
           {
            if(strcmp(b,c[i])==0){
             cur=i;
             goto step;
            }
            }
            strcpy(c[count],b);
            p[count]=0;
            cur=count;
            count++;
            step:
            scanf("%s",d);
            while(d[0]!=49||d[0]!=50||d[0]!=51){
                if(d[0]=='$'){
                    for(int i=0;i<count;i++){
                        if(strcmp(d,c[i])==0){
                           p[cur]+=p[i];
                        }
                    }
                }else{
                 p[cur]=strlen(d);
                }
            }
            i++;
            strcpy(w,d);
            flag=1;
           } else if(w[0]=='3'){
            scanf("%s",b);
          for(int j=0;j<count;j++){
            if(strcmp(b,c[i])==0){
                printf("%d\n",p[i]);
            }
            i++;
          }
        }
         if(flag!=1){
            scanf("%s",w);
         }
         flag=0;
    }
    

}