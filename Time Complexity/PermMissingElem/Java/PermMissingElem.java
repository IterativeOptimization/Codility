import java.util.Arrays;

class main {
    public static void main(String[] args) {
        int[] input = { 2, 3 };
        // int[] input = { 2, 3, 1, 5 };

        Solution mySolution = new Solution();
        int output_value = mySolution.solution(input);
        System.out.println("Output Value: " + output_value);
    }
}

class Solution {
    public int solution(int[] A)
    {
        // check for valid input
        if (A.length == 0)
        {
            return 1;
        }

        // edge case - one value in the array
        if (A.length == 1)
        {
            // missing value could be the first or last
            if (A[0] != 1) {
                return 1;
            }

            return 2;
        }

        int[] sorted_input = A;
        Arrays.sort(sorted_input);

        // edge case - first value is missing
        if (sorted_input[0] != 1)
        {
            return 1;
        }

        // compare each value + 1 to the next value, looking for the gap
        for (int index = 0; (index + 1) < sorted_input.length; ++index)
        {
            if ((sorted_input[index] + 1) != sorted_input[index + 1])
            {
                return sorted_input[index] + 1;
            }
        }

        // if we reached the end, the missing value is the final position
        return (sorted_input.length + 1);
    }
}
