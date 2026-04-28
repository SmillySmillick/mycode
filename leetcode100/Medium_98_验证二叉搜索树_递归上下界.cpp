/*
LeetCode 98. 验证二叉搜索树（Medium）
手撕思路：BST 中序遍历应严格递增。递归时也可以传上下界，当前节点必须在 (low, high) 范围内。
复杂度：时间 O(n)，空间 O(h)。
*/
#include <climits>
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
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool check(TreeNode* root, long long low, long long high) {
        if (!root) return true;
        if (root->val <= low || root->val >= high) return false;
        return check(root->left, low, root->val) && check(root->right, root->val, high);
    }
};
