class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int right = 0;
        int left = 0;
        int pro = 0;
        pro = 1;
        int ans = 0;
        int n = 0;
        n = nums.size();
        while (right < n)
        {
            pro *= nums[right];
            while (left <= right && pro >= k)
            {
                pro /= nums[left++];
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};
