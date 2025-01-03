class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int chc = 0;
        int i = 0;
        int j = 0;
        int n = 0;
        int m = 0;
        n = nums1.size();
        m = nums2.size();
        while (i < n && j < m)
        {
            if (nums1[i] > nums2[j])
            {
                i += 1;
            }
            else if (nums2[j] > nums1[i])
            {
                j += 1;
            }
            else
            {
                chc = 1;
                break;
            }
        }
        if (chc == 0)
        {
            return -1;
        }
        return nums1[i];
    }
};