class Solution
{
public:
    void dfs(vector<bool> &visited, vector<vector<int>> &graph, int temp)
    {
        visited[temp] = true;
        for (auto child : graph[node])
        {
            if (!visited[child])
            {
                dfs(visited, graph, child);
            }
        }
    }
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = 0;
        n = nums.size();
        vector<vector<int>> graph(n);
        int maX = 0;
        maX = *max_element(nums.begin(), nums.end()) + 1;
        vector<vector<int>> hash(maX);
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]].push_back(i);
        }
        for (int i = 2; i < maX; i++)
        {
            vector<int> current;
            for (int j = i; j < maX; j += i)
            {
                for (auto x : hash[j])
                {
                    current.push_back(x);
                }
            }
            for (int j = 1; j < current.size(); j++)
            {
                graph[current[j]].push_back(current[j - 1]);
                graph[current[j - 1]].push_back(current[j]);
            }
        }
        vector<bool> visited(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cnt += 1;
                dfs(visited, graph, i);
            }
        }
        return cnt == 1;
    }
};