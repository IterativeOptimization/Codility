class main
{
    public static void main(String[] args)
    {
        int input_value = 1041;
        System.out.println("Input Value: " + input_value);
        Solution mySolution = new Solution();
        int output_value = mySolution.solution(1041);
        System.out.println("Output Value: " + output_value);
    }
}

class Solution
{
    public int solution(int N)
    {
        if(N <= 1)
        {
            return 0;
        }

        if(N > 2147483647)
        {
            return 0;
        }

        int working_value = N;
        int max_gap = 0;
        int zero_count = -1;

        while (working_value > 0)
        {
            if ((working_value & 1) == 1)
            {
                if (zero_count > max_gap)
                {
                    max_gap = zero_count;
                }
                zero_count = 0;
            }
            else
            {
                if (zero_count != -1)
                {
                    zero_count++;
                }
            }
            working_value = working_value >> 1;
        }
        return max_gap;
    }
}
