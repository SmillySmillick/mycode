/*
LeetCode 42. 接雨水（Hard）

手撕思路：
1. 每个位置能接的水 = min(左侧最高, 右侧最高) - 当前高度。
2. 双指针从两端向中间走，维护 leftMax 和 rightMax。
3. 如果 height[left] < height[right]，左边位置的上限由 leftMax 决定，因为右侧至少有 height[right] 兜底。
4. 反之处理右边。每次只结算较矮侧。

复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};
