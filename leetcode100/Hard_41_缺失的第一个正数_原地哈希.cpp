/*
LeetCode 41. 缺失的第一个正数（Hard）

手撕思路：
1. 答案一定在 [1, n+1] 之间，n 是数组长度。
2. 如果一个数 x 满足 1 <= x <= n，就应该放到下标 x-1 的位置。
3. 原地不断交换，让 nums[i] 尽量回到它该在的位置。
4. 再扫一遍，第一个 nums[i] != i+1 的位置，答案就是 i+1。
5. 如果 1..n 都在正确位置，答案就是 n+1。

复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // nums[i] 应该去 nums[i]-1 的位置。
            // 如果目标位置已经是同一个数，不能再换，否则会死循环。
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};
