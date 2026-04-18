class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int islandCount = 0;
        int rows = 0;
        rows = grid.size();
        int cols = 0;
        cols = grid[0].size();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int rows = 0;
        rows = grid.size();
        int cols = 0;
        cols = grid[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0')
        {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};
