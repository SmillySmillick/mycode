#include <vector>
#include <unordered_map>
using namespace std;
/*
sum(i,j)== prefix[j] - prefix[i],记录前缀和出现的次数,如果前缀和 - k 的次数存在,则count加上前缀和 - k 的次数
*/
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> prefixSumCount;  // 存储前缀和出现的次数
            prefixSumCount[0] = 1;  // 初始前缀和为 0 的出现次数为 1
            int count = 0, currentSum = 0;
            
            for (int num : nums) {
                currentSum += num;  // 更新当前前缀和
                if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                    count += prefixSumCount[currentSum - k];  // 找到当前前缀和 - k 的子数组数量
                }
                prefixSumCount[currentSum]++;  // 更新当前前缀和出现的次数
            }
            
            return count;
        }
    };