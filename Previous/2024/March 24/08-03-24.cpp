class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<int> vl;
        for (auto m : mp)
        {
            vl.push_back(m.second);
        }
        sort(vl.begin(), vl.end(), greater<int>());
        int res = 0;
        res = count(vl.begin(), vl.end(), vl[0]);
        return res * vl[0];
    }
};