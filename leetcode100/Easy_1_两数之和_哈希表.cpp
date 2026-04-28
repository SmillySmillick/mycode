/*
LeetCode 1. 两数之和（Easy）

手撕思路：
1. 暴力是两层循环找 nums[i] + nums[j] == target，时间 O(n^2)。
2. 优化点：遍历到 nums[i] 时，只需要知道 target - nums[i] 之前有没有出现过。
3. 用哈希表存已经遍历过的值和下标。
4. 注意顺序：先查补数，再把当前数放进表，避免同一个元素被用两次。

复杂度：时间 O(n)，空间 O(n)。
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos; // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (pos.count(need)) {
                return {pos[need], i};
            }
            pos[nums[i]] = i;
        }
        return {};
    }
};
