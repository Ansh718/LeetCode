class Solution
{
public:
    int helper(string &ring, string &key, int ptr, int index, vector<vector<int>> &dp)
    {
        int n = 0;
        int m = 0;
        n = ring.size();
        m = key.size();
        if (index >= m)
        {
            return 0;
        }
        if (dp[ptr][index] != -1)
        {
            return dp[ptr][index];
        }
        int result = 0;
        result = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (ring[i] == key[index])
            {
                int d = 0;
                d = min(abs(i - ptr), n - abs(i - ptr)) + 1;
                int nxt = 0;
                nxt = helper(ring, key, i, index + 1, dp);
                result = min(result, d + nxt);
            }
        }
        return dp[ptr][index] = result;
    }
    int findRotateSteps(string ring, string key)
    {
        int ptr = 0;
        int index = 0;
        int n = 0;
        int m = 0;
        n = ring.size();
        m = key.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(ring, key, ptr, index, dp);
    }
};