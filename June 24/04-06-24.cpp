class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> charCount;
        for (char c : s)
        {
            charCount[c]++;
        }
        int result = 0;
        bool hasOdd = false;
        for (const auto &pair : charCount)
        {
            if (pair.second % 2 == 0)
            {
                result += pair.second;
            }
            else
            {
                result += pair.second - 1;
                hasOdd = true;
            }
        }
        if (hasOdd)
        {
            result += 1;
        }
        return result;
    }
};
