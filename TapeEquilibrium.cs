class main
{
    static public void Main(String[] args)
    {
        // int[] input = { 3, 1, 2, 4, 3 };
        // int[] input = { 1 };
        // int[] input = { 1, 1, 1, 1 };
        int[] input = { -1000, 1000 };
        // int[] input = { 555, 88, 7777, 999, 123456 };
        // int[] input = { -10, -20, -30, -40, 100 };
        // int[] input = { 1, 2, 3, 4, 10 };

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
            return 0;
        }

        if (A.Length == 1)
        {
            return A[0];
        }

        int right_side = 0;
        int left_side = 0;
        int current_difference = -1;
        int best_difference = Int32.MaxValue;

        right_side = A[0];
        left_side = array_sum(A, 1, A.Length);

        // edge case, balanced array
        if (right_side == left_side)
        {
            return 0;
        }
        current_difference = Math.Abs(right_side - left_side);
        best_difference = current_difference;

        // should never need to visit more positions than the length of the array
        for (int count = 1; count < (A.Length - 1); count++)
        {
            right_side += A[count];
            left_side -= A[count];
            current_difference = Math.Abs(right_side - left_side);

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

    public int array_sum(int[] input_array, int start, int end)
    {
        int running_total = 0;
        for (int each_value = start; each_value < end; each_value++)
        {
            running_total += input_array[each_value];
        }
        return running_total;
    }

    // public int solution(int[] A)
    // {
    //     // check for valid input
    //     if (A.Length == 0)
    //     {
    //         return 0;
    //     }

    //     if (A.Length == 1)
    //     {
    //         return A[0];
    //     }

    //     int entry_point = A.Length / 2;
    //     // int last_entry_point = entry_point;
    //     int right_side = 0;
    //     int left_side = 0;
    //     int current_difference = -1;

    //     right_side = array_sum(A, 0, entry_point);
    //     left_side = array_sum(A, entry_point, A.Length);

    //     // edge case, balanced array
    //     if (right_side == left_side)
    //     {
    //         return 0;
    //     }

    //     current_difference = Math.Abs(right_side - left_side);
    //     left_side = dive(A, current_difference, entry_point, Math.Max(entry_point / 2, 1), entry_point);
    //     right_side = dive(A, current_difference, entry_point, entry_point + ((A.Length - entry_point) / 2), A.Length);

    //     if (left_side < right_side)
    //     {
    //         return left_side;
    //     }

    //     return right_side;
    // }

    // public int dive(int[] A, int last_difference, int last_entry_point, int entry_point, int max_entry)
    // {
    //     int right_side = 0;
    //     int left_side = 0;
    //     int current_difference = -1;

    //     right_side = array_sum(A, 0, entry_point);
    //     left_side = array_sum(A, entry_point, A.Length);

    //     // edge case, balanced array
    //     if (right_side == left_side)
    //     {
    //         return 0;
    //     }

    //     current_difference = Math.Abs(right_side - left_side);

    //     if (current_difference > last_difference)
    //     {
    //         return last_difference;
    //     }

    //     int new_entry = entry_point / 2;
    //     if (new_entry >= 1)
    //     {
    //         left_side = dive(A, current_difference, entry_point, entry_point / 2, max_entry);
    //     }
    //     new_entry = entry_point + ((max_entry - entry_point) / 2);
    //     if (new_entry != last_entry_point)
    //     {
    //         right_side = dive(A, current_difference, entry_point, entry_point + ((max_entry - entry_point) / 2), max_entry);
    //     }

    //     return current_difference;
    // }

    // public int solution(int[] A)
    // {
    //     // check for valid input
    //     if (A.Length <= 1)
    //     {
    //         return 0;
    //     }

    //     int entry_point = A.Length / 2;
    //     int last_entry_point = entry_point;
    //     int right_side = 0;
    //     int left_side = 0;
    //     int current_difference = -1;
    //     int best_difference = Int32.MaxValue;

    //     // should never need to visit more positions than the length of the array
    //     for (int count = 0; count < A.Length; count++)
    //     {
    //         right_side = array_sum(A, 0, entry_point);
    //         left_side = array_sum(A, entry_point, A.Length);

    //         // edge case, balanced array
    //         if (right_side == left_side)
    //         {
    //             return 0;
    //         }

    //         if (right_side > left_side)
    //         {
    //             current_difference = right_side - left_side;
    //             // if the difference starts getting worse, this is as good as it gets
    //             if (best_difference < current_difference)
    //             {
    //                 return best_difference;
    //             }
    //             best_difference = current_difference;
    //             last_entry_point = entry_point;

    //             // avoid a divide by zero situation
    //             if (last_entry_point == 0)
    //             {
    //                 return best_difference;
    //             }

    //             // dividing one by two won't get to array position 0 very easily
    //             if (last_entry_point == 1)
    //             {
    //                 entry_point = 0;
    //             }
    //             else
    //             {
    //                 entry_point = entry_point / 2;
    //             }
    //         }
    //         else
    //         {
    //             current_difference = left_side - right_side;
    //             // if the difference starts getting worse, this is as good as it gets
    //             if (best_difference < current_difference)
    //             {
    //                 return best_difference;
    //             }
    //             best_difference = current_difference;
    //             last_entry_point = entry_point;
    //             entry_point = entry_point + ((A.Length - entry_point) / 2);

    //             // run out of options, the last number in the array is huge
    //             if (last_entry_point == (A.Length - 1))
    //             {
    //                 return best_difference;
    //             }
    //         }
    //     }

    //     return best_difference;
    // }
}