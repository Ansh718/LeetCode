class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        map<map<char, int>, vector<string>> mp;
        for (string i : strs)
        {
            map<char, int> temp;
            vector<string> t;
            for (int j = 0; j < i.size(); j++)
            {
                ++temp[i[j]];
            }
            auto it = mp.find(temp);
            if (it == mp.end())
            {
                t.push_back(i);
                mp.insert({temp, t});
            }
            else
            {
                it->second.push_back(i);
            }
        }
        for (auto it = mp.begin();
             it != mp.end(); ++it)
        {
            result.push_back(it->second);
        }
        return result;
    }
};