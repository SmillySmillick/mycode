/*
LeetCode 763. 划分字母区间（Medium）
手撕思路：先记录每个字符最后出现位置。遍历字符串时维护当前片段必须覆盖到的最远位置 end，走到 end 就切一段。
复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        for (int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;
        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};

