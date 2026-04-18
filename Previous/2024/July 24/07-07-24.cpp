class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int answer = 0;
        answer = numBottles;
        while (numBottles >= numExchange)
        {
            int temp = numBottles / numExchange;
            answer += temp;
            numBottles = numBottles % numExchange + temp;
        }
        return answer;
    }
};