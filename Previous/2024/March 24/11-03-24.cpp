class Solution
{
public:
    string customSortString(string order, string s)
    {
        string res;
        vector<int> hash(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
        }
        int rescnt = 0;
        for (int i = 0; i < order.size(); i++)
        {
            if (hash[order[i] - 'a'] > 0)
            {
                res.insert(rescnt, hash[order[i] - 'a'], order[i]);
                rescnt += hash[order[i] - 'a'];
                hash[order[i] - 'a'] = 0;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i] - 'a'] > 0)
            {
                res.insert(rescnt, hash[s[i] - 'a'], s[i]);
                rescnt += hash[s[i] - 'a'];
                hash[s[i] - 'a'] = 0;
            }
        }
        return res;
    }
};