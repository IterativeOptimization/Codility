using System.Collections.Generic;
using System.Linq;

class main
{
    static public void Main(String[] args)
    {
        int[] input = { 1, 3, 6, 4, 1, 2 };
        // int[] input = { 1, 2, 3 };
        // int[] input = { -1, -3 };

        Solution mySolution = new Solution();
        int output_value = mySolution.solution(input);
        Console.WriteLine("Output Value: " + output_value);
    }
}

class Solution
{
    public int solution(int[] A)
    {
        // check for valid input
        if (A.Length == 0)
        {
            return 1;
        }

        List<int> sorted_input = A.ToList<int>();
        sorted_input.Sort();

        int current_value = 0;

        for (int each_value = 0; each_value < sorted_input.Count; ++each_value)
        {
            // skip negative numbers
            if(sorted_input[each_value] < 0) {
                continue;
            }

            // edge case - the number 1 is missing ex. [-1, 0, 2, 3]
            if((current_value == 0) && (sorted_input[each_value] > 1))
            {
                break;
            }

            // reached the end of the list and everything has been sequential, thus the missing number in the sequence would be one past the end ex [1, 2, 3] -> "4"
            if(sorted_input.Count <= (each_value + 1))
            {
                return sorted_input[each_value] + 1;
            }

            // continue past duplicate numbers ex. [1, 1, 1, 2, 3]
            if(sorted_input[each_value] == (sorted_input[each_value + 1]))
            {
                continue;
            }

            // found a break in the sequence, before reaching the end of the array, report the result
            if((sorted_input[each_value] + 1) != sorted_input[each_value + 1])
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
}