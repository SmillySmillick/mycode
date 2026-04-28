/*
LeetCode 39. 组合总和（Medium）
手撕思路：回溯枚举选哪个数。每个数可以重复使用，所以递归下一层仍从 i 开始；为了避免重复组合，后面只能选当前位置及之后的数。
复杂度：指数级，取决于答案数量。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(candidates, target, 0, path, ans);
        return ans;
    }
private:
    void dfs(vector<int>& nums, int remain, int start, vector<int>& path, vector<vector<int>>& ans) {
        if (remain == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > remain) break;
            path.push_back(nums[i]);
            dfs(nums, remain - nums[i], i, path, ans);
            path.pop_back();
        }
    }
};
