class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; ++i)
        {
            workers.emplace_back(static_cast<double>(wage[i]) / quality[i], quality[i]);
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> maxHeap;
        int sumOfQualities = 0;
        for (auto &[ratio, qual] : workers)
        {
            sumOfQualities += qual;
            maxHeap.push(qual);
            if (maxHeap.size() > k)
            {
                sumOfQualities -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == k)
            {
                double totalWage = ratio * sumOfQualities;
                if (minWage == -1 || totalWage < minWage)
                {
                    minWage = totalWage;
                }
            }
        }
        return minWage;
    }

private:
    double minWage = -1;
};
