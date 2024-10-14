import java.util.Scanner;

public class CircleAreaCalculatorImpure {
    // Impure function that prompts the user for the radius and prints the area
    public static void promptAndCalculateArea() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the radius of the circle: ");
        double radius = scanner.nextDouble();

        double area = Math.PI * radius * radius;
        System.out.println("The area of the circle with radius " + radius + " is: " + area);
    }

    public static void main(String[] args) {
        promptAndCalculateArea();
    }
}
