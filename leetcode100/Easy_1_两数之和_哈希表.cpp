/*
用o(n)的规模解决此问题
vector<int>& nums,输入数组
unordered_map<int,int> mp,哈希表记录每个数的补数
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // 记录数字和对应下标
        
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            
            if (mp.count(need)) {//查表,即二元组里有没有下标为i数字的补
                return {mp[need], i};//返回下标
            }
            
            mp[nums[i]] = i;//在表中填某数的下标i
        }
        
        return {};//题目一定有解
    }
};
