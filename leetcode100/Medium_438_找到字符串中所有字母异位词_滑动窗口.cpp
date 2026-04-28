/*
LeetCode 438. 找到字符串中所有字母异位词（Medium）

手撕思路：
1. 异位词要求字符频次完全相同，顺序无所谓。
2. 窗口长度固定为 p.size()，维护窗口内 26 个小写字母频次。
3. 初始化第一个窗口，之后每次右移一格：加入右侧新字符，移除左侧旧字符。
4. 每次窗口频次等于 p 的频次，就记录窗口起点。

复杂度：时间 O(26*n)，可视作 O(n)，空间 O(1)。
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        if (n < m) return ans;

        vector<int> need(26, 0), window(26, 0);
        for (int i = 0; i < m; i++) {
            need[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        if (window == need) ans.push_back(0);

        for (int right = m; right < n; right++) {
            window[s[right] - 'a']++;
            window[s[right - m] - 'a']--;
            if (window == need) ans.push_back(right - m + 1);
        }
        return ans;
    }
};
