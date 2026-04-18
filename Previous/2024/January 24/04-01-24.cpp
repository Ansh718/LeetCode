class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int result = 0;
        unordered_map<int, int> umP;
        for (auto n : nums)
        {
            umP[n]++;
        }
        for (auto u : umP)
        {
            if (u.second % 3 == 0)
            {
                result += u.second / 3;
            }
            else if (u.second % 3 == 2)
            {
                result++;
                result += (u.second - 2) / 3;
            }
            else
            {
                if (u.second == 1)
                {
                    return -1;
                }
                result += 2;
                result += (u.second - 4) / 3;
            }
        }
        return result;
    }
};