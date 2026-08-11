class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<int> result(n);
        vector<int> cnt(n, 1);
        vector<unordered_set<int>> figure(n);
        for (const vector<int> &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            figure[u].insert(v);
            figure[v].insert(u);
        }
        postOrd(figure, 0, -1, cnt, result);
        preOrd(figure, 0, -1, cnt, result);
        return result;
    }

private:
    void postOrd(const vector<unordered_set<int>> &figure, int node, int parent,
                   vector<int> &cnt, vector<int> &result)
    {
        for (const int child : figure[node])
        {
            if (child == parent)
            {
                continue;
            }
            postOrd(figure, child, node, cnt, result);
            cnt[node] += cnt[child];
            result[node] += result[child] + cnt[child];
        }
    }

    void preOrd(const vector<unordered_set<int>> &figure, int node, int parent,
                  vector<int> &cnt, vector<int> &result)
    {
        for (const int child : figure[node])
        {
            if (child == parent)
            {
                continue;
            }
            result[child] = result[node] - cnt[child] + (figure.size() - cnt[child]);
            preOrd(figure, child, node, cnt, result);
        }
    }
};