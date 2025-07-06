#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A);

int main()
{
    // vector<int> input = { 1, 3, 6, 4, 1, 2 };
    // vector<int> input = { 1, 2, 3 };
    // vector<int> input = { -1, -3 };
    vector<int> input = { 1, 3, 6, 4, 1, 2, -7, -13, 10, 0 };

    int output_value = solution(input);
    cout << "Output Value: " << output_value << endl;
}

int solution(vector<int> &A)
{
    // check for valid input
    if (A.size() == 0)
    {
        return 1;
    }

    vector<int> sorted_input(A);
    std::sort(sorted_input.begin(), sorted_input.end());

    int current_value = 0;

    for (int each_value = 0; each_value < sorted_input.size(); ++each_value)
    {
        // skip negative numbers
        if (sorted_input[each_value] < 0)
        {
            continue;
        }

        // edge case - the number 1 is missing ex. [-1, 0, 2, 3]
        if ((current_value == 0) && (sorted_input[each_value] > 1))
        {
            break;
        }

        // reached the end of the list and everything has been sequential, thus the missing number in the sequence would be one past the end ex [1, 2, 3] -> "4"
        if (sorted_input.size() <= (each_value + 1))
        {
            return sorted_input[each_value] + 1;
        }

        // continue past duplicate numbers ex. [1, 1, 1, 2, 3]
        if (sorted_input[each_value] == (sorted_input[each_value + 1]))
        {
            continue;
        }

        // found a break in the sequence, before reaching the end of the array, report the result
        if ((sorted_input[each_value] + 1) != sorted_input[each_value + 1])
        {
            return sorted_input[each_value] + 1;
        }

        // average case - found sequential numbers in the array
        current_value = sorted_input[each_value];
    }

    // Made it through the entire array without early returning, thus the missing number will be one past the last sequential number found.
    // Note that this could happen if the entire array contents are negative and current_value is still 0 from initialization.
    return (current_value + 1);
}
