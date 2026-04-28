/*
LeetCode 399. 除法求值（Medium）
手撕思路：把 a/b=v 看成图中 a->b 权重 v，b->a 权重 1/v。查询 x/y 就从 x DFS 到 y，沿路乘权重。
复杂度：建图 O(e)，每次查询 O(V+E)。
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            graph[a].push_back({b, values[i]});
            graph[b].push_back({a, 1.0 / values[i]});
        }
        vector<double> ans;
        for (auto& q : queries) {
            unordered_set<string> visited;
            double res = dfs(q[0], q[1], visited);
            ans.push_back(res);
        }
        return ans;
    }
private:
    unordered_map<string, vector<pair<string,double>>> graph;
    double dfs(string cur, string target, unordered_set<string>& visited) {
        if (!graph.count(cur) || !graph.count(target)) return -1.0;
        if (cur == target) return 1.0;
        visited.insert(cur);
        for (auto& [next, weight] : graph[cur]) {
            if (visited.count(next)) continue;
            double sub = dfs(next, target, visited);
            if (sub != -1.0) return weight * sub;
        }
        return -1.0;
    }
};

