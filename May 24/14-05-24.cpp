class Solution
{
public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int maxGold = 0;
        int rows = 0;
        rows = grid.size();
        int cols = 0;
        cols = grid[0].size();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] > 0)
                {
                    maxGold = max(maxGold, dfs(grid, i, j, 0));
                }
            }
        }

        return maxGold;
    }

private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>> &grid, int x, int y, int currentGold)
    {
        int originalGold = grid[x][y];
        currentGold += originalGold;
        grid[x][y] = 0;

        int maxCollected = 0;
        maxCollected = currentGold;

        for (auto dir : directions)
        {
            int nx = 0;
            nx = x + dir.first;
            int ny = 0;
            ny = y + dir.second;
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] > 0)
            {
                maxCollected = max(maxCollected, dfs(grid, nx, ny, currentGold));
            }
        }

        grid[x][y] = originalGold;
        return maxCollected;
    }
};
