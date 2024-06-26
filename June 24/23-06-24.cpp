class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> minDeque, maxDeque;
        int left = 0;
        int maxLength = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right])
            {
                minDeque.pop_back();
            }
            minDeque.push_back(right);
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right])
            {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit)
            {
                ++left;
                if (minDeque.front() < left)
                {
                    minDeque.pop_front();
                }
                if (maxDeque.front() < left)
                {
                    maxDeque.pop_front();
                }
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
