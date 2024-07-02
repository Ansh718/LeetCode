class Solution
{
public:
    bool canMakeBouquets(vector<int> &bloomDay, int m, int k, int days)
    {
        int bouquets = 0;
        int flowers = 0;
        for (int bloom : bloomDay)
        {
            if (bloom <= days)
            {
                flowers++;
                if (flowers == k)
                {
                    bouquets++;
                    flowers = 0;
                }
            }
            else
            {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = 0;
        n = bloomDay.size();
        if ((long long)m * k > n)
        {
            return -1;
        }
        int left = 0;
        left = 1;
        int right = 0;
        right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right)
        {
            int mid = 0;
            mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};