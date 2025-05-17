#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin >> n;
cout << bitset<8*sizeof(n)>(n) << endl;
}
