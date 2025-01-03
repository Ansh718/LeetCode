class UnionFind
{
public:
    vector<int> parent, rank;
    int count;

    UnionFind(int n) : parent(n), rank(n, 1), count(n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unionSets(int u, int v)
    {
        int pu = find(u), pv = find(v);
        if (pu != pv)
        {
            if (rank[pu] > rank[pv])
            {
                parent[pv] = pu;
            }
            else if (rank[pu] < rank[pv])
            {
                parent[pu] = pv;
            }
            else
            {
                parent[pv] = pu;
                rank[pu]++;
            }
            count--;
            return true;
        }
        return false;
    }

    bool connected()
    {
        return count == 1;
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        UnionFind ufAlice(n), ufBob(n), ufCommon(n);
        int edgesAdded = 0;

        for (const auto &edge : edges)
        {
            if (edge[0] == 3)
            {
                if (ufCommon.unionSets(edge[1] - 1, edge[2] - 1))
                {
                    ufAlice.unionSets(edge[1] - 1, edge[2] - 1);
                    ufBob.unionSets(edge[1] - 1, edge[2] - 1);
                    edgesAdded++;
                }
            }
        }

        for (const auto &edge : edges)
        {
            if (edge[0] == 1)
            {
                if (ufAlice.unionSets(edge[1] - 1, edge[2] - 1))
                {
                    edgesAdded++;
                }
            }
        }

        for (const auto &edge : edges)
        {
            if (edge[0] == 2)
            {
                if (ufBob.unionSets(edge[1] - 1, edge[2] - 1))
                {
                    edgesAdded++;
                }
            }
        }

        if (!ufAlice.connected() || !ufBob.connected())
        {
            return -1;
        }

        return edges.size() - edgesAdded;
    }
};
