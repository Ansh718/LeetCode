class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> p;
        vector<int> n;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                n.push_back(nums[i]);
            }
            else
            {
                p.push_back(nums[i]);
            }
        }
        while (!n.empty() || !p.empty())
        {
            if (!n.empty())
            {
                result.push_back(n.back());
                n.pop_back();
            }
            if (!p.empty())
            {
                result.push_back(p.back());
                p.pop_back();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
