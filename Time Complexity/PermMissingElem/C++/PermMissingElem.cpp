#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A);

int main()
{
    // vector<int> input_value = {2, 3};
    vector<int> input_value = { 2, 3, 1, 5 };

    int output_value = solution(input_value);
    cout << "Output Value: " << output_value << endl;
}

int solution(vector<int> &A)
{
    // check for valid input
    if (A.size() == 0)
    {
        return 1;
    }

    // edge case - one value in the array
    if (A.size() == 1)
    {
        // missing value could be the first or last
        if (A[0] != 1)
        {
            return 1;
        }

        return 2;
    }

    vector<int> sorted_input = A;
    sort(sorted_input.begin(), sorted_input.end());

    // edge case - first value is missing
    if (sorted_input[0] != 1)
    {
        return 1;
    }

    // compare each value + 1 to the next value, looking for the gap
    for (int index = 0; (index + 1) < sorted_input.size(); ++index)
    {
        if ((sorted_input[index] + 1) != sorted_input[index + 1])
        {
            return sorted_input[index] + 1;
        }
    }

    // if we reached the end, the missing value is the final position
    return (sorted_input.size() + 1);
}
