import java.util.*;

class Avg {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, i = 0, j = 0;
        double sum = 0, avg = 0; 
        System.out.println("Enter no of terms");
        n = in.nextInt();
        int[] arr = new int[n];
        while (i < n) {
            System.out.println("Enter term " + (i + 1)); 
            arr[i] = in.nextInt();
            i++;
        }

        while (j < n) {
            sum = sum + arr[j];
            j++;
        }
        avg = sum / n;
        System.out.println("The average is = " + avg);
    }
}