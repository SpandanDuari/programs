import java.util.Random;

public class LargestNumberFinder {
    public static void main(String[] args) {
        int[] numbers = fillArray(10, 1, 100); // fill an array with 10 random numbers between 1 and 100
        int largest = findLargest(numbers);
        System.out.println("The largest number in the array is: " + largest);
    }

    public static int[] fillArray(int size, int min, int max) {
        Random random = new Random();
        int[] numbers = new int[size];
        for (int i = 0; i < size; i++) {
            numbers[i] = random.nextInt(max - min + 1) + min;
        }
        return numbers;
    }

    public static int findLargest(int[] numbers) {
        int largest = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i] > largest) {
                largest = numbers[i];
            }
        }
        return largest;
    }
}