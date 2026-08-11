class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int result = 0;
        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
            {
                result++;
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return result;
    }
};