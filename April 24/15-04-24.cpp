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
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }

    int dfs(TreeNode *node, int currentSum)
    {
        if (!node)
        {
            return 0;
        }
        currentSum = currentSum * 10 + node->val;
        if (!node->left && !node->right)
        {
            return currentSum;
        }
        int leftSum = 0;
        leftSum = dfs(node->left, currentSum);
        int rightSum = 0;
        rightSum = dfs(node->right, currentSum);
        return leftSum + rightSum;
    }
};