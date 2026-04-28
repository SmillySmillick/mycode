/*
不相同的三数之和=0,用双指针找
*/ 
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;   // 二维数组存放最终答案
        int n = nums.size();

        // 第一步：排序
        sort(nums.begin(), nums.end());

        // 第二步：枚举三元组中的第一个数
        for (int i = 0; i < n - 2; i++) {
            // 剪枝：
            // 排序后，如果 nums[i] > 0，
            // 那么后面的数都大于此不可能再凑出和为 0
            if (nums[i] > 0) break;

            // 去重：
            // 如果当前 nums[i] 和前一个一样，
            // 说明这轮会产生重复
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 双指针初始化
            int left = i + 1;
            int right = n - 1;

            // 第三步：在剩下的区间里找两个数
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // 找到一个合法三元组
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});//进栈

                    // 去重：
                    // left 指向的值如果重复，就一直跳过
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // 去重：
                    // right 指向的值如果重复，就一直跳过
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // 找下一组
                    left++;
                    right--;
                }
                // 当前和太小，说明需要更大的数
                else if (sum < 0) {
                    left++;
                }
                // 当前和太大，说明需要更小的数
                else {
                    right--;
                }
            }
        }

        return res;
    }
};
