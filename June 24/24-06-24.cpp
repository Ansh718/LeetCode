class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int K)
    {
        vector<int> prefix(nums.size());
        for (int i = 0; i < nums.length() - K + 1; i++)
        {
            int flips = 0;
            if (i > 0)
            {
                flips = prefix[i - 1];
            }
            int eflips = 0;
            eflips = flips;
            if (i - K > -1)
            {
                eflips -= prefix[i - K];
            }
            if (nums[i] == 0)
            {
                if (!(eflips % 2))
                {
                    flips += 1;
                }
            }
            else
            {
                if (flips % 2)
                {
                    flips += 1;
                }
            }
            prefix[i] = flips;
        }
        for (int i = nums.size() - K + 1; i < nums.size(); i++)
        {
            int flips = 0;
            if (i > 0)
            {
                flips = prefix[i - 1];
            }
            int eflips = 0;
            eflips = flips;
            if (i - K > -1)
            {
                eflips -= prefix[i - K];
            }
            if (nums[i] == 0)
            {
                if (!(eflips % 2))
                {
                    return -1;
                }
            }
            else
            {
                if (flips % 2)
                {
                    return -1;
                }
            }
            prefix[i] = flips;
        }
        return prefix[nums.size() - 1];
    }
};