class Solution
{
public:
    struct Compare
    {
        bool operator()(pair<char, int> down, pair<char, int> up)
        {
            if (down.second == up.second)
            {
                return down.first < up.first;
            }
            return down.second < up.second;
        }
    };
    string frequencySort(string s)
    {
        unordered_map<char, int> umP;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> minH;
        for (char ch : s)
        {
            umP[ch]++;
        }
        for (auto m : umP)
        {
            minH.push({m.first, m.second});
        }
        string ans = "";
        while (!minH.empty())
        {
            char ch = minH.top().first;
            int freq = minH.top().second;
            minH.pop();
            for (int i = 0; i < freq; i++)
            {
                ans += ch;
            }
        }
        return ans;
    }
};
