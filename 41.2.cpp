#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> f; // op=0: (a, b) 分数背包
    vector<pair<int,int>> g; // op=1: (a, b) 0/1背包
    long long tot = 0;

    for (int i = 0; i < n; i++) {
        int op, t, a, b;
        cin >> op >> t >> a >> b;
        tot += t;
        if (op == 0) f.push_back({a, b});
        else         g.push_back({a, b});
    }

    // op=0 按效率 b/a 降序，贪心时优先选效率高的
    sort(f.begin(), f.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
        return (long long)x.second * y.first > (long long)y.second * x.first;
    });

    // 贪心：给定预算 bud，op=0 能获得的最大缩减
    auto greedy = [&](int bud) -> double {
        double res = 0.0;
        for (auto& [a, b] : f) {
            if (bud <= 0) break;
            int use = min(bud, a);
            res += (double)use * b / a;
            bud -= use;
        }
        return res;
    };

    // ---- 0/1 背包 DP（处理所有 op=1 的任务）----

    // 背包容量上限：不超过 m，也不超过所有 op=1 任务费用之和（选完也不会超）
    int cap = 0;
    for (auto& [a, b] : g) cap += a;
    cap = min(cap, m);

    // dp[j] 表示：恰好花费 j 点参数在 op=1 任务上，能获得的最大缩减
    // 初始化为 -1 表示"该花费不可达"，只有 dp[0]=0（花0获得0缩减）是合法起点
    vector<long long> dp(cap + 1, -1);
    dp[0] = 0;

    for (auto& [a, b] : g) {
        if (a > cap) continue; // 该任务费用超出上限，跳过

        // 逆序遍历：保证每个任务只被选一次（0/1 背包标准写法）
        // 若正序遍历，同一任务可能在同一轮被反复叠加（变成完全背包）
        for (int j = cap; j >= a; j--) {

            // 只有 dp[j-a] 可达（!= -1），才能从"花费 j-a"转移到"花费 j"
            if (dp[j - a] != -1) {

                // 状态转移：在已花费 j-a 的基础上，再花 a 选当前任务，获得 b 缩减
                dp[j] = max(dp[j], dp[j - a] + b);
            }
        }
    }

    // ---- 合并两类任务，枚举最优分配 ----

    // 枚举 op=1 任务花费 j，把剩余预算 m-j 全交给 op=0 任务贪心
    double ans = 0.0;
    for (int j = 0; j <= cap; j++) {
        if (dp[j] == -1) continue;          // 花费 j 不可达，跳过
        if (m - j < 0)   break;             // 剩余预算不足，终止
        double cur = (double)dp[j] + greedy(m - j);
        ans = max(ans, cur);
    }

    cout << fixed << setprecision(6) << (double)tot - ans << endl;

    return 0;
}
