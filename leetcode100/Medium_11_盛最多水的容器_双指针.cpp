/*
显然往中间收缩,宽度变小,想让面积增大,只会和矮的一侧有关
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int l = 0, r = height.size() - 1, ans = 0;
            while (l < r) {
                ans = max(ans, min(height[l], height[r]) * (r - l));
                height[l] < height[r] ? l++ : r--;
            }
            return ans;
        }
    };