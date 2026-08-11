class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = 0;
        n = profits.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapital;
        priority_queue<int> maxProfits;
        for (int i = 0; i < n; i++)
        {
            minCapital.push({capital[i], profits[i]});
        }
        int currentCapital = 0;
        currentCapital = w;
        for (int i = 0; i < k; i++)
        {
            while (!minCapital.empty() && minCapital.top().first <= currentCapital)
            {
                maxProfits.push(minCapital.top().second);
                minCapital.pop();
            }
            if (maxProfits.empty())
            {
                break;
            }
            currentCapital += maxProfits.top();
            maxProfits.pop();
        }
        return currentCapital;
    }
};
