class Solution
{
private:
    int dp[52][52][52];
    int mod = 1e9 + 7;

public:
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (startRow >= m || startRow < 0 || startColumn >= n || startColumn < 0)
        {
            return 1;
        }
        if (maxMove == 0)
        {
            return 0;
        }
        if (dp[startRow][startColumn][maxMove] != -1)
        {
            return dp[startRow][startColumn][maxMove];
        }
        long long down = findPaths(m, n, maxMove - 1, startRow + 1, startColumn);
        long long up = findPaths(m, n, maxMove - 1, startRow - 1, startColumn);
        long long right = findPaths(m, n, maxMove - 1, startRow, startColumn + 1);
        long long left = findPaths(m, n, maxMove - 1, startRow, startColumn - 1);
        return dp[startRow][startColumn][maxMove] = (((down + up) % mod + right) % mod + left) % mod;
    }
};