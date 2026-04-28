/*
LeetCode 560. 和为 K 的子数组（Medium）

手撕思路：
1. 子数组和可以用前缀和表示：sum(i..j) = prefix[j] - prefix[i-1]。
2. 遍历到当前前缀和 cur 时，如果之前出现过 cur-k，那么这些位置到当前都能形成和为 k 的子数组。
3. 哈希表记录每个前缀和出现次数。
4. 注意先查 count[cur-k]，再把当前 cur 加入表，避免空子数组干扰。

复杂度：时间 O(n)，空间 O(n)。
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int cur = 0, ans = 0;
        for (int x : nums) {
            cur += x;
            if (count.count(cur - k)) {
                ans += count[cur - k];
            }
            count[cur]++;
        }
        return ans;
    }
};
