class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = 0;
        n = s.size();
        int cnt = 0;
        for (char x = 'a'; x <= 'z'; x++)
        {
            int f = 0;
            f = -1;
            int l = 0;
            l = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == x)
                {
                    if (f == -1)
                    {
                        f = i;
                    }
                    l = i;
                }
            }
            if (f != -1 && l - f > 1)
            {
                unordered_set<char> us;
                for (int i = f + 1; i < l; i++)
                {
                    us.insert(s[i]);
                }
                cnt += us.size();
            }
        }
        return cnt;
    }
};