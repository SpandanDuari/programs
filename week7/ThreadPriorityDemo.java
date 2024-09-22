class PriorityThread extends Thread {
    // Constructor to set the thread name
    public PriorityThread(String name) {
        super(name);
    }

    @Override
    public void run() {
        // Display thread name and its priority
        System.out.println(Thread.currentThread().getName() + " is running with priority: " + Thread.currentThread().getPriority());
    }
}

public class ThreadPriorityDemo { // Renamed the public class
    public static void main(String[] args) {
        // Create 5 thread objects with different names
        PriorityThread process1 = new PriorityThread("Process1");
        PriorityThread process2 = new PriorityThread("Process2");
        PriorityThread process3 = new PriorityThread("Process3");
        PriorityThread process4 = new PriorityThread("Process4");
        PriorityThread process5 = new PriorityThread("Process5");

        // Set priorities for each thread
        process1.setPriority(Thread.MIN_PRIORITY);   // Priority 1
        process2.setPriority(3);                     // Priority 3
        process3.setPriority(Thread.NORM_PRIORITY);  // Priority 5
        process4.setPriority(7);                     // Priority 7
        process5.setPriority(Thread.MAX_PRIORITY);   // Priority 10

        // Start the threads
        process1.start();
        process2.start();
        process3.start();
        process4.start();
        process5.start();
    }
}
