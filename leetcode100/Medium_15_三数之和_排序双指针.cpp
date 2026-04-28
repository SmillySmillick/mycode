/*
LeetCode 15. 三数之和（Medium）

手撕思路：
1. 先排序，方便双指针和去重。
2. 枚举第一个数 nums[i]，剩下两个数在 i+1..n-1 里用双指针找。
3. sum 太小就 left++，sum 太大就 right--。
4. 找到一组后，要跳过 left 和 right 的重复值，避免答案重复。
5. nums[i] 也要去重；排序后 nums[i] > 0 可以提前结束。

复杂度：时间 O(n^2)，空间 O(1) 不计答案。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};
