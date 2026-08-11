class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &A)
    {
        int n = A.size();
        for (int row = n - 2; row >= 0; row--)
        {
            for (int column = 0; column < n; column++)
            {
                int best = A[row + 1][column];
                if (column > 0)
                    best = min(best, A[row + 1][column - 1]);
                if (column + 1 < n)
                    best = min(best, A[row + 1][column + 1]);
                A[row][column] = A[row][column] + best;
            }
        }

        int result = INT_MAX;
        for (int i = 0; i < n; ++i)
            result = min(result, A[0][i]);
        return result;
    }
};