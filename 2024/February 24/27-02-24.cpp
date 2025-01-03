class Solution
{
public:
    int dfs(TreeNode *node, int &answer)
    {
        if (!node)
        {
            return 0;
        }
        int l = dfs(node->left, answer);
        int r = dfs(node->right, answer);
        answer = max(answer, l + r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }
};
