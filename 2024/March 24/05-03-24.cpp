class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0;
        int j = 0;
        j = s.length() - 1;
        for (; i < j && s[i] == s[j];)
        {
            char c = s[i];
            while (i <= j && s[i] == c)
            {
                i += 1;
            }
            while (i <= j && s[j] == c)
            {
                j -= 1;
            }
        }
        return j - i + 1;
    }
};