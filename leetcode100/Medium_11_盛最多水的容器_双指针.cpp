/*
LeetCode 11. 盛最多水的容器（Medium）

手撕思路：
1. 面积 = min(height[l], height[r]) * 宽度。
2. 双指针从两端开始，宽度一定会越来越小。
3. 如果想让面积变大，只能尝试提高短板；移动长板没有意义，因为短板不变且宽度变小。
4. 所以每次移动较矮的一侧。

复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};
