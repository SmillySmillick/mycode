/*
LeetCode 4. 寻找两个正序数组的中位数（Hard）

手撕思路：
1. 两个有序数组的中位数，本质是找合并后第 k 小的数。
2. 不真的合并数组，否则是 O(m+n)。
3. 写一个 getKth(k)：每次比较两个数组当前起点往后 k/2 个位置的值。
   - 谁的小，说明谁前面的 k/2 个数都不可能是第 k 小，直接丢掉。
   - k 也同步减掉被丢弃的数量。
4. 如果总长度是奇数，找第 n/2+1 小；偶数，找中间两个数取平均。

复杂度：时间 O(log(m+n))，空间 O(1)。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 1) {
            return getKth(nums1, 0, nums2, 0, total / 2 + 1);
        }

        int leftMid = getKth(nums1, 0, nums2, 0, total / 2);
        int rightMid = getKth(nums1, 0, nums2, 0, total / 2 + 1);
        return (leftMid + rightMid) / 2.0;
    }

private:
    int getKth(vector<int>& a, int i, vector<int>& b, int j, int k) {
        while (true) {
            // a 用完了，只能从 b 里取第 k 个。
            if (i == a.size()) return b[j + k - 1];
            // b 用完了，只能从 a 里取第 k 个。
            if (j == b.size()) return a[i + k - 1];
            // k == 1 时，答案就是两个当前头部较小的那个。
            if (k == 1) return min(a[i], b[j]);

            int half = k / 2;
            int newI = min(i + half, (int)a.size()) - 1;
            int newJ = min(j + half, (int)b.size()) - 1;

            if (a[newI] <= b[newJ]) {
                // a[i..newI] 这段都不可能是第 k 小，丢掉。
                k -= newI - i + 1;
                i = newI + 1;
            } else {
                // b[j..newJ] 这段都不可能是第 k 小，丢掉。
                k -= newJ - j + 1;
                j = newJ + 1;
            }
        }
    }
};
