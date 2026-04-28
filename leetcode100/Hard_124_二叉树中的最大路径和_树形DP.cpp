/*
LeetCode 124. 二叉树中的最大路径和（Hard）

手撕思路：
1. 路径可以从任意节点开始和结束，但必须沿父子边走，不能分叉后再往上返回多次。
2. 对每个节点，递归函数返回“从当前节点向父节点延伸时，最多能贡献多少”。
   - 向上只能选左边或右边其中一条路。
   - 如果子树贡献是负数，不如不要，按 0 处理。
3. 但用当前节点作为路径最高点时，可以同时连接左贡献和右贡献：left + root + right。
4. 用全局 ans 记录所有节点作为最高点时的最大路径和。

复杂度：时间 O(n)，空间 O(h)，h 是树高。
*/
#include <algorithm>
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;

        int leftGain = max(0, dfs(root->left, ans));
        int rightGain = max(0, dfs(root->right, ans));

        // 当前节点作为路径最高点：左边接上来 + 当前节点 + 右边接上来。
        ans = max(ans, leftGain + root->val + rightGain);

        // 返回给父节点时只能选一条边继续向上。
        return root->val + max(leftGain, rightGain);
    }
};
