class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> umP;
        for (auto n : nums)
        {
            umP[n]++;
        }
        int s = 0;
        for (auto u : umP)
        {
            s = max(s, u.second);
        }
        vector<vector<int>> result(s);
        for (auto u : umP)
        {
            for (int i = 0; i < u.second; i++)
            {
                result[j].push_back(u.first);
            }
        }
        return result;
    }
};