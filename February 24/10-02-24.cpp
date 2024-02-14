class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        vector<vector<int>> isp(n, vector<int>(n, 0));
        int res = 0;
        for (int i = n - 1; i > -1; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    isp[i][j] = 1;
                    ++res;
                }
                else
                {
                    if (s[i] == s[j] and (i == j - 1 or isp[i + 1][j - 1]))
                    {
                        isp[i][j] = 1;
                        ++res;
                    }
                }
            }
        }
        return res;
    }
};