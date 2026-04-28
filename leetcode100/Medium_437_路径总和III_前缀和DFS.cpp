/*
LeetCode 437. 路径总和 III（Medium）
手撕思路：树上前缀和。当前前缀为 cur，若之前出现过 cur-target，则从那个祖先后面到当前节点是一条合法路径。
复杂度：时间 O(n)，空间 O(h)。
*/
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
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
private:
    unordered_map<long long, int> prefix;
    int dfs(TreeNode* root, long long cur, int target) {
        if (!root) return 0;
        cur += root->val;
        int ans = prefix[cur - target];
        prefix[cur]++;
        ans += dfs(root->left, cur, target);
        ans += dfs(root->right, cur, target);
        prefix[cur]--;
        return ans;
    }
};
