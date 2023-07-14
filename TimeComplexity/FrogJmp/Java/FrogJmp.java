class main {
    public static void main(String[] args) {
        int x = 10;
        int y = 85;
        int d = 30;

        Solution mySolution = new Solution();
        int output_value = mySolution.solution(x, y, d);
        System.out.println("Output Value: " + output_value);
    }
}

class Solution {
    public int solution(int X, int Y, int D) {
        // check for valid input
        if (D <= 0) {
            return 0;
        }

        if (X > Y) {
            return 0;
        }

        int distance_to_cover = Y - X;

        // if the distance cannot be covered perfectly with a certain number of
        // movements
        if ((distance_to_cover % D) > 0) {
            // return the number of movements needed plus one for the partial movement
            return ((distance_to_cover / D) + 1);
        }

        // return the number of movements needed
        return (distance_to_cover / D);
    }
}
