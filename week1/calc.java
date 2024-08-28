import java.util.*;

class Cal {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter 1 for addition or 2 for subtraction");
        int ch = in.nextInt();
        if (ch == 1) {
            int a, b;
            System.out.println("Enter 2 numbers");
            a = in.nextInt();
            b = in.nextInt();
            System.out.println("Sum = " + (a + b));
        } else if (ch == 2) {
            int c, d;
            System.out.println("Enter 2 numbers");
            c = in.nextInt();
            d = in.nextInt();
            System.out.println("Difference = " + (c - d));
        } else {
            System.out.println("Invalid choice");
        }
        in.close();
    }
}