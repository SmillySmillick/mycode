/*
LeetCode 236. 二叉树的最近公共祖先（Medium）
手撕思路：递归找 p/q。若左右子树分别找到，当前节点就是 LCA；如果只一边找到，就把那边结果向上返回。
复杂度：时间 O(n)，空间 O(h)。
*/
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};
