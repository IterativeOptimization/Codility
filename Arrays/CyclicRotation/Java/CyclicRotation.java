import java.util.Arrays;

class main {
    public static void main(String[] args) {
        int[] input_value = { 3, 8, 9, 7, 6 };
        int shift_amount = 3;

        // int[] input_value = {0,0,0};
        // int shift_amount = 1;

        // int[] input_value = {1, 2, 3, 4};
        // int shift_amount = 4;

        System.out.println("Input Value: " + Arrays.toString(input_value));
        System.out.println("Shift Amount: " + shift_amount);

        Solution mySolution = new Solution();
        int[] output_value = mySolution.solution(input_value, shift_amount);
        System.out.println("Output Value: " + Arrays.toString(output_value));
    }
}

class Solution {
    public int[] solution(int[] A, int K) {
        // ensure there is something to rotate
        if ((A.length == 0) || (A.length == 1)) {
            return A;
        }

        // input bounds checking
        if ((K <= 0) || (K > 100)) {
            return A;
        }

        // Shifting by the length of the array just resets to the starting point, so only shift by amounts less than that
        int shifts_needed = K % A.length;
        int[] output_value = new int[A.length];

        // find the point in the old array which will become the new start
        int old_position = A.length - shifts_needed;
        int new_position = 0;

        // transfer from the old array to the new one from the mid point (the second part)
        while (old_position < A.length) {
            output_value[new_position] = A[old_position];
            old_position++;
            new_position++;
        }

        old_position = 0;

        // transfer from the old array to the new one, from the start (the first part)
        while (new_position < A.length) {
            output_value[new_position] = A[old_position];
            old_position++;
            new_position++;
        }

        return output_value;
    }
}
