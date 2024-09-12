import bubblesort.BubbleSort;
import java.util.Arrays;
import selectionsort.SelectionSort;

public class SortTest {
    public static void main(String[] args) {
        int[] array1 = {64, 34, 25, 12, 22, 11, 90};
        int[] array2 = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original Array: " + Arrays.toString(array1));

        // Bubble Sort
        BubbleSort bubbleSort = new BubbleSort();
        bubbleSort.sort(array1);
        System.out.println("Array after Bubble Sort: " + Arrays.toString(array1));

        // Selection Sort
        SelectionSort selectionSort = new SelectionSort();
        selectionSort.sort(array2);
        System.out.println("Array after Selection Sort: " + Arrays.toString(array2));
    }
}
