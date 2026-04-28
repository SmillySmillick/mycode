/*
LeetCode 621. 任务调度器（Medium）
手撕思路：最高频任务决定框架。若最大频次为 maxCnt，有 maxKinds 种任务达到最大频次，最短时间至少是 (maxCnt-1)*(n+1)+maxKinds，再和任务总数取最大。
复杂度：时间 O(N+26)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char c : tasks) cnt[c - 'A']++;
        int maxCnt = *max_element(cnt.begin(), cnt.end());
        int maxKinds = 0;
        for (int x : cnt) if (x == maxCnt) maxKinds++;
        int frame = (maxCnt - 1) * (n + 1) + maxKinds;
        return max((int)tasks.size(), frame);
    }
};
