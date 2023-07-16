#include <iostream>
#include <vector>

using namespace std;

int solution(int X, vector<int> &A);

int main()
{
    vector<int> input = { 1, 3, 1, 4, 2, 3, 5, 4 };
    int distance = 5;

    int output_value = solution(distance, input);
    cout << "Output Value: " << output_value << endl;
}

int solution(int X, vector<int> &A)
{
        // check for valid input
        if (X < 0)
        {
            return -1;
        }

        if (A.size() == 0)
        {
            return -1;
        }

        int position_count = 0;
        vector<bool> occupied_positions;
        occupied_positions.resize(X);

        for (int each_position = 0; each_position < A.size(); ++each_position)
        {
            int current_position = A[each_position] - 1;
            if (current_position > X)
            {
                continue;
            }

            if (occupied_positions[current_position] == false)
            {
                occupied_positions[current_position] = true;
                position_count += 1;
            }

            if (position_count == X)
            {
                return each_position;
            }
        }

        return -1;
}
