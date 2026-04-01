/*
当 right 向右移动，遇到字符 c 时，只有两种情况：

? 情况一：c 不在当前窗口内
窗口:  [ x  y  z ]  c
         ↑        ↑
        left     right
c 是新字符，直接加入窗口，不会产生重复 → 无需移动 left

? 情况二：c 在当前窗口内
窗口:  [ a  b  c  d  e ]  c    ← right 遇到重复的 c
              ↑           ↑
         c上次位置       right
此时把 left 跳到 重复字符上次位置的下一位：

新窗口:        [ d  e  c ]
                ↑        ↑
               left     right
这样旧的 c 就被踢出窗口之外了，新窗口内不再有重复
*/
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // <key,value>,记录字符和其对应下标
            unordered_map<char, int> charIndex;
            
            int maxLen = 0;
            int left = 0; // 窗口左边界
            
            for (int right = 0; right < s.size(); right++) {
                char c = s[right];
                
                // 如果字符已存在，且其上次出现位置在窗口内
                // 则将左边界移动到重复字符的下一位
                if (charIndex.count(c) && charIndex[c] >= left) {
                    left = charIndex[c] + 1;
                }
                
                
                charIndex[c] = right;
                
                
                maxLen = max(maxLen, right - left + 1);
            }
            
            return maxLen;
        }
    };
    