class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < n; i += 3)
        {
            vector<int> temp = {nums[i], nums[i + 1], nums[i + 2]};
            if (temp[2] - temp[0] > k)
            {
                return {};
            }
            result.emplace_back(temp);
        }
        return result;
    }
};