/*
LeetCode 739. 每日温度（Medium）
手撕思路：单调递减栈保存还没找到更高温度的下标。当前温度更高时，弹出栈顶并计算等待天数。
复杂度：时间 O(n)，空间 O(n)。
*/
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top(); st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
};
