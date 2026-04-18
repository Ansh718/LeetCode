class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (const string &token : tokens)
        {
            if (isOperator(token))
            {
                int operand2 = s.top();
                s.pop();
                int operand1 = s.top();
                s.pop();
                int result = performOperation(operand1, operand2, token);
                s.push(result);
            }
            else
            {
                s.push(stoi(token));
            }
        }
        return s.top();
    }

private:
    bool isOperator(const string &token)
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int performOperation(int operand1, int operand2, const string &op)
    {
        if (op == "+")
        {
            return operand1 + operand2;
        }
        else if (op == "-")
        {
            return operand1 - operand2;
        }
        else if (op == "*")
        {
            return operand1 * operand2;
        }
        else if (op == "/")
        {
            return operand1 / operand2;
        }
        return 0;
    }
};