class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        vector<int> result(n, 0);

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> prioQ;
        priority_queue<long long, vector<long long>, greater<long long>> prioQ2;
        for (int i = 0; i < n; i++)
            prioQ.push({0, i});

        long long time = 0;
        for (int i = 0; i < meetings.size(); i++)
        {
            time = max(time, (long long)meetings[i][0]);

            while (prioQ.size() and time >= prioQ.top().first)
            {
                prioQ2.push(prioQ.top().second);
                prioQ.pop();
            }

            if (prioQ2.empty())
            {
                time = prioQ.top().first;
                while (prioQ.size() and time >= prioQ.top().first)
                {
                    prioQ2.push(prioQ.top().second);
                    prioQ.pop();
                }
            }

            int mt = prioQ2.top();
            prioQ2.pop();

            ++result[mt];
            prioQ.push({time + meetings[i][1] - meetings[i][0], mt});
        }

        int rm = 0;
        int maX = 0;

        for (int i = 0; i < n; i++)
        {
            if (result[i] > maX)
            {
                maX = result[i];
                rm = i;
            }
        }

        return rm;
    }
};