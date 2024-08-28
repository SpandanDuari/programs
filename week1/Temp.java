import java.util.*;

class Temp {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t;
        System.out.println("Enter temperature");
        t = in.nextInt();
        if (t > 30) {
            System.out.println("Its hot");
        } else if (t >= 20 && t <= 30) {
            System.out.println("Its warm");
        } else if (t >= 10 && t < 20) {
            System.out.println("Its cool");
        } else {
            System.out.println("Its cold");
        }
        in.close();
    }
}