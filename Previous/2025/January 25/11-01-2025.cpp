class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        vector<int> freq(26, 0);
        int n = 0;
        n = s.size();
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }
        if (k > n)
        {
            return false;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            cnt += (freq[i] % 2) ? 1 : 0;
        }
        return k >= cnt;
    }
};