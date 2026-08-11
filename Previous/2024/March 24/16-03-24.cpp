class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int maxLen = 0, count = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                count--;
            }
            else
            {
                count++;
            }
            if (mp.find(count) != mp.end())
            {
                maxLen = max(maxLen, i - mp[count]);
            }
            else
            {
                mp[count] = i;
            }
        }
        return maxLen;
    }
};
