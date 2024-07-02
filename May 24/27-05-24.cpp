class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = 0;
        n = nums.size();
        for (int x = 0; x <= n; x++)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] >= x)
                {
                    count++;
                }
            }
            if (count == x)
            {
                return x;
            }
        }
        return -1;
    }
};