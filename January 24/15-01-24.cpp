class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> result(2);
        vector<int> v1(1e5 + 10, 0);
        vector<int> v2(1e5 + 10, 0);
        for (auto m : matches)
        {
            v1[m[0]] = v1[m[1]] = 1;
            v2[m[1]]++;
        }
        for (int i = 1; i < 1e5 + 10; i++)
        {
            if (v1[i])
            {
                if (v2[i] == 1)
                    result[1].push_back(i);
                else if (v2[i] == 0)
                    result[0].push_back(i);
            }
        }
        return result;
    }
};
