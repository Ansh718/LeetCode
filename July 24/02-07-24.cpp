
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_multiset<int> multiset1(nums1.begin(), nums1.end());
        vector<int> result;
        for (int num : nums2)
        {
            auto it = multiset1.find(num);
            if (it != multiset1.end())
            {
                result.push_back(num);
                multiset1.erase(it);
            }
        }
        return result;
    }
};
