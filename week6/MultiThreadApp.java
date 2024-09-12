import java.util.Random;

public class MultiThreadApp {
    private static Integer sharedNumber = null;

    public static void main(String[] args) {
        Thread generatorThread = new Thread(new NumberGenerator());
        Thread squareThread = new Thread(new SquareCalculator());
        Thread cubeThread = new Thread(new CubeCalculator());

        generatorThread.start();
        squareThread.start();
        cubeThread.start();
    }

    static class NumberGenerator implements Runnable {
        @Override
        public void run() {
            Random random = new Random();
            try {
                while (true) {
                    synchronized (MultiThreadApp.class) {
                        sharedNumber = random.nextInt(100);
                        System.out.println("Generated Number: " + sharedNumber);
                        MultiThreadApp.class.notifyAll();
                    }
                    Thread.sleep(1000);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static class SquareCalculator implements Runnable {
        @Override
        public void run() {
            try {
                while (true) {
                    synchronized (MultiThreadApp.class) {
                        while (sharedNumber == null || sharedNumber % 2 != 0) {
                            MultiThreadApp.class.wait();
                        }
                        int square = sharedNumber * sharedNumber;
                        System.out.println("Square of " + sharedNumber + ": " + square);
                        sharedNumber = null;
                    }
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static class CubeCalculator implements Runnable {
        @Override
        public void run() {
            try {
                while (true) {
                    synchronized (MultiThreadApp.class) {
                        while (sharedNumber == null || sharedNumber % 2 == 0) {
                            MultiThreadApp.class.wait();
                        }
                        int cube = sharedNumber * sharedNumber * sharedNumber;
                        System.out.println("Cube of " + sharedNumber + ": " + cube);
                        sharedNumber = null;
                    }
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
