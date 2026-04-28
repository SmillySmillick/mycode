/*
LeetCode 279. 完全平方数（Medium）
手撕思路：完全背包。dp[i] 表示组成 i 的最少平方数个数，枚举平方数 square，更新 dp[i] = min(dp[i], dp[i-square]+1)。
复杂度：时间 O(n*sqrt(n))，空间 O(n)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int x = 1; x * x <= i; x++) {
                dp[i] = min(dp[i], dp[i - x * x] + 1);
            }
        }
        return dp[n];
    }
};
