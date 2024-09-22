class SleepThread extends Thread {
    @Override
    public void run() {
        // Array of sleep times (in milliseconds)
        int[] sleepTimes = {10, 20, 50, 70, 100};

        for (int sleepTime : sleepTimes) {
            System.out.println(Thread.currentThread().getName() + " will sleep for " + sleepTime + " milliseconds.");
            
            try {
                // Sleep for the specified duration
                Thread.sleep(sleepTime);
            } catch (InterruptedException e) {
                System.out.println(Thread.currentThread().getName() + " was interrupted.");
            }

            System.out.println(Thread.currentThread().getName() + " woke up after " + sleepTime + " milliseconds.");
        }
    }
}

public class ThreadSleepExample {
    public static void main(String[] args) {
        // Create a new thread object
        SleepThread sleepThread = new SleepThread();

        // Set thread name
        sleepThread.setName("SleepThread");

        // Start the thread
        sleepThread.start();
    }
}
