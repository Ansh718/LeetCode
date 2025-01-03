class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        vector<int> end(n, 1);
        vector<int> prev(n, -1);
        int maX = 0;
        int ind = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j > -1; j--)
            {
                if (nums[i] % nums[j] == 0 && end[i] < end[j] + 1)
                {
                    end[i] = end[j] + 1;
                    prev[i] = j;
                }
            }
            if (maX < end[i])
            {
                maX = end[i];
                ind = i;
            }
        }
        while (ind != -1)
        {
            ans.push_back(nums[ind]);
            ind = prev[ind];
        }
        return ans;
    }
};