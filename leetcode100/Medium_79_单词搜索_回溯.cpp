/*
LeetCode 79. 单词搜索（Medium）
手撕思路：从每个格子作为起点 DFS，匹配当前字符后向四个方向走。用临时标记避免一个格子在同一路径里重复使用，回溯时恢复。
复杂度：时间 O(mn*4^L)，空间 O(L)。
*/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (board[i][j] != word[idx]) return false;
        char old = board[i][j];
        board[i][j] = '#';
        bool ok = dfs(board, word, i + 1, j, idx + 1) ||
                  dfs(board, word, i - 1, j, idx + 1) ||
                  dfs(board, word, i, j + 1, idx + 1) ||
                  dfs(board, word, i, j - 1, idx + 1);
        board[i][j] = old;
        return ok;
    }
};
