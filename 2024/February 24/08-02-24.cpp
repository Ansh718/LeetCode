class Solution
{
public:
    int numSquares(int N)
    {
        if (isPerfectSquare(N))
        {
            return 1;
        }
        while (N % 4 == 0)
        {
            N /= 4;
        }
        if (N % 8 == 7)
        {
            return 4;
        }
        for (int i = 1; i * i < N + 1; ++i)
        {
            if (isPerfectSquare(N - i * i))
            {
                return 2;
            }
        }
        return 3;
    }

private:
    bool isPerfectSquare(int n)
    {
        int sqrtN = sqrt(n);
        return sqrtN * sqrtN == n;
    }
};