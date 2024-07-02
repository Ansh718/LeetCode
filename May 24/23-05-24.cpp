class Solution
{
public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        return countBeautifulSubsets(nums, k, 0, freq) - 1;
    }

private:
    int countBeautifulSubsets(vector<int> &nums, int k, int index, unordered_map<int, int> &freq)
    {
        if (index == nums.size())
        {
            return 1;
        }
        int count = countBeautifulSubsets(nums, k, index + 1, freq);
        int num = nums[index];
        if (freq[num - k] == 0 && freq[num + k] == 0)
        {
            freq[num]++;
            count += countBeautifulSubsets(nums, k, index + 1, freq);
            freq[num]--;
        }
        return count;
    }
};
