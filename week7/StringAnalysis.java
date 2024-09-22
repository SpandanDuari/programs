class ThreadA extends Thread {
    private String k;
    private int dc; // Digit count

    // Constructor to initialize the string
    public ThreadA(String k) {
        this.k = k;
    }

    @Override
    public void run() {
        dc = 0;
        // Count digits in the string
        for (int i = 0; i < k.length(); i++) {
            if (Character.isDigit(k.charAt(i))) {
                dc++;
            }
        }
        // Print the result in the specified format
        System.out.println("ThreadA: digitscount = " + dc);
    }
}

class ThreadB extends Thread {
    private String k;
    private int cc; // Alphabetic character count

    // Constructor to initialize the string
    public ThreadB(String k) {
        this.k = k;
    }

    @Override
    public void run() {
        cc = 0;
        // Count alphabetic characters in the string
        for (int i = 0; i < k.length(); i++) {
            if (Character.isLetter(k.charAt(i))) {
                cc++;
            }
        }
        // Print the result in the specified format
        System.out.println("ThreadB: alphabetscount = " + cc);
    }
}

public class StringAnalysis {
    public static void main(String[] args) {
        String k = "abc123xyz456"; // Example string with digits and alphabets

        // Create and start threads
        ThreadA threadA = new ThreadA(k);
        ThreadB threadB = new ThreadB(k);

        threadA.start();  // Start ThreadA to count digits
        threadB.start();  // Start ThreadB to count alphabetic characters
    }
}
