/*
LeetCode 22. 括号生成（Medium）
手撕思路：回溯构造字符串。左括号数量小于 n 就能放左括号；右括号数量小于左括号数量才可以放右括号，保证任何前缀都合法。
复杂度：结果数量是卡特兰数，时间和空间都与输出规模相关。
*/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        dfs(n, 0, 0, path, ans);
        return ans;
    }
private:
    void dfs(int n, int left, int right, string& path, vector<string>& ans) {
        if (path.size() == 2 * n) {
            ans.push_back(path);
            return;
        }
        if (left < n) {
            path.push_back('(');
            dfs(n, left + 1, right, path, ans);
            path.pop_back();
        }
        if (right < left) {
            path.push_back(')');
            dfs(n, left, right + 1, path, ans);
            path.pop_back();
        }
    }
};
