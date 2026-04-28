/*
LeetCode 239. 滑动窗口最大值（Hard）

手撕思路：
1. 窗口每次右移一格，要快速知道窗口最大值。
2. 用双端队列保存“可能成为最大值”的下标，队列里的值从大到小。
3. 新元素进来时，把队尾所有 <= 新元素的下标弹掉，因为它们以后不可能再当最大值。
4. 队头如果已经滑出窗口，也要弹掉。
5. 当窗口长度达到 k，队头就是当前窗口最大值。

复杂度：时间 O(n)，空间 O(k)。
*/
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; // 保存下标，保证 nums[q[0]] 最大。
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            if (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }

        return ans;
    }
};
