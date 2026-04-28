/*
LeetCode 240. 搜索二维矩阵 II（Medium）
手撕思路：从右上角开始。当前值大于 target 就左移，小于 target 就下移，每次排除一行或一列。
复杂度：时间 O(m+n)，空间 O(1)。
*/
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
