class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.empty())
        {
            return true;
        }
        if (board.empty() || board[0].empty())
        {
            return false;
        }
        int m = 0;
        m = board.size();
        int n = 0;
        n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, 0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, const string &word, int index, int i, int j)
    {
        if (index == word.size())
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '*';
        bool found = dfs(board, word, index + 1, i + 1, j) ||
                     dfs(board, word, index + 1, i - 1, j) ||
                     dfs(board, word, index + 1, i, j + 1) ||
                     dfs(board, word, index + 1, i, j - 1);
        board[i][j] = temp;
        return found;
    }
};
