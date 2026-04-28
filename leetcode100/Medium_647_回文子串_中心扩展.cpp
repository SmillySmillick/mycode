/*
LeetCode 647. 回文子串（Medium）
手撕思路：枚举每个中心向两边扩展，扩展成功一次就多一个回文子串。中心有单字符和双字符两类。
复杂度：时间 O(n^2)，空间 O(1)。
*/
#include <string>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += expand(s, i, i);
            ans += expand(s, i, i + 1);
        }
        return ans;
    }
private:
    int expand(string& s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
};
