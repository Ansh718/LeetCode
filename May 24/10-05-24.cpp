class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        auto compare = [&](const pair<int, int> &a, const pair<int, int> &b)
        {
            return arr[a.first] * arr[b.second] > arr[a.second] * arr[b.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        for (int i = 1; i < arr.size(); i++)
        {
            pq.push({0, i});
        }
        for (int i = 1; i < k; i++)
        {
            pair<int, int> fraction = pq.top();
            pq.pop();
            if (fraction.first + 1 < fraction.second)
            { 
                pq.push({fraction.first + 1, fraction.second});
            }
        }
        return {arr[pq.top().first], arr[pq.top().second]};
    }
};

1001 1111 1691 1881 1961 6009 6119 6699 6889 6969 8008 8118 8698 8888 8968 9006 9116 9696 9886 9966 