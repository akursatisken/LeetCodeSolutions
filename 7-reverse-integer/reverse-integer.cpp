class Solution {
public:
    int reverse(int x) {
    
    if(x == 0 || x == INT_MIN)
        return 0;

    int dump = abs(x);
    queue<int> queue;
    while (dump > 0)
    {
        queue.push(dump % 10);
        dump /= 10;
    }

    string temp;

    while (!queue.empty())
    {
        temp += to_string(queue.front());
        queue.pop();
    }
    int result;
    if (x < 0)
    {
        try {

            result = stoi(temp) * -1;
        }
        catch (const std::out_of_range& e) {
            result = 0;
        }
    }
    else
    {
        try {

            result = stoi(temp);
        }
        catch (const std::out_of_range& e) {
            result = 0;
        }
    }

    return result;
    }


};