/*
LeetCode 96. 不同的二叉搜索树（Medium）
手撕思路：选 i 当根，左边有 i-1 个数，右边有 n-i 个数，方案数相乘；枚举根节点求和。
复杂度：时间 O(n^2)，空间 O(n)。
*/
#include <vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int nodes = 2; nodes <= n; nodes++) {
            for (int root = 1; root <= nodes; root++) {
                dp[nodes] += dp[root - 1] * dp[nodes - root];
            }
        }
        return dp[n];
    }
};
