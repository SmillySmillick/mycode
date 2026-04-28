/*
LeetCode 416. 分割等和子集（Medium）
手撕思路：总和为奇数直接 false；否则问题变成能否选一些数凑出 sum/2，是 0/1 背包可达性。
复杂度：时间 O(n*target)，空间 O(target)。
*/
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int x : nums) {
            for (int j = target; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
        }
        return dp[target];
    }
};
