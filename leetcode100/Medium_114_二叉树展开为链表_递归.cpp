/*
LeetCode 114. 二叉树展开为链表（Medium）
手撕思路：后序处理左右子树。把左子树展开后接到右边，再把原右子树接到新右链表的末尾。
复杂度：时间 O(n)，空间 O(h)。
*/
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
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* oldRight = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* tail = root;
        while (tail->right) tail = tail->right;
        tail->right = oldRight;
    }
};
