class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dP(n);
        for (int i = 0; i < n; i++)
        {
            dP[i] = 0;
        }
        vector<int> r(n);
        for (int i = 0; i < n; i++)
        {
            r[i] = i;
        }
        vector<int> s;
        s.push_back(0);
        for (int i = 1; i < n; i++)
        {
            int current = arr[i];

            while ((s.size() > 0) && (current < arr[s.back()]))
            {
                int index = 0;
                index = s.back();
                s.pop_back();
                r[index] = i;
            }
            s.push_back(i);
        }
        dP[n - 1] = arr[n - 1];
        for (int i = n - 2; i > -1; i--)
        {
            int rightIndex = r[i];
            if (rightIndex == i)
            {
                int current = 0;
                current = (n - i) * arr[i];
                dP[i] = current;
            }
            else
            {
                int uptoSmallIndex = 0;
                uptoSmallIndex = (rightIndex - i) * arr[i];
                int current = 0;
                current = uptoSmallIndex + dP[rightIndex];
                dP[i] = current;
            }
        }
        int resultSum = 0;
        for (int i = 0; i < n; i++)
        {
            resultSum = ((resultSum) % 1000000007 + (dP[i]) % 1000000007) % 1000000007;
        }
        return resultSum;
    }
};