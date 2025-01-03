class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> count_map;
        count_map[0] = 1;
        int prefix_sum = 0;
        int result = 0;

        for (int num : nums)
        {
            if (num % 2 == 1)
            {
                prefix_sum++;
            }
            if (count_map.find(prefix_sum - k) != count_map.end())
            {
                result += count_map[prefix_sum - k];
            }
            count_map[prefix_sum]++;
        }
        return result;
    }
};