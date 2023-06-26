#include <iostream>

using namespace std;

int solution(int N);

int main()
{
    int input = 1041;
    cout << "Given input: " << input << endl;
    cout << "Max BindaryGap is: " << solution(input) << endl;
}

int solution(int N)
{
    if (N <= 1)
    {
        return 0;
    }

    if (N > 2147483647)
    {
        return 0;
    }

    int working_value = N;
    int max_gap = 0;
    int zero_count = -1;

    while (working_value > 0)
    {
        if ((working_value & 1) == 1)
        {
            if (zero_count > max_gap)
            {
                max_gap = zero_count;
            }
            zero_count = 0;
        }
        else
        {
            if (zero_count != -1)
            {
                zero_count++;
            }
        }
        working_value = working_value >> 1;
    }
    return max_gap;
}
