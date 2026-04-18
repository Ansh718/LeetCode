/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        int result = 0;
        map<TreeNode *, int> ht;
        ht[nullptr] = 0;

        function<int(TreeNode *)> dfs1 = [&](TreeNode *node) -> int
        {
            if (!node)
                return -1;

            int left = dfs1(node->left);
            int right = dfs1(node->right);

            return ht[node] = max(left, right) + 1;
        };

        function<void(TreeNode *, int)> dfs2 = [&](TreeNode *node, int prev)
        {
            if (!node)
                return;

            if (node->val == start)
            {
                result = max(prev, ht[node]);
                return;
            }

            int left = (node->left) ? ht[node->left] + 1 : 0;
            int right = (node->right) ? ht[node->right] + 1 : 0;

            dfs2(node->left, 1 + max(prev, right));
            dfs2(node->right, 1 + max(prev, left));
        };

        dfs1(root);
        dfs2(root, 0);

        return result;
    }
};