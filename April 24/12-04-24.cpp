class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int n = 0;
        n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], arr[i]);
        }
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], arr[i]);
        }
        int trap = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int val = 0;
            val = min(left[i - 1], right[i + 1]);
            if (val > arr[i])
            {
                trap += val - arr[i];
            }
        }
        return trap;
    }
};