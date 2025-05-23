#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int highestBit = 1;
    while (highestBit <= n) {
        highestBit <<= 1;
    }
    highestBit >>= 1;
    while (highestBit > 0) {
        cout << ((n & highestBit) ? 1 : 0);
        highestBit >>= 1;
    }
    cout << endl;
}
