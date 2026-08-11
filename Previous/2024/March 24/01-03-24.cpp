class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        string res = s;
        int cnt1 = 0;
        for (char c : s)
        {
            if (c == '1')
            {
                cnt1++;
            }
        }
        if (cnt1 == 0)
        {
            return s;
        }
        res[s.size() - 1] = '1';
        cnt1--;
        for (int i = 0; i < cnt1; i++)
        {
            res[i] = '1';
        }
        for (int i = cnt1; i < s.size() - 1; i++)
        {
            res[i] = '0';
        }
        return res;
    }
};
