/*
LeetCode 55. 跳跃游戏（Medium）

手撕思路：
1. 不关心具体怎么跳，只关心当前最远能到哪里。
2. maxReach 表示遍历到当前位置前，能覆盖到的最远下标。
3. 如果 i > maxReach，说明当前位置都到不了，直接 false。
4. 否则用 i + nums[i] 更新最远覆盖范围。

复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= nums.size() - 1) return true;
        }
        return true;
    }
};
