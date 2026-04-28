/*
LeetCode 300. 最长递增子序列（Medium）
手撕思路：tails[len] 保存长度为 len+1 的递增子序列的最小结尾。遍历每个数，用二分找到它能替换的位置。
复杂度：时间 O(n log n)，空间 O(n)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return tails.size();
    }
};
