import java.util.*;

class factorial {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a non-negative integer: ");
        int num = scanner.nextInt();
        scanner.close();

        int factorial = 1;
        int i = 1;
        do {
            factorial *= i;
            i++;
        } while (i <= num);

        System.out.println("The factorial of " + num + " is " + factorial);
    }
}