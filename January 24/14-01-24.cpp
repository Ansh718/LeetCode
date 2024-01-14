class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> h(26, 0);
        vector<int> n(26, 0);
        for (char w1 : word1)
        {
            h[w1 - 'a']++;
        }
        for (char w2 : word2)
        {
            n[w2 - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (h[i] == n[i])
            {
                continue;
            }
            for (int j = i + 1; j < 26; j++)
            {
                if (n[i] == h[j] && h[i] && h[j])
                {
                    swap(h[i], h[j]);
                    break;
                }
            }
        }
        return (h == n);
    }
};