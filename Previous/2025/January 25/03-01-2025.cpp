class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = 0;
        n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = q; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (prefix[i] >= prefix[n - 1] - prefix[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};