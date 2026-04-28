/*
LeetCode 49. 字母异位词分组（Medium）

手撕思路：
1. 字母异位词的本质是字符组成相同、顺序不同。
2. 把每个字符串排序，排序后的结果可以作为同一组的 key。
3. 哈希表 key -> 一组原字符串。
4. 最后把哈希表里的每个 group 放入答案。

复杂度：时间 O(n*k log k)，k 是字符串平均长度；空间 O(nk)。
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& [key, group] : mp) {
            ans.push_back(group);
        }
        return ans;
    }
};
