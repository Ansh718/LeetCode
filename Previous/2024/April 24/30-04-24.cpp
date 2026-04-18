class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long count = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        int mask = 0;
        for (char c : word)
        {
            int bit = c - 'a';
            mask ^= (1 << bit);
            count += freq[mask];
            for (int i = 0; i < 10; ++i)
            {
                int target_mask = mask ^ (1 << i);
                count += freq[target_mask];
            }
            freq[mask]++;
        }
        return count;
    }
};
