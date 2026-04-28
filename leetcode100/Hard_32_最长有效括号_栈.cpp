/*
LeetCode 32. 最长有效括号（Hard）

手撕思路：
1. 用栈保存“还没匹配成功的位置”。
2. 先放一个 -1 当哨兵，表示当前合法段开始前的位置。
3. 遇到 '('：下标入栈。
4. 遇到 ')'：弹出一个位置尝试匹配。
   - 如果弹完栈空，说明这个 ')' 没人匹配，把它作为新的边界入栈。
   - 如果栈不空，当前 i - 栈顶 就是以 i 结尾的最长合法长度。

复杂度：时间 O(n)，空间 O(n)。
*/
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // 哨兵：合法括号串左边界的前一个位置。
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // 当前 ')' 无法匹配，成为新的无效边界。
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};
