/*
LeetCode 3. 无重复字符的最长子串（Medium）

手撕思路：
1. 子串要求连续，所以考虑滑动窗口 [left, right]。
2. right 每次加入一个字符，如果这个字符上次出现位置在窗口内，说明重复了。
3. 此时 left 直接跳到“上次出现位置 + 1”，不用一步步挪。
4. 每轮更新字符最后出现位置，再用窗口长度更新答案。

复杂度：时间 O(n)，空间 O(字符集大小)。
*/
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last;
        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (last.count(c) && last[c] >= left) {
                left = last[c] + 1;
            }
            last[c] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
