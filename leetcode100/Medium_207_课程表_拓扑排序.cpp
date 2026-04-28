/*
LeetCode 207. 课程表（Medium）
手撕思路：课程依赖是有向图，判断能否学完就是判断是否有环。用入度拓扑排序，入度为 0 的课先学，逐步删除边。
复杂度：时间 O(n+m)，空间 O(n+m)。
*/
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) if (indegree[i] == 0) q.push(i);
        int learned = 0;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            learned++;
            for (int next : graph[cur]) {
                if (--indegree[next] == 0) q.push(next);
            }
        }
        return learned == numCourses;
    }
};
