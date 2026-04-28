/*
LeetCode 56. 合并区间（Medium）
手撕思路：先按左端点排序。当前区间和答案最后一个区间有交集就合并，否则直接加入答案。
复杂度：时间 O(n log n)，空间 O(n)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto& cur : intervals) {
            if (ans.empty() || ans.back()[1] < cur[0]) {
                ans.push_back(cur);
            } else {
                ans.back()[1] = max(ans.back()[1], cur[1]);
            }
        }
        return ans;
    }
};
