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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> v;
        while (!q.empty())
        {
            int t = 0;
            t = q.size();
            int vg = 0;
            for (int i = 0; i < t; i++)
            {
                TreeNode *tr = q.front();
                q.pop();
                if (vg == 0)
                {
                    v.push_back(tr->val);
                    vg = 1;
                }
                if (tr->left)
                {
                    q.push(tr->left);
                }
                if (tr->right)
                {
                    q.push(tr->right);
                }
            }
        }
        return v.back();
    }
};