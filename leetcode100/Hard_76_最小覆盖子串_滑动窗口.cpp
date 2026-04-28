/*
LeetCode 76. 最小覆盖子串（Hard）

手撕思路：
1. 用 need 统计 t 里每个字符还需要多少个。
2. 右指针不断扩张窗口，把字符放进来。
   - 如果当前字符是需要的，missing--。
   - need[c]--，负数表示窗口里这个字符多了。
3. 当 missing == 0，说明窗口已经覆盖 t，开始移动左指针缩小窗口。
4. 每缩小一次都检查是否刷新答案；如果移走了必须字符，missing++，窗口失效。

复杂度：时间 O(n)，空间 O(字符集大小)。
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        for (char c : t) need[c]++;

        int missing = t.size();
        int left = 0;
        int bestStart = 0;
        int bestLen = s.size() + 1;

        for (int right = 0; right < s.size(); right++) {
            char in = s[right];
            if (need[in] > 0) missing--;
            need[in]--;

            while (missing == 0) {
                int len = right - left + 1;
                if (len < bestLen) {
                    bestLen = len;
                    bestStart = left;
                }

                char out = s[left];
                need[out]++;
                if (need[out] > 0) missing++;
                left++;
            }
        }

        return bestLen == s.size() + 1 ? "" : s.substr(bestStart, bestLen);
    }
};
