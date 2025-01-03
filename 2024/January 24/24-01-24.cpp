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
    int result;
    bool chc(vector<int> &v)
    {
        int odd = 0;
        for (auto V : v)
        {
            odd += (V & 1);
        }
        return odd == 0 || odd == 1;
    }
    void dfs(TreeNode *node, vector<int> &v)
    {
        if (node == NULL)
        {
            return;
        }
        v[node->val]++;
        if (node->left == NULL && node->right == NULL)
        {
            if (chc(v))
            {
                result++;
            }
            v[node->val]--;
            return;
        }
        dfs(node->left, v);
        dfs(node->right, v);
        v[node->val]--;
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        result = 0;
        vector<int> freq(10);
        dfs(root, freq);
        return result;
    }
};