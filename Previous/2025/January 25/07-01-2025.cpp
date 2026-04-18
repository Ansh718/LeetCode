class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> result;
        for (string one : words)
        {
            for (string other : words)
            {
                if (one != other)
                {
                    if (one != other && other.find(one) != string::npos)
                    {
                        result.push_back(one);
                        break;
                    }
                }
            }
        }
        return result;
    }
};