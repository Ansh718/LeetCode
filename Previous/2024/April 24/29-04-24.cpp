class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int result = 0;
        result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            result ^= nums[i];
        }
        if (result == k)
        {
            return 0;
        }
        int temp = 0;
        temp = result ^ k;
        int answer = 0;
        answer = __builtin_popcount(temp);
        return answer;
    }
};