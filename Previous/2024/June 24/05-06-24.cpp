class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<string> ans1;
        vector<int> commonCount1(26, INT_MAX);
        for (const string &a1 : A)
        {
            vector<int> count1(26);
            for (char c1 : a1)
            {
                ++count1[c1 - 'a'];
            }
            for (int i = 0; i < 26; ++i)
            {
                commonCount1[i] = min(commonCount1[i], count1[i]);
            }
        }
        for (char c1 = 'a'; c1 <= 'z'; ++c1)
        {
            for (int i = 0; i < commonCount1[c1 - 'a']; ++i)
            {
                ans1.push_back(string(1, c1));
            }
        }
        return ans1;
    }
};