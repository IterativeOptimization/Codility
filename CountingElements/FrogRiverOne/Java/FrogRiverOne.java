class main {
    public static void main(String[] args) {
        int[] input = { 1, 3, 1, 4, 2, 3, 5, 4 };
        int distance = 5;

        Solution mySolution = new Solution();
        int output_value = mySolution.solution(distance, input);
        System.out.println("Output Value: " + output_value);
    }
}

class Solution {
    public int solution(int X, int[] A) {
        // check for valid input
        if (X < 0)
        {
            return -1;
        }

        if (A.length == 0)
        {
            return -1;
        }

        int position_count = 0;
        boolean[] occupied_positions = new boolean[X];

        for (int each_position = 0; each_position < A.length; ++each_position)
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
}
