import java.util.Arrays;
import java.util.Random;

public class W5Q1 {
    public static void main(String[] args) {
        // Create an integer array to store the grades of 30 students
        int[] grades = new int[30];

        // Populate the array with random grades between 0 and 100
        Random random = new Random();
        for (int i = 0; i < grades.length; i++) {
            grades[i] = random.nextInt(101); // 101 is the upper bound, so we get numbers from 0 to 100
        }

        // Calculate and print the average grade of the class
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        double average = (double) sum / grades.length;
        System.out.println("Average grade: " + average);

        // Find and print the highest and lowest grades
        int highest = grades[0];
        int lowest = grades[0];
        for (int i = 1; i < grades.length; i++) {
            if (grades[i] > highest) {
                highest = grades[i];
            }
            if (grades[i] < lowest) {
                lowest = grades[i];
            }
        }
        System.out.println("Highest grade: " + highest);
        System.out.println("Lowest grade: " + lowest);

        // Sort the grades in descending order and print the top 5 scores
        Arrays.sort(grades);
        System.out.println("Top 5 scores:");
        for (int i = grades.length - 1; i >= grades.length - 5; i--) {
            System.out.println(grades[i]);
        }
    }
}