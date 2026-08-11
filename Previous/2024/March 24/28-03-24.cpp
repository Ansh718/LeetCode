class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int result = 0;
        unordered_map<int, int> mnums;
        for (int l = 0, r = 0; r < nums.size(); r++)
        {
            mnums[nums[r]]++;
            while (mnums[nums[r]] == k + 1)
            {
                mnums[nums[l++]]--;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};