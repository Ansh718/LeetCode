class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int result = 0;
        int next = 0;
        int n = bank.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int cnt = 0;
            for (auto b : bank[i])
            {
                if (b == '1')
                {
                    cnt++;
                    result += next;
                }
            }
            if (cnt > 0)
            {
                next = cnt;
            }
        }
        return result;
    }
};