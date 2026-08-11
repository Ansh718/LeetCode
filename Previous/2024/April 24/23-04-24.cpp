class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
        {
            return {0};
        }
        vector<unordered_set<int>> adj_list(n);
        for (const auto &edge : edges)
        {
            adj_list[edge[0]].insert(edge[1]);
            adj_list[edge[1]].insert(edge[0]);
        }
        queue<int> leaves;
        for (int i = 0; i < n; ++i)
        {
            if (adj_list[i].size() == 1)
            {
                leaves.push(i);
            }
        }
        while (n > 2)
        {
            int leaves_count = leaves.size();
            n -= leaves_count;
            for (int i = 0; i < leaves_count; ++i)
            {
                int leaf = leaves.front();
                leaves.pop();
                int neighbor = *(adj_list[leaf].begin());
                adj_list[neighbor].erase(leaf);
                if (adj_list[neighbor].size() == 1)
                {
                    leaves.push(neighbor);
                }
            }
        }
        vector<int> result;
        while (!leaves.empty())
        {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};
