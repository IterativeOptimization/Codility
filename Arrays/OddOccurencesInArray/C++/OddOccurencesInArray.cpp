#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A);

int main()
{
    vector<int> input_value = {9, 3, 9, 3, 9, 7, 9};

    int output_value = solution(input_value);
    cout << "Output Value: " << output_value << endl;
}

int solution(vector<int> &A)
{
    // check for valid input
    if ((A.size() == 0))
    {
        return 0;
    }

    // create a data structure the size of the largest possible input value
    vector<bool> occurrence_count;
    occurrence_count.resize(1000000000);
    unsigned long long total = 0;

    for (unsigned int each_entry = 0; each_entry < A.size(); ++each_entry)
    {
        // if this value has been found before, subtract it from the running total
        if (occurrence_count[A[each_entry]])
        {
            total -= A[each_entry];
            occurrence_count[A[each_entry]] = false;
        }
        else
        {
            // if this value has not been found before, or was found an even number of times, add it to the running total
            total += A[each_entry];
            occurrence_count[A[each_entry]] = true;
        }
    }

    // whatever is left in the running total is the value that had no match
    return total;
}
