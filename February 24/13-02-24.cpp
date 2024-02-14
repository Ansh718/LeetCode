class Solution
{
public:
    bool isP(string word)
    {
        for (int i = 0; i < (word.size()) / 2; i++)
        {
            if (word[i] != word[word.size() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            if (isP(words[i]))
            {
                return words[i];
            }
        }
        return "";
    }
};