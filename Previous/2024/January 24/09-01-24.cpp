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
    void dfs(TreeNode *node, vector<int> &result)
    {
        if (!node->left && !node->right)
        {
            result.push_back(node->val);
        }
        if (node->left)
        {
            dfs(node->left, result);
        }
        if (node->right)
        {
            dfs(node->right, result);
        }
    }
    vector<int> getleafNodes(TreeNode *root)
    {
        vector<int> result;
        if (!root)
        {
            return result;
        }
        dfs(root, result);
        return result;
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leafNodes1 = getleafNodes(root1);
        vector<int> leafNodes2 = getleafNodes(root2);
        if (leafNodes1.size() != leafNodes2.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < leafNodes1.size(); i++)
            {
                if (leafNodes1[i] != leafNodes2[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
};