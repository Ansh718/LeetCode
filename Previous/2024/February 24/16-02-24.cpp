class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        map<int, int> freq;
        for (auto i : arr)
        {
            ++freq[i];
        }
        vector<int> nums;
        for (auto i : freq)
        {
            nums.push_back(i.second);
        }
        sort(nums.begin(), nums.end());
        int result = nums.size();
        for (auto i : nums)
        {
            if (i <= k)
            {
                k -= i;
                --result;
            }
            else
            {
                break;
            }
        }
        return result;
    }
};