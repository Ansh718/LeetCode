class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return root->val == 1;
        }
        bool leftValue = evaluateTree(root->left);
        bool rightValue = evaluateTree(root->right);
        if (root->val == 2)
        {
            return leftValue || rightValue;
        }
        else if (root->val == 3)
        {
            return leftValue && rightValue;
        }
        return false;
    }
};
