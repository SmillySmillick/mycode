/*
LeetCode 295. 数据流的中位数（Hard）

手撕思路：
1. 中位数需要把数据分成较小的一半和较大的一半。
2. 用两个堆：
   - small：大根堆，保存较小的一半，堆顶是左半边最大值。
   - large：小根堆，保存较大的一半，堆顶是右半边最小值。
3. 保持 small.size() == large.size() 或 small 比 large 多 1。
4. 插入时先放进 small，再把 small 最大值挪到 large，最后如果 large 更多，再挪回 small。
5. 奇数个元素，中位数是 small.top()；偶数个元素，是两个堆顶平均值。

复杂度：addNum 时间 O(log n)，findMedian 时间 O(1)，空间 O(n)。
*/
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();

        if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        }
        return (small.top() + large.top()) / 2.0;
    }

private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
};

