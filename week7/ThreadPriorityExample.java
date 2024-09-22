import java.util.Scanner;

class UserThreadPriority extends Thread {
    static String k;  // Shared String variable across all threads
    static char c;    // Shared Character variable across all threads

    @Override
    public void run() {
        // Custom logic for thread (example: print name and the assigned String and Character)
        System.out.println(Thread.currentThread().getName() + " is running.");
        System.out.println("String value (k): " + k);
        System.out.println("Character value (c): " + c);
    }
}

public class ThreadPriorityExample {
    public static void main(String[] args) {
        // Create scanner to get input from user
        Scanner scanner = new Scanner(System.in);

        // Get a string from the user
        System.out.print("Enter a string: ");
        UserThreadPriority.k = scanner.nextLine();  // Assign the input string to class variable k

        // Get a character from the user
        System.out.print("Enter a character: ");
        UserThreadPriority.c = scanner.next().charAt(0);  // Assign the input character to class variable c

        // Create thread objects
        UserThreadPriority threadobj1 = new UserThreadPriority();
        UserThreadPriority threadobj2 = new UserThreadPriority();

        // Set the names of the threads
        threadobj1.setName("ThreadA");
        threadobj2.setName("ThreadB");

        // Start the threads
        threadobj1.start();
        threadobj2.start();
    }
}
