/*
LeetCode 64. 最小路径和（Medium）
手撕思路：只能向右或向下，dp[j] 表示走到当前行第 j 列的最小路径和，来自上方 dp[j] 或左边 dp[j-1]。
复杂度：时间 O(mn)，空间 O(n)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j];
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};
