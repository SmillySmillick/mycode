/*
LeetCode 221. 最大正方形（Medium）
手撕思路：dp[i][j] 表示以当前位置为右下角的最大正方形边长。若当前位置是 1，边长取左、上、左上三者最小值 + 1。
复杂度：时间 O(mn)，空间 O(n)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int ans = 0, prev = 0;
        for (int i = 1; i <= m; i++) {
            prev = 0;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min({dp[j], dp[j - 1], prev}) + 1;
                    ans = max(ans, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return ans * ans;
    }
};
