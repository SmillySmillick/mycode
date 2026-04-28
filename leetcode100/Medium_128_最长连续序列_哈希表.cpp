/*
unordered_set是一个一元组哈希,由于原始数组已经排序,可以直接用
*/
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            
            unordered_set<int> numSet(nums.begin(), nums.end());//构建去重的哈希表
            int maxLen = 0;
    
            
            for (int num : numSet) {
                
                if (!numSet.count(num - 1) ) {//前置不存在,重新取长度
                    int curNum = num;
                    int curLen = 1;
    
                    
                    while (numSet.count(curNum + 1)) {//当前可取的最长序列
                        curNum++;
                        curLen++;
                    }
    
                    maxLen = max(maxLen, curLen);//更新最长序列
                }
            }
    
            return maxLen;
        }
    };