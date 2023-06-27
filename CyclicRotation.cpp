#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K);

int main()
{
    // vector<int> input_value = {3,8,9,7,6};
    // int shift_amount = 3;

    // vector<int> input_value = {0,0,0};
    // int shift_amount = 1;

    vector<int> input_value = {1, 2, 3, 4};
    int shift_amount = 4;

    cout << "Input Value: ";
    for (int each_value = 0; each_value < input_value.size(); ++each_value)
    {
        cout << input_value[each_value];
    }
    cout << endl;
    cout << "Shift Amount: " << shift_amount << endl;

    vector<int> output_value = solution(input_value, shift_amount);
    cout << "Output Value: ";
    for (int each_value = 0; each_value < output_value.size(); ++each_value)
    {
        cout << output_value[each_value];
    }
    cout << endl;
}

vector<int> solution(vector<int> &A, int K)
{
    // ensure there is something to rotate
    if ((A.size() == 0) || (A.size() == 1))
    {
        return A;
    }

    // input bounds checking
    if ((K <= 0) || (K > 100))
    {
        return A;
    }

    // Shifting by the length of the array just resets to the starting point, so only shift by amounts less than that
    int shifts_needed = K % A.size();
    vector<int> output_value;
    output_value.resize(A.size());

    // find the point in the old array which will become the new start
    int old_position = A.size() - shifts_needed;
    int new_position = 0;

    // transfer from the old array to the new one from the mid point (the second part)
    while (old_position < A.size())
    {
        output_value[new_position] = A[old_position];
        old_position++;
        new_position++;
    }

    old_position = 0;

    // transfer from the old array to the new one, from the start (the first part)
    while (new_position < A.size())
    {
        output_value[new_position] = A[old_position];
        old_position++;
        new_position++;
    }

    return output_value;
}
