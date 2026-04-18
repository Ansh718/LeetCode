class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();

        vector<unordered_map<int, int>> dP(n);
        unordered_map<long long, vector<int>> position;

        for (int i = 0; i < n; i++)
            position[nums[i]].push_back(i);

        int ans = 0;

        function<int(int, long long)> helper = [&](int temp, long long x) -> int
        {
            if (dP[temp].count(x))
                return dP[temp][x];

            dP[temp][x] = 1;

            long long need = nums[temp] + x;

            int next = lower_bound(position[need].begin(), position[need].end(), temp + 1) - position[need].begin();

            for (int i = next; i < position[need].size(); i++)
            {
                dP[temp][x] += helper(position[need][i], x);
            }

            return dP[temp][x];
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                ans += helper(j, (long long)nums[j] - (long long)nums[i]) - 1;
        }

        return ans;
    }
};