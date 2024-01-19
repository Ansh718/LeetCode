class Solution
{
public:
    int climbStairs(int n)
    {
        long long int result = 0;
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        long long int f0 = 1;
        long long int f1 = 2;
        for (int i = 2; i < n; i++)
        {
            result = f0 + f1;
            f0 = f1;
            f1 = result;
        }
        return result;
    }
