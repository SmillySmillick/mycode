/*
LeetCode 128. 最长连续序列（Medium）

手撕思路：
1. 要 O(n)，不能排序。
2. 用哈希集合存所有数，方便 O(1) 判断一个数是否存在。
3. 只有当 num-1 不存在时，num 才是一个连续序列的起点。
4. 从起点开始不断找 num+1，统计长度并更新答案。

复杂度：时间 O(n)，空间 O(n)。
*/
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int num : st) {
            if (st.count(num - 1)) continue;
            int cur = num;
            int len = 1;
            while (st.count(cur + 1)) {
                cur++;
                len++;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
