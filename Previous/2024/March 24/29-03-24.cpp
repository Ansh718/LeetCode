class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        const int maX = ranges::max(nums);
        long long result = 0;
        int cnt = 0;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            if (nums[right] == maX)
            {
                cnt++;
            }
            while (cnt == k)
            {
                if (nums[left++] == maX)
                {
                    cnt--;
                }
            }
            result += left;
        }
        return result;
    }
};