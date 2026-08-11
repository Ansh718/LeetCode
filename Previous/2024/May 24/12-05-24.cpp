class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        vector<vector<int>> result(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                for (int k = i; k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {
                        result[i][j] = max(result[i][j], grid[k][l]);
                    }
                }
            }
        }
        return result;
    }
};