class Solution
{
private:
    bool dfs(int source, int destination, vector<vector<int>> &graph, unordered_set<int> &visited)
    {
        if (source == destination)
        {
            return true;
        }
        visited.insert(source);
        for (int neighbor : graph[source])
        {
            if (visited.find(neighbor) == visited.end() && dfs(neighbor, destination, graph, visited))
            {
                return true;
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph(n);
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        return dfs(source, destination, graph, visited);
    }
};
