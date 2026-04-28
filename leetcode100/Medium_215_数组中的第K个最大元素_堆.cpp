/*
LeetCode 215. 数组中的第 K 个最大元素（Medium）
手撕思路：维护大小为 k 的小根堆。堆里始终放当前最大的 k 个数，堆顶就是第 k 大。
复杂度：时间 O(n log k)，空间 O(k)。
*/
#include <vector>
#include <queue>
#include <functional>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int x : nums) {
            heap.push(x);
            if (heap.size() > k) heap.pop();
        }
        return heap.top();
    }
};
