class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> result;
        int m = 0;
        m = land.size();
        int n = 0;
        n = land[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (land[i][j] == 1)
                {
                    int r2 = 0;
                    r2 = i;
                    int c2 = 0;
                    c2 = j;
                    while (r2 < m && land[r2][j] == 1)
                    {
                        c2 = j;
                        while (c2 < n && land[r2][c2] == 1)
                        {
                            land[r2][c2] = 0;
                            c2++;
                        }
                        r2++;
                    }
                    result.push_back({i, j, r2 - 1, c2 - 1});
                }
            }
        }
        return result;
    }
};
