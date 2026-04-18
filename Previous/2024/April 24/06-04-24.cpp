class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> parentheses_stack;
        string result = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                parentheses_stack.push(i);
            }
            else if (s[i] == ')' && !parentheses_stack.empty())
            {
                parentheses_stack.pop();
            }
            else if (s[i] == ')')
            {
                s[i] = ' ';
            }
        }
        while (!parentheses_stack.empty())
        {
            int curIdx = parentheses_stack.top();
            parentheses_stack.pop();
            s[curIdx] = ' ';
        }
        for (char ch : s)
        {
            if (ch != ' ')
            {
                result += ch;
            }
        }

        return result;
    }
};
