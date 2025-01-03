class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        int M = 1000000007;
        if (k > n * (n - 1) / 2 || k < 0)
        {
            return 0;
        }
        vector<vector<long long>> dP(n + 1, vector<long long>(k + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            dP[i][0] = 1;
            if (i + 1 <= n)
            {
                dP[i + 1][0] = 1;
            }
            for (int j = 1; j <= min(k, i * (i - 1) / 2); j++)
            {
                dP[i][j] = dP[i][j - 1] + dP[i - 1][j];
                if (j >= i)
                {
                    dP[i][j] -= dP[i - 1][j - i];
                }
                dP[i][j] = (dP[i][j] + M) % M;
            }
        }
        return (int)dP[n][k];
    }
};