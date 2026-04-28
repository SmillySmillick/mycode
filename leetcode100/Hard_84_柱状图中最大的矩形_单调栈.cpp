/*
LeetCode 84. 柱状图中最大的矩形（Hard）

手撕思路：
1. 对每根柱子，最大矩形高度如果选它，就需要知道左右第一个比它矮的位置。
2. 用单调递增栈保存柱子下标。
3. 遍历到一个更矮的柱子时，栈顶柱子的右边界就确定了；弹出并计算面积。
4. 在数组末尾补一个高度 0 的哨兵，强制把栈里剩余柱子都结算。

复杂度：时间 O(n)，空间 O(n)。
*/
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // 哨兵，让所有柱子最终都能出栈结算。
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int leftLess = st.empty() ? -1 : st.top();
                int width = i - leftLess - 1;
                ans = max(ans, h * width);
            }
            st.push(i);
        }

        heights.pop_back();
        return ans;
    }
};
