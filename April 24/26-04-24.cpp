class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        for (int i = 1; i < n; i++)
        {
            const vector<pair<int, int>> firstMinSecondMin =
                chc(grid[i - 1]);
            const auto &[firstMinNo, firstMinInd] = firstMinSecondMin[0];
            const auto &[secondMinNo, _] = firstMinSecondMin[1];
            for (int j = 0; j < n; ++j)
                if (j == firstMinInd)
                {
                    grid[i][j] += secondMinNo;
                }
                else
                {
                    grid[i][j] += firstMinNo;
                }
        }
        return ranges::min(grid.back());
    }

private:
    vector<pair<int, int>> chc(const vector<int> &A)
    {
        vector<pair<int, int>> temp;
        for (int i = 0; i < A.size(); i++)
        {
            temp.emplace_back(A[i], i);
        }
        ranges::sort(temp);
        return {temp[0], temp[1]};
    }
};

