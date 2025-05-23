//csp35第二题,简单模拟
#include<bits/stdc++.h>
using namespace std;
int main(){
    char ori[103];

    std::cin.getline(ori,103);

    int len=strlen(ori)-2;
    int n;

    cin>>n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    char s[n][5];
    char c[128];
    for(int i=0;i<128;i++){
        c[i]=i;
    }
    for(int i=0;i<n;i++){
        std::cin.getline(s[i],5);
        c[s[i][1]]=s[i][2];
    }
    int m,x;
    cin>>m;
    for(int i=0;i<m;i++){
       cin>>x;
       char cur[103];
       char cuc;
       strcpy(cur,ori);
       for(int j=0;j<x;j++){
          for(int k=1;k<=len;k++){
            cuc=cur[k];
            cur[k]=c[cuc];
          }
    }
    cout<<cur<<endl;
}
}
