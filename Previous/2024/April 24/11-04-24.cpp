// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         stack<char> s;
//         for (char digit : num) {
//             while (!s.empty() && k > 0 && digit < s.top()) {
//                 s.pop();
//                 k--;
//             }
//             s.push(digit);
//         }
//         while (k > 0 && !s.empty()) {
//             s.pop();
//             k--;
//         }
//         string result;
//         while (!s.empty()) {
//             result = s.top() + result;
//             s.pop();
//         }
//         int i = 0;
//         while (i < result.length() && result[i] == '0') {
//             i++;
//         }
//         result = result.substr(i);
//         if (result.empty()) {
//             return "0";
//         }
//         return result;
//     }
// };
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = 0;
        n = num.size();
        if (k == n)
        {
            return "0";
        }
        string result;
        for (char digit : num)
        {
            while (!result.empty() && k > 0 && result.back() > digit)
            {
                result.pop_back();
                k--;
            }
            if (result.empty() && digit == '0')
            {
                continue;
            }
            result.push_back(digit);
        }
        while (k > 0 && !result.empty())
        {
            result.pop_back();
            k--;
        }
        if (result.empty())
        {
            return "0";
        }
        return result;
    }
};
