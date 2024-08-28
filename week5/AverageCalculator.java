import java.util.Scanner;

public class AverageCalculator {
    public static void main(String[] args) {
        int[] numbers = getInputArray();
        double average = calculateAverage(numbers);
        System.out.println("The average of the array is: " + average);
    }

    public static int[] getInputArray() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int size = scanner.nextInt();
        int[] numbers = new int[size];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < size; i++) {
            numbers[i] = scanner.nextInt();
        }
        return numbers;
    }

    public static double calculateAverage(int[] numbers) {
        int sum = 0;
        for (int number : numbers) {
            sum += number;
        }
        return (double) sum / numbers.length;
    }
}