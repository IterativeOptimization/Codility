import java.util.Arrays;

class main {
    public static void main(String[] args) {
        // int[] input = { 3, 1, 2, 4, 3 };
        // int[] input = { 1 };
        // int[] input = { 1, 1, 1, 1 };
        // int[] input = { -1000, 1000 };
        // int[] input = { 555, 88, 7777, 999, 123456 };
        // int[] input = { -10, -20, -30, -40, 100 };
        int[] input = { 1, 2, 3, 4, 10 };

        Solution mySolution = new Solution();
        int output_value = mySolution.solution(input);
        System.out.println("Output Value: " + output_value);
    }
}

class Solution {
    public int solution(int[] A) {
        // check for valid input
        if (A.length == 0) {
            return 0;
        }

        if (A.length == 1) {
            return A[0];
        }

        int right_side = 0;
        int left_side = 0;
        int current_difference = -1;
        int best_difference = Integer.MAX_VALUE;

        right_side = A[0];
        left_side = array_sum(A, 1, A.length);
        // edge case, balanced array
        if (right_side == left_side) {
            return 0;
        }
        current_difference = Math.abs(right_side - left_side);
        best_difference = current_difference;

        // should never need to visit more positions than the length of the array
        for (int count = 1; count < (A.length - 1); count++) {
            right_side += A[count];
            left_side -= A[count];
            current_difference = Math.abs(right_side - left_side);

            // edge case, balanced array
            if (right_side == left_side) {
                return 0;
            }

            if (best_difference > current_difference) {
                best_difference = current_difference;
            }
        }

        return best_difference;
    }

    public int array_sum(int[] input_array, int start, int end) {
        int running_total = 0;
        for (int each_value = start; each_value < end; each_value++) {
            running_total += input_array[each_value];
        }
        return running_total;
    }
}
