import java.util.*;

class Vending {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int ch;
        System.out.println("Press 1 for juice or 2 for soda");
        ch = in.nextInt();
        if (ch == 1) {
            System.out.println("Dispensing juice");
        } else if (ch == 2) {
            System.out.println("Dispensing soda");
        } else {
            System.out.println("Invalid choice");
        }
        in.close();
    }
}