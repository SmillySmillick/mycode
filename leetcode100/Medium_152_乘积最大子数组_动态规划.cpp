/*
LeetCode 152. 乘积最大子数组（Medium）
手撕思路：乘到负数会让最大变最小、最小变最大，所以同时维护以当前位置结尾的最大乘积 maxProd 和最小乘积 minProd。
复杂度：时间 O(n)，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], minProd = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(maxProd, minProd);
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};
