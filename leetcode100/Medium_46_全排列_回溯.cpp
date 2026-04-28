/*
LeetCode 46. 全排列（Medium）

手撕思路：
1. 全排列就是每个位置都尝试放一个还没用过的数。
2. path 表示当前排列前缀，used[i] 表示 nums[i] 是否已经放进 path。
3. path 长度等于 nums 长度时，得到一个完整排列。
4. 回溯模板：做选择 -> 递归 -> 撤销选择。

复杂度：时间 O(n*n!)，空间 O(n)。
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path, ans);
        return ans;
    }
private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& ans) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used, path, ans);
            used[i] = false;
            path.pop_back();
        }
    }
};
