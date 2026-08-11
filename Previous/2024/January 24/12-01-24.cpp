class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int vowelCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                vowelCount++;
            }
        }
        if (vowelCount % 2)
        {
            return false;
        }
        int halfVowelCount = 0;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                halfVowelCount++;
            }
        }
        return (halfVowelCount == vowelCount / 2);
    }
};