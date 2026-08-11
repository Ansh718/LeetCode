
// class Solution
// {
// public:
//     void helper(int index, vector<int> &nums, int n, vector<vector<int>> &result, vector<int> &temp)
//     {
//         if (index == n)
//         {
//             result.push_back(temp);
//             return;
//         }
//         temp.push_back(nums[index]);
//         helper(index + 1, nums, n, result, temp);
//         temp.pop_back();
//         helper(index + 1, nums, n, result, temp);
//     }
//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         vector<vector<int>> result;
//         vector<int> temp;
//         int n = 0;
//         n = nums.size();
//         helper(0, nums, n, result, temp);
//         return result;
//     }
// };
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int subsetCount = 1 << n;
        vector<vector<int>> result;
        for (int i = 0; i < subsetCount; i++)
        {
            vector<int> subset;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};
