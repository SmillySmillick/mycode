/*
LeetCode 62. 不同路径（Medium）
手撕思路：只能向右或向下，dp[j] 表示当前行到第 j 列的路径数，状态来自上方 dp[j] 和左边 dp[j-1]。
复杂度：时间 O(mn)，空间 O(n)。
*/
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
