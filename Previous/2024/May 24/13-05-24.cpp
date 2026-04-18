class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int rows = 0;
        rows = grid.size();
        int cols = 0;
        cols = grid[0].size();
        for (int i = 0; i < rows; ++i)
        {
            if (grid[i][0] == 0)
            {
                toggleRow(grid, i);
            }
        }
        for (int j = 1; j < cols; ++j)
        {
            int countOnes = 0;
            for (int i = 0; i < rows; ++i)
            {
                countOnes += grid[i][j];
            }
            if (countOnes < (rows + 1) / 2)
            {
                toggleColumn(grid, j);
            }
        }
        int score = 0;
        for (int i = 0; i < rows; ++i)
        {
            int rowScore = 0;
            for (int j = 0; j < cols; ++j)
            {
                rowScore = rowScore * 2 + grid[i][j];
            }
            score += rowScore;
        }

        return score;
    }

private:
    void toggleRow(vector<vector<int>> &grid, int row)
    {
        for (int j = 0; j < grid[row].size(); ++j)
        {
            grid[row][j] ^= 1;
        }
    }
    void toggleColumn(vector<vector<int>> &grid, int col)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            grid[i][col] ^= 1;
        }
    }
};
