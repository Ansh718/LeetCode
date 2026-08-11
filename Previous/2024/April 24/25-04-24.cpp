class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        unordered_map<char, int> last;
        int n = s.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
        {
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (last.count(c))
                {
                    if (abs(s[i] - c) <= k)
                    {
                        dp[i] = max(dp[i], dp[last[c]] + 1);
                    }
                }
            }
            last[s[i]] = i;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

