class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        vector<bitset<26>> dp = {bitset<26>()};
        int result = 0;
        for (auto ar : arr)
        {
            bitset<26> temp;
            for (char c : ar)
            {
                temp.set(c - 'a');
            }
            int n = temp.count();
            if (n < ar.size())
            {
                continue;
            }
            for (int i = dp.size() - 1; i >= 0; --i)
            {
                bitset<26> c = dp[i];
                if ((c & temp).any())
                {
                    continue;
                }
                dp.push_back(c | temp);
                result = max(result, (int)c.count() + n);
            }
        }
        return result;
    }
};