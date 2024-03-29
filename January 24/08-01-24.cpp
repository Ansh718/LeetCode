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
    void traversal(TreeNode *node, int &result, int low, int high)
    {
        if (!node)
        {
            return;
        }
        if (node->val >= low && node->val <= high)
        {
            result += node->val;
            traversal(node->left, result, low, high);
            traversal(node->right, result, low, high);
        }
        else if (node->val < low)
        {
            traversal(node->right, result, low, high);
        }
        else if (node->val > high)
        {
            traversal(node->left, result, low, high);
        }
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int result = 0;
        traversal(root, result, low, high);
        return result;
    }
};