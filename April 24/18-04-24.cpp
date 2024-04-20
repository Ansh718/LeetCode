class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0;
        int rows = 0;
        rows = grid.size();
        int cols = 0;
        cols = grid[0].size();
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        int ni = 0;
                        ni = i + dx[k];
                        int nj = 0;
                        nj = j + dy[k];
                        if (ni < 0 || ni >= rows || nj < 0 || nj >= cols || grid[ni][nj] == 0)
                        {
                            perimeter++;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};
