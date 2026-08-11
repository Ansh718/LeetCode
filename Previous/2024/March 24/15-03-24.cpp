class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int cnt = 0;
        cnt = count(nums.begin(), nums.end(), 0);
        if (cnt == 1)
        {
            vector<int> res(nums.size(), 0);
            int pro = 0;
            pro = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] != 0)
                {
                    pro *= nums[i];
                }
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    res[i] = pro;
                }
            }
            return res;
        }
        else if (cnt > 1)
        {
            vector<int> res(nums.size(), 0);
            return res;
        }
        else
        {
            vector<int> res(nums.size(), 0);
            vector<int> prefix(nums.size(), 0);
            vector<int> suffix(nums.size(), 0);
            prefix[0] = nums[0];
            suffix[nums.size() - 1] = nums[nums.size() - 1];
            for (int i = 1; i < nums.size(); i++)
            {
                prefix[i] = prefix[i - 1] * nums[i];
            }
            for (int i = nums.size() - 2; i > -1; i--)
            {
                suffix[i] = suffix[i + 1] * nums[i];
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (i == 0)
                {
                    res[i] = suffix[i + 1];
                }
                else if (i == nums.size() - 1)
                {
                    res[i] = prefix[i - 1];
                }
                else
                {
                    res[i] = prefix[i - 1] * suffix[i + 1];
                }
            }
            return res;
        }
    }
};