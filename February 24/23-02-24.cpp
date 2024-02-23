class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (const vector<int> &flight : flights)
        {
            const int a = flight[0];
            const int b = flight[1];
            const int c = flight[2];
            graph[a].emplace_back(b, c);
        }
        return dijkstra(graph, src, dst, k);
    }

private:
    int dijkstra(const vector<vector<pair<int, int>>> &graph, int src, int dst,
                 int k)
    {
        vector<vector<int>> temp(graph.size(), vector<int>(k + 2, INT_MAX));
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<>> minH;
        temp[src][k + 1] = 0;
        minH.emplace(temp[src][k + 1], src, k + 1);
        while (!minH.empty())
        {
            const auto [d, a, stp] = minH.top();
            minH.pop();
            if (a == dst)
            {
                return d;
            }
            if (stp == 0)
            {
                continue;
            }
            for (const auto &[b, c] : graph[a])
                if (d + c < temp[b][stp - 1])
                {
                    temp[b][stp - 1] = d + c;
                    minH.emplace(temp[b][stp - 1], b, stp - 1);
                }
        }
        return -1;
    }
};