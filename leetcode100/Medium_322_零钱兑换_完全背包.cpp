/*
LeetCode 322. 零钱兑换（Medium）
手撕思路：完全背包求最少硬币数。dp[i] 表示凑出金额 i 的最少硬币数，枚举 coin 更新 dp[i]。
复杂度：时间 O(amount * coins)，空间 O(amount)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
