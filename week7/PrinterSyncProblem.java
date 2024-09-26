class Printer {
    private int currentJob = 1;  // Start with the first job
    
    // Method to print a job
    public synchronized void printJob(int jobId) {
        // Loop until it's the turn of this job
        while (jobId != currentJob) {
            try {
                wait();  // Wait for the turn
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt(); // Handle interrupt'

            }
        }
        
        // Print the job
        System.out.println("Printing job " + jobId);
        
        
        // Move to the next job
        currentJob++;
        
        // Notify all waiting threads to check if it's their turn
        notifyAll();
    }
}

class PrintJob implements Runnable {
    private final int jobId;
    private final Printer printer;

    // Constructor
    public PrintJob(int jobId, Printer printer) {
        this.jobId = jobId;
        this.printer = printer;
    }

    @Override
    public void run() {
        printer.printJob(jobId);
    }
}

public class PrinterSyncProblem {
    public static void main(String[] args) {
        Printer printer = new Printer();
        
        // Create threads for different jobs
        Thread job1 = new Thread(new PrintJob(1, printer));
        Thread job2 = new Thread(new PrintJob(2, printer));
        Thread job3 = new Thread(new PrintJob(3, printer));
        
        // Start the threads in random order
        job3.start();
        job1.start();
        job2.start();
    }
}
