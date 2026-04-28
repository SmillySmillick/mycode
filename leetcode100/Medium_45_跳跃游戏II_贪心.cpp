/*
LeetCode 45. 跳跃游戏 II（Medium）
手撕思路：贪心按层扩展。当前步数能覆盖到 end，遍历这一层时维护下一层最远位置 farthest；走到 end 就必须跳一步，end 更新为 farthest。
复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0, end = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == end) {
                steps++;
                end = farthest;
            }
        }
        return steps;
    }
};
