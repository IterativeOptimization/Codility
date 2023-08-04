import java.util.Arrays;

class main {
    public static void main(String[] args) {
        int[] input = { 3, 4, 4, 6, 1, 4, 4 };
        int counters = 5;

        Solution mySolution = new Solution();
        int[] output_value = mySolution.solution(counters, input);
        System.out.println("Output Value: " + Arrays.toString(output_value));
    }
}

class Solution {
    public int[] solution(int N, int[] A) {
        // check for valid input
        if (A.length == 0) {
            return A;
        }

        if (N < 0) {
            return A;
        }

        int current_highest_counter = 0; // the highest counter value yet assigned
        int floor_value = 0; // the lowest value that should be in any position
        int[] result = new int[N];
        int current_counter_value = 0;

        for (int each_value = 0; each_value < A.length; each_value++) {
            // if the value in the input array is higher than the number of counters
            if (A[each_value] > N) {
                // a new minimum value has been established for all result positions
                floor_value = current_highest_counter;
                continue;
            }

            // if the value in this counter is lower than the floor value, update it
            current_counter_value = result[A[each_value] - 1];
            if (current_counter_value < floor_value) {
                result[A[each_value] - 1] = floor_value;
                current_counter_value = floor_value;
            }

            // increase the counter associated with this value
            current_counter_value = (result[A[each_value] - 1] += 1);

            // track the highest counter ever set for future floor values
            if (current_counter_value > current_highest_counter) {
                current_highest_counter = current_counter_value;
            }
        }

        // ensure that the floor value has been applied to all result output positions
        for (int each_value = 0; each_value < result.length; each_value++) {
            if (result[each_value] < floor_value) {
                result[each_value] = floor_value;
            }
        }

        return result;
    }
}