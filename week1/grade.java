import java.util.Scanner;

class Grade {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m;
        System.out.println("Enter marks");
        m = in.nextInt();

        if (m < 0 || m > 100) {
            System.out.println("Invalid score input");
        } else {
            int grade = m / 10;
            switch (grade) {
                case 10:
                case 9:
                    System.out.println("A");
                    break;
                case 8:
                    System.out.println("B");
                    break;
                case 7:
                    System.out.println("C");
                    break;
                case 6:
                    System.out.println("D");
                    break;
                default:
                    System.out.println("F");
            }
        }
        in.close();
    }
}