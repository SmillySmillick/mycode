/*
LeetCode 78. 子集（Medium）

手撕思路：
1. 子集问题不是只有叶子节点是答案，而是递归树上的每个节点都是一个子集。
2. start 表示下一次可以从哪个位置开始选，保证不会回头选，避免重复。
3. 每次先收集当前 path，再继续枚举后面的数。
4. 标准回溯：加入 nums[i] -> 递归 i+1 -> 弹出 nums[i]。

复杂度：时间 O(n*2^n)，空间 O(n)。
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(nums, 0, path, ans);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, ans);
            path.pop_back();
        }
    }
};
