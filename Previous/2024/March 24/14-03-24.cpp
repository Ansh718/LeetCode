class Solution
{
public:
    int atmost(vector<int> &nums, int k)
    {
        if (k < 0)
        {
            return 0;
        }
        int l = 0, cnt = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cnt += nums[i];
            while (cnt > k)
            {
                cnt -= nums[l++];
            }
            res += (i - l + 1);
        }

        return res;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};
