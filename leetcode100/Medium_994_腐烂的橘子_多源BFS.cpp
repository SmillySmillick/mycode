/*
LeetCode 994. 腐烂的橘子（Medium）
手撕思路：多源 BFS。所有烂橘子先入队，每一层代表一分钟，向四周感染新鲜橘子。最后还有新鲜橘子则返回 -1。
复杂度：时间 O(mn)，空间 O(mn)。
*/
#include <vector>
#include <queue>
#include <utility>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, minutes = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        vector<int> dir = {1, 0, -1, 0, 1};
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            minutes++;
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dir[k], ny = y + dir[k + 1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};

