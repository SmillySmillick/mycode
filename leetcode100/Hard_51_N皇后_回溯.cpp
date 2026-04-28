/*
LeetCode 51. N 皇后（Hard）

手撕思路：
1. 一行只放一个皇后，所以递归参数用 row 表示当前处理第几行。
2. 对当前行枚举每一列 col，判断这个位置是否安全。
3. 安全条件：同列没有皇后，两条斜线没有皇后。
   - 主对角线 row - col 固定，为了下标非负，加 n-1。
   - 副对角线 row + col 固定。
4. 放皇后 -> 递归下一行 -> 撤销皇后，这就是标准回溯。

复杂度：时间约 O(n!)，空间 O(n)。
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> colUsed(n, false);
        vector<bool> diag1(2 * n - 1, false); // row - col + n - 1
        vector<bool> diag2(2 * n - 1, false); // row + col

        backtrack(0, n, board, colUsed, diag1, diag2, ans);
        return ans;
    }

private:
    void backtrack(int row, int n,
                   vector<string>& board,
                   vector<bool>& colUsed,
                   vector<bool>& diag1,
                   vector<bool>& diag2,
                   vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;
            int d2 = row + col;
            if (colUsed[col] || diag1[d1] || diag2[d2]) continue;

            board[row][col] = 'Q';
            colUsed[col] = diag1[d1] = diag2[d2] = true;

            backtrack(row + 1, n, board, colUsed, diag1, diag2, ans);

            board[row][col] = '.';
            colUsed[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};
