#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = LLONG_MIN / 4;

struct Line { ll m, b; };

bool is_redundant(const Line &l1, const Line &l2, const Line &l3) {
   __int128 left = (__int128)(l2.b - l1.b) * (__int128)(l2.m - l3.m);
   __int128 right = (__int128)(l3.b - l2.b) * (__int128)(l1.m - l2.m);
   return left >= right;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n, m;
   if (!(cin >> n >> m)) return 0;
   vector<tuple<int,int,int,int>> items;
   for (int i = 0; i < n; ++i) {
       int t; cin >> t;
       if (t == 1) { int A,B; cin >> A >> B; items.emplace_back(t,A,B,0); }
       else if (t == 2) { int A,B,C; cin >> A >> B >> C; items.emplace_back(t,A,B,C); }
       else { int A,B; cin >> A >> B; items.emplace_back(t,A,B,-1); }
   }
   vector<ll> dp(m+1, NEG_INF);
   dp[0] = 0;
   for (auto &it : items) {
       int type = get<0>(it);
       int A = get<1>(it);
       int B = get<2>(it);
       int C = get<3>(it);
       if (type == 3) {
           for (int v = B; v <= m; ++v)
               if (dp[v - B] != NEG_INF)
                   dp[v] = max(dp[v], dp[v - B] + (ll)A);
       } else if (type == 2) {
           int cnt = C;
           for (int k = 1; cnt > 0; k <<= 1) {
               int take = min(k, cnt);
               ll val = (ll)take * A;
               int vol = take * B;
               for (int j = m; j >= vol; --j)
                   if (dp[j - vol] != NEG_INF)
                       dp[j] = max(dp[j], dp[j - vol] + val);
               cnt -= take;
           }
       } else {
           vector<ll> prev = dp;
           if (A == 0) {
               ll best = NEG_INF;
               for (int j = 1; j <= m; ++j) {
                   if (prev[j-1] != NEG_INF)
                       best = max(best, prev[j-1] + (ll)B * (j-1));
                   if (best != NEG_INF)
                       dp[j] = max(dp[j], -(ll)B * j + best);
               }
           } else {
               deque<Line> q;
               for (int j = 1; j <= m; ++j) {
                   int k = j - 1;
                   if (prev[k] != NEG_INF) {
                       ll slope = -2LL * A * k;
                       ll intercept = prev[k] + (ll)A * k * k + (ll)B * k;
                       Line nl = {slope, intercept};
                       while (q.size() >= 2 && is_redundant(q[q.size()-2], q[q.size()-1], nl)) q.pop_back();
                       q.push_back(nl);
                   }
                   if (q.empty()) continue;
                   while (q.size() >= 2) {
                       __int128 v0 = (__int128)q[0].m * j + (__int128)q[0].b;
                       __int128 v1 = (__int128)q[1].m * j + (__int128)q[1].b;
                       if (v0 <= v1) q.pop_front();
                       else break;
                   }
                   ll bestLineVal = (ll)((__int128)q.front().m * j + (__int128)q.front().b);
                   ll candidate = (ll)A * j * j - (ll)B * j + bestLineVal;
                   dp[j] = max(dp[j], candidate);
               }
           }
       }
   }
   ll ans = 0;
   for (int i = 0; i <= m; ++i)
       if (dp[i] != NEG_INF)
           ans = max(ans, dp[i]);
   cout << ans << "\n";
}
