/*
一些语法
for(const string& s : strs)从strs开始轮询(只读),每次引用赋值给名叫s的变量(&代表引用,节省空间)
for(auto& [key,group] : mp)auto&自动选择类型轮询,给mp的二元组变量名为<key,group>,等价于for(auto& p : mp)
*/
/*
题目本身不难,给每个词排序,排序相同的就是字母异位词,压栈,把ans出栈即可
*/
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
            
            for (const string& s : strs) {
                string key = s;
                sort(key.begin(), key.end());  // 排序作为 key
                mp[key].push_back(s);
            }
            
            vector<vector<string>> res;
            for (auto& [key, group] : mp) {
                res.push_back(move(group));
            }
            return res;
        }
    };