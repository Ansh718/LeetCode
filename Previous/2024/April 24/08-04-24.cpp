class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        map<int, int> mp;
        for (auto s : students)
        {
            mp[s] += 1;
        }
        int cnt = 0;
        for (auto s : sandwiches)
        {
            if (mp[s] == 0)
            {
                return sandwiches.size() - cnt;
            }
            cnt += 1;
            mp[s] -= 1;
        }
        return 0;
    }
};