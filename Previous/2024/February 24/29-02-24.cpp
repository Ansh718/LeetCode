class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            vector<int> temp;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            if (!isLevelValid(temp, level))
            {
                return false;
            }
            level++;
        }
        return true;
    }
    bool isLevelValid(const vector<int> &temp, int level)
    {
        if (level % 2 == 0)
        {
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] % 2 != 1 || (i > 0 && temp[i] <= temp[i - 1]))
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] % 2 != 0 || (i > 0 && temp[i] >= temp[i - 1]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
