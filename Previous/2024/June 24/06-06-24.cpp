class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
        {
            return false;
        }

        unordered_map<int, int> countMap;
        for (int card : hand)
        {
            countMap[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const auto &entry : countMap)
        {
            minHeap.push(entry.first);
        }

        while (!minHeap.empty())
        {
            int first = minHeap.top();
            for (int i = 0; i < groupSize; i++)
            {
                int card = first + i;
                if (countMap[card] == 0)
                {
                    return false;
                }
                countMap[card]--;
                if (countMap[card] == 0)
                {
                    if (card != minHeap.top())
                    {
                        return false;
                    }
                    minHeap.pop();
                }
            }
        }

        return true;
    }
};
