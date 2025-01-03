class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int Mx = -1, mx = -1;
        int s = nums.size();
        for (int r = 0, l = 0; r < s; r++)
        {
            int x = nums[r];
            if (x < minK || x > maxK)
            {
                l = r + 1;
                continue;
            }
            if (x == maxK)
            {
                Mx = r;
            }
            if (x == minK)
            {
                mx = r;
            }
            ans += max((min(Mx, mx) - l + 1), 0);
        }
        return ans;
    }
};