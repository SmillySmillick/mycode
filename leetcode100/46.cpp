/*
全排列的一个做法,递归回溯
*/
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> path;
            vector<bool> used(nums.size(), false);
    
            backtrack(nums, path, used, result);
            return result;
        }
    
    private:
        void backtrack(vector<int>& nums, vector<int>& path,
                       vector<bool>& used, vector<vector<int>>& result) {
            // 终止条件：路径长度等于数组长度
            if (path.size() == nums.size()) {
                result.push_back(path);  // 直接拷贝，无需手动 copy
                return;
            }
    
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;       // 已使用，跳过
    
                // 做选择
                path.push_back(nums[i]);
                used[i] = true;
    
                // 递归
                backtrack(nums, path, used, result);
    
                // 撤销选择（回溯）
                path.pop_back();
                used[i] = false;
            }
        }
    };