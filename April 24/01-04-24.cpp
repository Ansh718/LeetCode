class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = 0;
        n = s.size() - 1;
        int cnt = 0;
        int i = 0;
        i = n;
        while (s[i] == ' ')
        {
            i--;
        }
        for (; i > -1; i--)
        {
            if (s[i] == ' ')
            {
                return cnt;
            }
            cnt++;
        }
        return cnt;
    }
};