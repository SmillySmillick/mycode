/*
LeetCode 337. 打家劫舍 III（Medium）
手撕思路：树形 DP。每个节点返回两个值：偷当前节点的最大收益、不偷当前节点的最大收益。
复杂度：时间 O(n)，空间 O(h)。
*/
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res[0], res[1]);
    }
private:
    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int robRoot = root->val + left[0] + right[0];
        int skipRoot = max(left[0], left[1]) + max(right[0], right[1]);
        return {skipRoot, robRoot};
    }
};
