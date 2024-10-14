import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ListSorter {
    // Impure function that sorts a list of numbers in ascending order
    public static void sortNumbers(List<Integer> numbers) {
        Collections.sort(numbers);  // This operation modifies the original list
    }

    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>(List.of(10, 20, 5, 8, 30));
        System.out.println("Original list: " + numbers);

        sortNumbers(numbers);  // The list is modified here
        System.out.println("Sorted list: " + numbers);
    }
}
