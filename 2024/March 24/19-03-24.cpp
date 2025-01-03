class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> taskCounts;
        for (char task : tasks)
        {
            taskCounts[task]++;
        }
        int maxCount = 0;
        for (auto &entry : taskCounts)
        {
            maxCount = max(maxCount, entry.second);
        }
        int numMaxTasks = 0;
        for (auto &entry : taskCounts)
        {
            if (entry.second == maxCount)
            {
                numMaxTasks++;
            }
        }
        int minIntervals = 0;
        minIntervals = (maxCount - 1) * (n + 1) + numMaxTasks;
        return max(minIntervals, static_cast<int>(tasks.size()));
    }
};