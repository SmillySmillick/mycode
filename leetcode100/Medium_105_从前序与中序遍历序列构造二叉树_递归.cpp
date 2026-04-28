/*
LeetCode 105. 从前序与中序遍历序列构造二叉树（Medium）
手撕思路：前序第一个是根；在中序里找到根，左边是左子树，右边是右子树。用哈希表加速找根位置。
复杂度：时间 O(n)，空间 O(n)。
*/
#include <vector>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    unordered_map<int, int> pos;
    TreeNode* build(vector<int>& pre, int pl, int pr, int il, int ir) {
        if (pl > pr) return nullptr;
        int rootVal = pre[pl];
        int k = pos[rootVal];
        int leftSize = k - il;
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(pre, pl + 1, pl + leftSize, il, k - 1);
        root->right = build(pre, pl + leftSize + 1, pr, k + 1, ir);
        return root;
    }
};
