/*
LeetCode 33. 搜索旋转排序数组（Medium）
手撕思路：二分时总有一半是有序的。判断 target 是否落在有序半边里，落在里面就缩到那边，否则去另一边。
复杂度：时间 O(log n)，空间 O(1)。
*/
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
