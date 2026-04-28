/*
LeetCode 283. 移动零（Easy）

手撕思路：
1. 要保持非零元素相对顺序，所以不能随便交换到末尾。
2. 用 slow 表示下一个非零元素应该放的位置。
3. fast 从左到右扫描，遇到非零就写到 nums[slow]，然后 slow++。
4. 扫完后，slow 后面的所有位置补 0。

复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
