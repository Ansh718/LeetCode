class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int pr1 = 0;
        pr1 = edges[0][0];
        int pr2 = 0;
        pr2 = edges[0][1];
        int pr3 = 0;
        pr3 = edges[1][0];
        int pr4 = 0;
        pr4 = edges[1][1];
        if (pr1 == pr4)
        {
            return pr1;
        }
        if (pr1 == pr3)
        {
            return pr1;
        }
        if (pr2 == pr4)
        {
            return pr2;
        }
        return pr2;
    }
};