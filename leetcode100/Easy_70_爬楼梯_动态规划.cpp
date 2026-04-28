/*
LeetCode 70. 爬楼梯（Easy）

手撕思路：
1. 到第 i 阶的最后一步，要么从 i-1 走 1 步，要么从 i-2 走 2 步。
2. 所以 f[i] = f[i-1] + f[i-2]，就是斐波那契。
3. 只依赖前两个状态，用两个变量滚动即可。

复杂度：时间 O(n)，空间 O(1)。
*/
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1;
        int prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
