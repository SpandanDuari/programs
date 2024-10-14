public class CircleAreaCalculator {
    // Pure function to calculate the area of a circle
    public static double calculateArea(double radius) {
        return Math.PI * radius * radius;
    }

    public static void main(String[] args) {
        double radius = 5.0;
        double area = calculateArea(radius);
        System.out.println("The area of the circle with radius " + radius + " is: " + area);
    }
}
