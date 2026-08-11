class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = 0;
        n = customers.size();
        int totalSatisfied = 0;
        for (int i = 0; i < n; i++)
        {
            if (!grumpy[i])
            {
                totalSatisfied += customers[i];
            }
        }
        int additionalSatisfied = 0;
        for (int i = 0; i < minutes; i++)
        {
            if (grumpy[i])
            {
                additionalSatisfied += customers[i];
            }
        }

        int maxAdditionalSatisfied = 0;
        maxAdditionalSatisfied = additionalSatisfied;
        for (int i = minutes; i < n; i++)
        {
            if (grumpy[i])
            {
                additionalSatisfied += customers[i];
            }
            if (grumpy[i - minutes])
            {
                additionalSatisfied -= customers[i - minutes];
            }
            maxAdditionalSatisfied = max(maxAdditionalSatisfied, additionalSatisfied);
        }
        return totalSatisfied + maxAdditionalSatisfied;
    }
};
