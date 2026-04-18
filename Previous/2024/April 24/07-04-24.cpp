class Solution
{
public:
    bool checkValidString(string s)
    {
        int l = 0;
        int h = 0;
        for (char ch : s)
        {
            switch (ch)
            {
            case '(':
                l += 1;
                h += 1;
                break;
            case ')':
                l = max(0, l -= 1);
                h -= 1;
                break;
            case '*':
                l = max(0, l -= 1);
                h += 1;
                break;
            }
            if (h < 0)
            {
                return false;
            }
        }
        return l == 0;
    }
};