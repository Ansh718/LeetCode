class Solution
{
public:
    int missingInteger(vector<int> &arr)
    {
        int i = 0;
        int n = arr.size();
        int sum = arr[0];
        while ((i < (n - 1)) && ((arr[i] + 1) == arr[i + 1]))
        {
            sum += arr[i + 1];
            i++;
        }
        int minMissing = sum;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == minMissing)
            {
                minMissing++;
            }
        }
        return minMissing;
    }
};