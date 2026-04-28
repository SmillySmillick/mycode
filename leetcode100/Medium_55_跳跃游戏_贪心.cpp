/*
nums上的数是几就能走几步,能否走到终点?
贪心找最优
*/
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            int maxReach = 0; 
    
            for (int i = 0; i < n; i++) {
                
                if (i > maxReach) return false;//当前不可达,终点也不可达,第一块总是可达的
    
                
                maxReach = max(maxReach, i + nums[i]);//试图找最远可达的位置
    
                // 已经能到达终点
                if (maxReach >= n - 1) return true;
            }
    
            return true;
        }
    };