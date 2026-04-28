/*
LeetCode 198. 打家劫舍（Medium）
手撕思路：每间房只有偷或不偷。偷当前 = prev2 + nums[i]，不偷当前 = prev1，滚动更新。
复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for (int x : nums) {
            int cur = max(prev1, prev2 + x);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
