import java.util.ArrayList;
import java.util.List;

public class TaskProcessor {
    private List<Task> taskQueue = new ArrayList<>();

    public void addTask(Task task) {
        taskQueue.add(task);
    }

    public void processTasks() {
        for (Task task : taskQueue) {
            task.performCalculation();
            task.generateReport();
        }
    }

    public interface Task {
        void performCalculation();
        void generateReport();
    }

    public static class SquareTask implements Task {
        private int number;
        private int result;

        public SquareTask(int number) {
            this.number = number;
        }

        @Override
        public void performCalculation() {
            result = number * number;
        }

        @Override
        public void generateReport() {
            System.out.println("Number: " + number + " | Squared Result: " + result);
        }
    }

    public static void main(String[] args) {
        TaskProcessor taskProcessor = new TaskProcessor();

        taskProcessor.addTask(new SquareTask(5));
        taskProcessor.addTask(new SquareTask(10));
        taskProcessor.addTask(new SquareTask(15));

        taskProcessor.processTasks();
    }
}
