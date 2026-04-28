/*
LeetCode 53. 最大子数组和（Medium）
手撕思路：Kadane。当前位置要么接在前面的子数组后面，要么自己重新开始。cur 表示以当前元素结尾的最大和。
复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};
