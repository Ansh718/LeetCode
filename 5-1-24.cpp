class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dP(n, 1e5);
        for (int i = 0; i < n; i++)
        {
            int ptr = lower_bound(dP.begin(), dP.end(), nums[i]) - dP.begin();
            if (ptr < n)
            {
                dP[ptr] = min(dP[ptr], nums[i]);
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (dP[i] < 1e5)
            {
                return i + 1;
            }
        }
        return 0;
    }
};
