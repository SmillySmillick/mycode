/*
LeetCode 75. 颜色分类（Medium）
手撕思路：荷兰国旗。left 左边全是 0，right 右边全是 2，i 扫描未知区。遇 0 换到左边，遇 2 换到右边，遇 1 继续。
复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, i = 0, right = nums.size() - 1;
        while (i <= right) {
            if (nums[i] == 0) swap(nums[left++], nums[i++]);
            else if (nums[i] == 2) swap(nums[i], nums[right--]);
            else i++;
        }
    }
};
