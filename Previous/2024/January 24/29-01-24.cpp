class MyQueue
{
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void transferStacks()
    {
        // Transfer elements from inputStack to outputStack
        while (!inputStack.empty())
        {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        inputStack.push(x);
    }

    int pop()
    {
        // If outputStack is empty, transfer elements from inputStack
        if (outputStack.empty())
        {
            transferStacks();
        }
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }

    int peek()
    {
        // If outputStack is empty, transfer elements from inputStack
        if (outputStack.empty())
        {
            transferStacks();
        }
        return outputStack.top();
    }

    bool empty()
    {
        return inputStack.empty() && outputStack.empty();
    }
};