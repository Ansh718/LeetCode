class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int mask = 0;
        for (int num : nums)
        {
            mask ^= num;
        }
        unsigned int umask = static_cast<unsigned int>(mask);
        int distinguishingBit = umask & (-umask);

        int x = 0, y = 0;
        for (int num : nums)
        {
            if (num & distinguishingBit)
            {
                x ^= num;
            }
            else
            {
                y ^= num;
            }
        }

        return {x, y};
    }
};
