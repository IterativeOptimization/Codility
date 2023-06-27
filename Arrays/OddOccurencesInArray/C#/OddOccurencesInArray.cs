class main
{
    static public void Main(String[] args)
    {
        int[] input_value = { 9, 3, 9, 3, 9, 7, 9 };

        Console.WriteLine("Input Value: ");
        Array.ForEach(input_value, Console.WriteLine);

        Solution mySolution = new Solution();
        int output_value = mySolution.solution(input_value);
        Console.WriteLine("Output Value: " + output_value);
    }
}

class Solution
{
    public int solution(int[] A)
    {
        // check for valid input
        if ((A.Length == 0))
        {
            return 0;
        }

        if (A.Length == 1)
        {
            return A[0];
        }

        // create a new unique key based data structure
        Dictionary<int, int> occurrence_count = new Dictionary<int, int>(A.Length);
        int working_value = 0;

        // go through each value stored in the input array and note how many times it has been found
        for (int each_entry = 0; each_entry < A.Length; ++each_entry)
        {
            if (occurrence_count.TryGetValue(A[each_entry], out working_value))
            {
                occurrence_count[A[each_entry]] = (working_value + 1);
            }
            else
            {
                occurrence_count.Add(A[each_entry], 1);
            }
        }

        // the key with an odd number value is the one with no matching pair
        foreach (KeyValuePair<int, int> each_kvp in occurrence_count)
        {
            if ((each_kvp.Value & 1) == 1)
            {
                return each_kvp.Key;
            }
        }

        return 0;
    }
}
