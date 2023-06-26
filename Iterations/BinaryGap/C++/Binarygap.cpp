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
    // ensure positive non-zero input
    if (N <= 1)
    {
        return 0;
    }

    int working_value = N;
    int max_gap = 0;
    int zero_count = -1; // -1 indicates that no complete gap has yet been found

    // check each bit of the input value
    while (working_value > 0)
    {
        // check if the 1 bit is active
        if ((working_value & 1) == 1)
        {
            // if a gap count was in progress, record it if it is longer than the previous highest
            if (zero_count > max_gap)
            {
                max_gap = zero_count;
            }
            // reset the current count
            zero_count = 0;
        }
        else
        {
            // if the 1 bit is NOT active AND the current bit is a zero
            if (zero_count != -1)
            {
                // start or continue the count
                zero_count++;
            }
        }
        // advance to the next bit in the sequence
        working_value = working_value >> 1;
    }

    return max_gap;
}
