import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class main {
    public static void main(String[] args) {
        int[] input = { 4, 1, 3, 2 };
        // int[] input = { 4, 1, 3 };
        // int[] input = { 1, 4, 1 };

        Solution mySolution = new Solution();
        int output_value = mySolution.solution(input);
        System.out.println("Output Value: " + output_value);
    }
}

class Solution {
    public int solution(int[] A) {
        // check for valid input
        if (A.length == 0) {
            return 1;
        }

        // trivial edge case
        if (A.length == 1) {
            if (1 == A[0]) {
                return 1;
            }
            return 0;
        }

        List<Integer> sorted_list = new ArrayList<Integer>();
        for (int each_position = 0; each_position < A.length; ++each_position) {
            sorted_list.add(A[each_position]);
        }
        Collections.sort(sorted_list);

        // if the sorted list does not start at 1, this is not a permutation
        if (1 != sorted_list.get(0)) {
            return 0;
        }

        for (int each_position = 1; each_position < sorted_list.size(); ++each_position) {
            // if at any point the current number is not one greater than the previous
            // position (ex. duplicate, missing number, etc) NOT a permutation.
            if ((sorted_list.get(each_position - 1) + 1) != sorted_list.get(each_position)) {
                return 0;
            }
        }

        // made it through the list and everything was sequential, must be a permutation
        return 1;
    }
}
