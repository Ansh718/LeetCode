class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int dP[n][m][m];

        for (int i = n - 1; i > -1; i--)
        {
            for (int x = 0; x < m; x++)
            {
                for (int y = 0; y < m; y++)
                {
                    dP[i][x][y] = 0;

                    for (int r1 = -1; r1 < 2; r1++)
                    {
                        for (int r2 = -1; r2 < 2; r2++)
                        {
                            if (x + r1 > -1 and x + r1 < m and y + r2 > -1 and y + r2 < m)
                            {
                                int current = grid[i][x];

                                if (x != y)
                                    current += grid[i][y];

                                if (i + 1 < n)
                                {
                                    current += dP[i + 1][x + r1][y + r2];
                                }

                                dP[i][x][y] = max(dP[i][x][y], current);
                            }
                        }
                    }
                }
            }
        }

        return dP[0][0][m - 1];
    }
};