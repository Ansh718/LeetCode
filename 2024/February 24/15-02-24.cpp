class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = 0;
        n = nums.size();
        long long res = 0;
        res = -1;
        long long pref = 0;
        pref = nums[0] + nums[1];
        for (int i = 2; i < n; i++)
        {
            if (pref > nums[i])
            {
                res = max(res, pref + nums[i]);
            }
            pref += nums[i];
        }
        return res;
    }
};