class Job
{
public:
    int start, end, profit;

    Job(int a, int b, int c)
    {
        start = a;
        end = b;
        profit = c;
    }
};

class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = profit.size();

        vector<Job> job;

        for (int i = 0; i < n; i++)
        {
            Job newJob(startTime[i], endTime[i], profit[i]);
            job.emplace_back(newJob);
        }

        sort(job.begin(), job.end(), [](Job &a, Job &b)
             { return a.start < b.start; });

        vector<int> dP(n + 1, 0);

        for (int i = n - 1; i > -1; i--)
        {
            int t, nt;

            nt = dP[i + 1];

            int l = i; 
            int h = n; 

            while (l < h - 1)
            {
                int mid = l + (h - l) / 2;

                if (job[mid].start >= job[i].end)
                    h = mid;
                else
                    l = mid;
            }

            t = job[i].profit + dP[h];

            dP[i] = max(t, nt);
        }

        return dP[0];
    }
};