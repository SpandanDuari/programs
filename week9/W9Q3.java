import java.util.List;

public class W9Q3 {
    // Pure function to find the maximum value in a list of numbers
    public static int findMaxValue(List<Integer> numbers) {
        int max = Integer.MIN_VALUE;
        for (int number : numbers) {
            if (number > max) {
                max = number;
            }
        }
        return max;
    }

    public static void main(String[] args) { // Changed the method name to main
        List<Integer> numbers = List.of(10, 20, 5, 8, 30);
        int maxValue = findMaxValue(numbers);
        System.out.println("The maximum value in the list is: " + maxValue);
    }
}
