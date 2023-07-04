class main
{
    static public void Main(String[] args)
    {
        int[] input = { 2, 3 };
        // int[] input = { 2, 3, 1, 5 };

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

        // edge case
        if (A.Length == 1)
        {
            if (A[0] != 1)
            {
                return 1;
            }

            return 2;
        }

        int[] sorted_input = A;
        Array.Sort(sorted_input);

        // edge case
        if (sorted_input[0] != 1)
        {
            return 1;
        }

        for (int index = 0; (index + 1) < sorted_input.Length; ++index)
        {
            if ((sorted_input[index] + 1) != sorted_input[index + 1])
            {
                return sorted_input[index] + 1;
            }
        }

        // if we reached the end, the missing value is the final element
        return (sorted_input.Length + 1);
    }
}