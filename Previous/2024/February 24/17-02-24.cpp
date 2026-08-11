class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> minH;
        for (int i = 1; i < heights.size(); ++i)
        {
            const int d = heights[i] - heights[i - 1];
            if (d <= 0)
            {
                continue;
            }
            minH.push(d);
            if (minH.size() > ladders)
            {
                bricks -= minH.top();
                minH.pop();
            }
            if (bricks < 0)
            {
                return i - 1;
            }
        }
        return heights.size() - 1;
    }
};