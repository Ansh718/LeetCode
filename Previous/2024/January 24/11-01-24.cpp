class Solution
{
public:
    int maxAncestorDiff(TreeNode *root)
    {
        int result = 0;
        const int inF = 1e6;

        helper(root, result, inF);

        return result;
    }

private:
    pair<int, int> helper(TreeNode *node, int &result, const int &inF)
    {
        if (!node)
            return {inF, -inF};

        pair<int, int> left = helper(node->left, result, inF);
        pair<int, int> right = helper(node->right, result, inF);

        int miN = min(left.first, right.first);
        int maX = max(left.second, right.second);

        if (node->left || node->right)
        {
            result = max({result, abs(miN - node->val), abs(maX - node->val)});
        }

        return {min(miN, node->val), max(maX, node->val)};
    }
};
