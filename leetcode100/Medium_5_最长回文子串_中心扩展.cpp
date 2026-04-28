/*
LeetCode 5. 最长回文子串（Medium）
手撕思路：回文串从中心向两边扩展。中心可能是一个字符，也可能是两个字符。枚举每个中心，扩展出最长回文并更新答案。
复杂度：时间 O(n^2)，空间 O(1)。
*/
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int bestStart = 0, bestLen = 0;
        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, bestStart, bestLen);       // 奇数长度
            expand(s, i, i + 1, bestStart, bestLen);   // 偶数长度
        }
        return s.substr(bestStart, bestLen);
    }
private:
    void expand(string& s, int l, int r, int& bestStart, int& bestLen) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        int len = r - l - 1;
        if (len > bestLen) {
            bestLen = len;
            bestStart = l + 1;
        }
    }
};
