//CSP34«©µΩÃ‚   
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,p,q;
    scanf("%d %d %d %d",&n,&m,&p,&q);
    int a[1000];
    for(int i=0;i<n*m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("%d",a[i*q+j]);
            if(j!=q-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    
}
