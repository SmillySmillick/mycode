//双指针,非0往前到slow,slow后全置零
#include<vector>
using namespace std;
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int slow = 0; 
    
            
            for (int fast = 0; fast < nums.size(); fast++) {
                if (nums[fast] != 0) {
                    nums[slow++] = nums[fast];//slow位置置非0,前进
                }
            }
    
            
            for (int i = slow; i < nums.size(); i++) {
                nums[i] = 0;
            }
        }
    };
    