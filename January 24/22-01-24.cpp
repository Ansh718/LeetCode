class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        long long int sum = ((nums.size()) * (nums.size() + 1)) / 2;
        long long int sumsq = ((nums.size()) * (nums.size() + 1) * (2 * nums.size() + 1) / 6);
        for (int i = 0; i < nums.size(); i++)
        {
            sum -= nums[i];
            sumsq -= pow(nums[i], 2);
        }
        vector<int> res;
        long long int p = ((sumsq / sum) - sum) / 2;
        long long int q = ((sumsq / sum) + sum) / 2;
        res.push_back(p);
        res.push_back(q);
        return res;
    }
};