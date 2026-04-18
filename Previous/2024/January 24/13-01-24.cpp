class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> freq(26, 0);
        for (char S : s)
        {
            freq[S - 'a']++;
        }
        for (char T : t)
        {
            freq[T - 'a']--;
        }
        int result = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] < 0)
            {
                result += abs(freq[i]);
            }
        }
        return result;
    }
};