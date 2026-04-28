/*
LeetCode 34. 在排序数组中查找元素的第一个和最后一个位置（Medium）
手撕思路：分别二分找第一个 >= target 的位置和第一个 > target 的位置，右边界就是后者减一。
复杂度：时间 O(log n)，空间 O(1)。
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lowerBound(nums, target);
        int right = upperBound(nums, target) - 1;
        if (left < nums.size() && nums[left] == target) return {left, right};
        return {-1, -1};
    }
private:
    int lowerBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    int upperBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
