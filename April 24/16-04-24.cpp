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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode *> q;
        q.push(root);
        int currentDepth = 0;
        currentDepth = 1;
        while (!q.empty())
        {
            int size = 0;
            size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (currentDepth == depth - 1)
                {
                    TreeNode *leftChild = new TreeNode(val);
                    TreeNode *rightChild = new TreeNode(val);
                    leftChild->left = node->left;
                    rightChild->right = node->right;
                    node->left = leftChild;
                    node->right = rightChild;
                }
                else
                {
                    if (node->left)
                    {
                        q.push(node->left);
                    }
                    if (node->right)
                    {
                        q.push(node->right);
                    }
                }
            }
            currentDepth++;
            if (currentDepth == depth)
            {
                break;
            }
        }
        return root;
    }
};
