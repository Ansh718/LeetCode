class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> occurrences;
        for (int num : arr)
        {
            occurrences[num]++;
        }
        unordered_set<int> uniqueCounts;
        for (auto &entry : occurrences)
        {
            if (!uniqueCounts.insert(entry.second).second)
            {
                return false;
            }
        }
        return true;
    }
};
