class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int r = 0;
        r = time / (n - 1);
        return ((!(r % 2)) ? (time % (n - 1) + 1) : (n - (time % (n - 1))));
    }
};