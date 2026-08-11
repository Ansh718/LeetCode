class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        map<int, int, greater<int>> mp;
        for (int i = 0; i < score.size(); i++)
        {
            mp[score[i]] = i;
        }

        vector<string> answer(score.size());
        int rank = 1;
        for (auto &entry : mp)
        {
            if (rank == 1)
            {
                answer[entry.second] = "Gold Medal";
            }
            else if (rank == 2)
            {
                answer[entry.second] = "Silver Medal";
            }
            else if (rank == 3)
            {
                answer[entry.second] = "Bronze Medal";
            }
            else
            {
                answer[entry.second] = to_string(rank);
            }
            rank++;
        }

        return answer;
    }
};
