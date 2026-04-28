/*
LeetCode 394. 字符串解码（Medium）
手撕思路：遇到数字累积倍数，遇到 '[' 把当前字符串和倍数入栈，重新开始；遇到 ']' 弹出并重复拼接。
复杂度：时间 O(输出长度)，空间 O(嵌套深度+输出长度)。
*/
#include <string>
#include <stack>
#include <cctype>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        string cur;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (c == '[') {
                nums.push(num);
                strs.push(cur);
                num = 0;
                cur.clear();
            } else if (c == ']') {
                int times = nums.top(); nums.pop();
                string prev = strs.top(); strs.pop();
                while (times--) prev += cur;
                cur = prev;
            } else {
                cur.push_back(c);
            }
        }
        return cur;
    }
};

