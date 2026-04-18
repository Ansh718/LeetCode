class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && temperatures[s.top()] < temperatures[i])
            {
                answer[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return answer;
    }
};