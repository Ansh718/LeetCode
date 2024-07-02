class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i1 = 0;
        for (const char c1 : s)
            if (c1 == t[i1])
            {
                if (++i1 == t.length())
                {
                    return 0;
                }
            }
        return t.length() - i1;
    }
};