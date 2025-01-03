class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int result = 0;
        int score = 0;
        int ind = 0;
        int chc = tokens.size() - 1;
        sort(tokens.begin(), token.end());
        while (ind <= chc && (power >= tokens[ind] || score))
        {
            while (ind <= chc && power >= tokens[ind])
            {
                power -= tokens[ind++];
                score += 1;
            }
            result = max(result, score);
            if (ind <= chc && score)
            {
                power += tokens[chc--];
                score -= 1;
            }
        }
        return result;
    }
};