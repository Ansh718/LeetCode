class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> degree(n, 0);
        for (const auto &road : roads)
        {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        vector<pair<int, int>> degree_city;
        for (int i = 0; i < n; i++)
        {
            degree_city.push_back({degree[i], i});
        }
        sort(degree_city.begin(), degree_city.end(), greater<pair<int, int>>());
        vector<int> importance_values(n);
        for (int i = 0; i < n; i++)
        {
            importance_values[degree_city[i].second] = n - i;
        }
        long long total_importance = 0;
        for (const auto &road : roads)
        {
            total_importance += (importance_values[road[0]] + importance_values[road[1]]);
        }

        return total_importance;
    }
};