/*
LeetCode 238. 除自身以外数组的乘积（Medium）
手撕思路：答案 = 左边所有数乘积 * 右边所有数乘积。先正向把左乘积写入 ans，再反向乘上右乘积。
复杂度：时间 O(n)，额外空间 O(1)。
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int left = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};
