class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = 0;
        n = s.size();
        vector<int> delta(n + 1, 0);
        for (auto &shift : shifts)
        {
            int start = 0;
            start = shift[0];
            int end = 0;
            end = shift[1];
            int dir = 0;
            dir = shift[2];
            if (dir == 0)
            {
                delta[start] -= 1;
                delta[end + 1] += 1;
            }
            else
            {
                delta[start] += 1;
                delta[end + 1] -= 1;
            }
        }
        int cumulative = 0;
        for (int i = 0; i < n; i++)
        {
            cumulative += delta[i];
            int shift = (s[i] - 'a' + cumulative) % 26;
            if (shift < 0)
            {
                shift += 26;
            }
            s[i] = 'a' + shift;
        }
        return s;
    }
};