class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int v1 = 0;
        v1 = nums[0];
        if (nums.size() == 1)
        {
            return v1;
        }
        int v2 = 0;
        v2 = max(nums[0], nums[1]);
        if (nums.size() == 2)
        {
            return v2;
        }
        int maX = INT_MIN;
        for (int i = 2; i < nums.size(); i++)
        {
            maX = max(v2, nums[i] + v1);
            v1 = v2;
            v2 = maX;
        }
        return maX;
    }
};