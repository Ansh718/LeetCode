class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int chc)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pr[i][j] = matrix[i][j];
                if (i > 0)
                {
                    pr[i][j] += pr[i - 1][j];
                }
                if (j > 0)
                {
                    pr[i][j] += pr[i][j - 1];
                }
                if (i > 0 and j > 0)
                {
                    pr[i][j] -= pr[i - 1][j - 1];
                }
            }
        }
        int result = 0;
        for (int sx = 0; sx < n; sx++)
        {
            for (int ex = sx; ex < n; ex++)
            {
                for (int sy = 0; sy < m; sy++)
                {
                    for (int ey = sy; ey < m; ey++)
                    {
                        int current = pr[ex][ey];
                        if (sy > 0)
                        {
                            current -= pr[ex][sy - 1];
                        }
                        if (sx > 0)
                        {
                            current -= pr[sx - 1][ey];
                        }
                        if (sx > 0 and sy > 0)
                        {
                            current += pr[sx - 1][sy - 1];
                        }
                        result += current == chc;
                    }
                }
            }
        }
        return result;
    }
};