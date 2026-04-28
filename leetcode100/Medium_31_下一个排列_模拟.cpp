/*
LeetCode 31. 下一个排列（Medium）
手撕思路：从右往左找第一个下降点 i，使 nums[i] < nums[i+1]；再从右找第一个比 nums[i] 大的数交换；最后反转 i 后面的降序尾巴。
复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
