/*
LeetCode 139. 单词拆分（Medium）
手撕思路：dp[i] 表示 s[0..i) 能否被拆分。枚举 j，如果 dp[j] 为真且 s[j..i) 在词典中，则 dp[i] 为真。
复杂度：时间 O(n^2 * 子串成本)，空间 O(n)。
*/
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
