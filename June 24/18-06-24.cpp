class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<pair<int, int>> jobs;
        int n = difficulty.size();
        for (int i = 0; i < n; i++)
        {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int maxProfit = 0;
        int result = 0;
        int i = 0;
        for (int ability : worker)
        {
            while (i < n && ability >= jobs[i].first)
            {
                maxProfit = max(maxProfit, jobs[i].second);
                i++;
            }
            result += maxProfit;
        }
        return result;
    }
};
