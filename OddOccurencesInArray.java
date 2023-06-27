import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class main {
    public static void main(String[] args) {
        int[] input_value = { 9, 3, 9, 3, 9, 7, 9 };
        System.out.println("Input Value: " + Arrays.toString(input_value));

        Solution mySolution = new Solution();
        int output_value = mySolution.solution(input_value);
        System.out.println("Output Value: " + output_value);
    }
}

class Solution {
    public int solution(int[] A) {
        // check for valid input
        if ((A.length == 0)) {
            return 0;
        }

        if (A.length == 1) {
            return A[0];
        }

        // create a new unique key based data structure
        Map<Integer, Integer> occurrence_count = new HashMap<Integer, Integer>(A.length);
        int working_value = 0;

        // go through each value stored in the input array and note how many times it has been found
        for (int each_entry = 0; each_entry < A.length; ++each_entry) {
            if (occurrence_count.containsKey(A[each_entry])) {
                working_value = occurrence_count.get(A[each_entry]);
                occurrence_count.put(A[each_entry], (working_value + 1));
            } else {
                occurrence_count.put(A[each_entry], 1);
            }
        }

        // the key with an odd number value is the one with no matching pair
        for (Integer key : occurrence_count.keySet()) {
            Integer value = occurrence_count.get(key);
            if ((value & 1) == 1) {
                return key;
            }
        }

        return 0;
    }
}