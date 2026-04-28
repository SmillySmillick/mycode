/*
LeetCode 347. 前 K 个高频元素（Medium）
手撕思路：哈希表统计频次，再用大小为 k 的小根堆保存当前频次最高的 k 个元素。
复杂度：时间 O(n log k)，空间 O(n)。
*/
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums) cnt[x]++;
        auto cmp = [](pair<int,int>& a, pair<int,int>& b) { return a.second > b.second; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> heap(cmp);
        for (auto& p : cnt) {
            heap.push(p);
            if (heap.size() > k) heap.pop();
        }
        vector<int> ans;
        while (!heap.empty()) {
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};

