/*
LeetCode 54. 螺旋矩阵（Medium）
手撕思路：维护上下左右四个边界，每次按右、下、左、上四个方向收一圈，收完更新边界。
复杂度：时间 O(mn)，空间 O(1) 不计答案。
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) ans.push_back(matrix[top][j]);
            top++;
            for (int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--) ans.push_back(matrix[bottom][j]);
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};
