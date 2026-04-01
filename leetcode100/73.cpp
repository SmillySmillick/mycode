/*
只需要扫一遍数组即可,第一行和第一列作为标记位,如果该行或该列有0,则将该行或该列的第一个元素置0
但需要先扫第一行和第一列确认是否要被置零
*/
#include <vector>
using namespace std;
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size(), n = matrix[0].size();
    
           
            bool firstRowZero = false, firstColZero = false;
    
            for (int j = 0; j < n; j++)
                if (matrix[0][j] == 0) { firstRowZero = true; break; }
    
            for (int i = 0; i < m; i++)
                if (matrix[i][0] == 0) { firstColZero = true; break; }
    
            
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;  // 标记该行
                        matrix[0][j] = 0;  // 标记该列
                    }
                }
            }
    
            
            for (int i = 1; i < m; i++)
                if (matrix[i][0] == 0)
                    for (int j = 1; j < n; j++)
                        matrix[i][j] = 0;
    
            for (int j = 1; j < n; j++)
                if (matrix[0][j] == 0)
                    for (int i = 1; i < m; i++)
                        matrix[i][j] = 0;
    
            
            if (firstRowZero)
                for (int j = 0; j < n; j++) matrix[0][j] = 0;
    
            if (firstColZero)
                for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    };
    