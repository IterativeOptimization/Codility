#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A);

int main()
{
    vector<int> input = {4, 1, 3, 2};
    // vector<int> input = { 4, 1, 3 };
    // vector<int> input = { 1, 4, 1 };

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

    // trivial edge case
    if (A.size() == 1)
    {
        if (1 == A[0])
        {
            return 1;
        }
        return 0;
    }

    vector<int> sorted_vector(A);
    std::sort(sorted_vector.begin(), sorted_vector.end());

    // if the sorted list does not start at 1, this is not a permutation
    if (1 != sorted_vector[0])
    {
        return 0;
    }

    for (int each_position = 1; each_position < sorted_vector.size(); ++each_position)
    {
        // if at any point the current number is not one greater than the previous
        // position (ex. duplicate, missing number, etc) NOT a permutation.
        if ((sorted_vector[each_position - 1] + 1) != sorted_vector[each_position])
        {
            return 0;
        }
    }

    // made it through the list and everything was sequential, must be a permutation
    return 1;
}
