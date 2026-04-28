//全排列,但每个叶子节点都返回一次
#include <vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> path;
    
            backtrack(nums, 0, path, result);
            return result;
        }
    
    private:
        void backtrack(vector<int>& nums, int start,
                       vector<int>& path, vector<vector<int>>& result) {
            // 每个节点都收集结果
            result.push_back(path);
    
            for (int i = start; i < nums.size(); i++) {
                
                path.push_back(nums[i]);
    
                
                backtrack(nums, i + 1, path, result);
    
                
                path.pop_back();
            }
        }
    };
    