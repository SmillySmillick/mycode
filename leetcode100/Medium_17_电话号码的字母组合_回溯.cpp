/*
LeetCode 17. 电话号码的字母组合（Medium）
手撕思路：每个数字对应几个字母，本质是多叉树枚举。递归处理第 idx 个数字，选择一个字母放入 path，递归后撤销。
复杂度：时间 O(4^n)，空间 O(n)。
*/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        string path;
        backtrack(digits, 0, path, ans);
        return ans;
    }
private:
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(string& digits, int idx, string& path, vector<string>& ans) {
        if (idx == digits.size()) {
            ans.push_back(path);
            return;
        }
        for (char c : mp[digits[idx] - '0']) {
            path.push_back(c);
            backtrack(digits, idx + 1, path, ans);
            path.pop_back();
        }
    }
};
