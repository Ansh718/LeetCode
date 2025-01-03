class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int pos = -1;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                pos = i;
                break;
            }
        }
        if (pos != -1)
        {
            for (int i = 0; i <= pos / 2; i++)
            {
                char temp = word[i];
                word[i] = word[pos - i];
                word[pos - i] = temp;
            }
        }
        return word;
    }
};

