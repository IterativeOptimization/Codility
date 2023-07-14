#include <iostream>
#include <vector>
#include <stdlib.h> // abs
#include <limits.h> // INT_MAX

using namespace std;

int solution(vector<int> &A);
int vector_sum(vector<int> &input_vector, int start, int end);

int main()
{
    // vector<int> input_value = { 3, 1, 2, 4, 3 };
    // vector<int> input_value = { 1 };
    // vector<int> input_value = { 1, 1, 1, 1 };
    // vector<int> input_value = {-1000, 1000};
    // vector<int> input_value = { 555, 88, 7777, 999, 123456 };
    // vector<int> input_value = { -10, -20, -30, -40, 100 };
    vector<int> input_value = {1, 2, 3, 4, 10};

    int output_value = solution(input_value);
    cout << "Output Value: " << output_value << endl;
}

int solution(vector<int> &A)
{
    // check for valid input
    if (A.size() == 0)
    {
        return 0;
    }

    if (A.size() == 1)
    {
        return A[0];
    }

    int right_side = 0;
    int left_side = 0;
    int current_difference = -1;
    int best_difference = INT_MAX;

    right_side = A[0];
    left_side = vector_sum(A, 1, A.size());
    // edge case, balanced array
    if (right_side == left_side)
    {
        return 0;
    }
    current_difference = abs(right_side - left_side);
    best_difference = current_difference;

    // should never need to visit more positions than the length of the array
    for (int count = 1; count < (A.size() - 1); count++)
    {
        right_side += A[count];
        left_side -= A[count];
        current_difference = abs(right_side - left_side);

        // edge case, balanced array
        if (right_side == left_side)
        {
            return 0;
        }

        if (best_difference > current_difference)
        {
            best_difference = current_difference;
        }
    }

    return best_difference;
}

int vector_sum(vector<int> &input_vector, int start, int end)
{
    int running_total = 0;
    for (int each_value = start; each_value < end; each_value++)
    {
        running_total += input_vector[each_value];
    }
    return running_total;
}
