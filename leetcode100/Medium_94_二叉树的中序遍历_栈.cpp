/*
LeetCode 94. 二叉树的中序遍历（Medium）
手撕思路：中序是左-根-右。用栈模拟递归：一路向左入栈，弹出访问，再去右子树。
复杂度：时间 O(n)，空间 O(h)。
*/
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};
