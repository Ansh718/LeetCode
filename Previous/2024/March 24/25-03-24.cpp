class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;
        map<int, int> mpp;
        for (int n : nums)
        {
            mpp[n]++;
        }
        for (auto m : mpp)
        {
            if (m.second == 2)
            {
                result.push_back(m.first);
            }
        }
        return result;
    }
};