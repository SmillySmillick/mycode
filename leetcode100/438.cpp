#include <vector>
#include <string>
using namespace std;
/*
滑动窗口,记录窗口内每个字符的频次,如果窗口内每个字符的频次和p的每个字符的频次相同,则返回窗口的起始索引
*/
class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> result;
            int sLen = s.size(), pLen = p.size();
    
            // s 比 p 短，不可能存在异位词
            if (sLen < pLen) return result;
    
            // 字符频次数组（仅小写字母，26个）
            vector<int> pCount(26, 0), windowCount(26, 0);
    
            // 统计 p 的字符频次，以及初始化前 pLen 个字符
            for (int i = 0; i < pLen; i++) {
                pCount[p[i] - 'a']++;
                windowCount[s[i] - 'a']++;
            }
    
            // 检查初始窗口
            if (windowCount == pCount) result.push_back(0);
    
            // 滑动窗口：右移一位，加入新字符，移除旧字符
            for (int i = pLen; i < sLen; i++) {
                windowCount[s[i] - 'a']++;           // 新字符进入窗口
                windowCount[s[i - pLen] - 'a']--;    // 旧字符离开窗口
    
                if (windowCount == pCount) {
                    result.push_back(i - pLen + 1);  // 记录窗口起始索引
                }
            }
    
            return result;
        }
    };