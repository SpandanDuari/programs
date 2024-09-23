import java.util.Scanner;

class ThreadA extends Thread {
    private String k;
    private int dc;

    public ThreadA(String k) {
        this.k = k;
    }

    public void run() {
        dc = 0;
        for (char c : k.toCharArray()) {
            if (Character.isDigit(c)) {
                dc++;
            }
        }
        System.out.println("ThreadA:digitcount=" + dc);
    }
}

class ThreadB extends Thread {
    private String k;
    private int cc;

    public ThreadB(String k) {
        this.k = k;
    }

    public void run() {
        cc = 0;
        for (char c : k.toCharArray()) {
            if (Character.isLetter(c)) {
                cc++;
            }
        }
        System.out.println("ThreadB:charcount=" + cc);
    }
}

public class StringAnalysis {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String k = scanner.nextLine();

        ThreadA threadA = new ThreadA(k);
        ThreadB threadB = new ThreadB(k);

        threadA.start();
        threadB.start();
    }
}