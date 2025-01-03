class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long sum = 0;
        int i = 0;
        int check = 0;
        while (k > 0)
        {
            long long chc = 0;
            chc = (long long)happiness[i] - check;
            if (chc > 0)
            {
                sum = sum + chc;
            }
            check += 1;
            i += 1;
            k -= 1;
        }
        return sum;
    }
};
