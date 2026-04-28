/*
LeetCode 494. 目标和（Medium）
手撕思路：给每个数加正负号。设正数和 P，负数和 N，总和 S，P-N=target，P+N=S，所以 P=(S+target)/2，转成 0/1 背包计数。
复杂度：时间 O(n*target)，空间 O(target)。
*/
#include <vector>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (abs(target) > sum || (sum + target) % 2) return 0;
        int bag = (sum + target) / 2;
        vector<int> dp(bag + 1, 0);
        dp[0] = 1;
        for (int x : nums) {
            for (int j = bag; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }
        return dp[bag];
    }
};
