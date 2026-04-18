class Solution
{
public:
    int length(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            n /= 10;
            ans++;
        }
        return ans;
    }
    int reverse(int n)
    {
        int len = length(n);
        int fact = len - 1;
        int ans = 0;
        while (n > 0)
        {
            int temp = n % 10;
            ans += temp * (pow(10, fact));
            fact -= 1;
            n /= 10;
        }
        return ans;
    }
    int mirrorDistance(int n)
    {
        return abs(n - reverse(n));
    }
};
