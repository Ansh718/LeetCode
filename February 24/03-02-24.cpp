class Solution
{
public:
    int func(int ind, vector<int> &arr, int k, vector<int> &dp)
    {
        if (ind == arr.size())
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int l = 0;
        int n = 0;
        n = arr.size();
        int maxI = INT_MIN;
        int ans = INT_MIN;
        for (int j = ind; j < min(n, ind + k); j++)
        {
            l++;
            maxI = max(maxI, arr[j]);
            int sum = 0;
            sum = (l * maxI) + func(j + 1, arr, k, dp);
            ans = max(ans, sum);
        }
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = 0;
        n = arr.size();
        vector<int> dp(n, -1);
        return func(0, arr, k, dp);
    }
};