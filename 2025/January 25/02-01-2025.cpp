class Solution
{
public:
    int maxScore(string s)
    {
        int n = 0;
        n = s.size();
        vector<int> prefix0(n, 0);
        vector<int> suffix1(n, 0);
        prefix0[0] = (s[0] == '0') ? 1 : 0;
        for (int i = 1; i < n; i++)
        {
            prefix0[i] = prefix0[i - 1] + (s[i] == '0' ? 1 : 0);
        }
        suffix1[n - 1] = (s[n - 1] == '1') ? 1 : 0;
        for (int i = n - 2; i > -1; i--)
        {
            suffix1[i] = suffix1[i + 1] + (s[i] == '1' ? 1 : 0);
        }
        int result = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            result = max(result, prefix0[i] + suffix1[i + 1]);
        }
        return result;
    }
};