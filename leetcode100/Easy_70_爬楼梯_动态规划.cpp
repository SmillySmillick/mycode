/*
由于一步和两步都是可选的,状态转移就是dp[i]=dp[i-1]+dp[i-2]
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int climbStairs(int n) {
            if (n <= 2) return n;
    
            int prev2 = 1; // f(n-2)
            int prev1 = 2; // f(n-1)
            int cur = 0;
    
            for (int i = 3; i <= n; i++) {
                cur   = prev1 + prev2;
                prev2 = prev1;
                prev1 = cur;//后置一位
            }
    
            return cur;
        }
    };
    