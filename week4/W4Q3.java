import java.util.Scanner;

public class W4Q3 {
    private static final int CART_SIZE = 10;
    private double[] prices = new double[CART_SIZE];
    private Scanner scanner = new Scanner(System.in);

    public void addProducts() {
        System.out.println("Enter " + CART_SIZE + " product prices:");
        for (int i = 0; i < prices.length; i++) {
            System.out.print("Price for product " + (i + 1) + ": ");
            while (!scanner.hasNextDouble()) {
                System.out.println("Invalid input. Please enter a numeric value.");
                scanner.next(); // Clear invalid input
                System.out.print("Price for product " + (i + 1) + ": ");
            }
            prices[i] = scanner.nextDouble();
        }
    }

    public void removeProduct(int index) {
        if (index >= 0 && index < prices.length) {
            prices[index] = 0;
        } else {
            System.out.println("Invalid index. No product removed.");
        }
    }

    public double calculateTotalPrice() {
        double total = 0;
        for (double price : prices) {
            total += price;
        }
        return total;
    }

    public void findMostAndLeastExpensive() {
        double mostExpensive = 0;
        double leastExpensive = Double.MAX_VALUE;
        boolean hasValidPrice = false;

        for (double price : prices) {
            if (price > mostExpensive) mostExpensive = price;
            if (price > 0) { // Only consider prices greater than 0 for least expensive
                if (price < leastExpensive) leastExpensive = price;
                hasValidPrice = true;
            }
        }

        System.out.println("Most Expensive: " + mostExpensive);
        if (hasValidPrice) {
            System.out.println("Least Expensive: " + leastExpensive);
        } else {
            System.out.println("Least Expensive: None");
        }
    }

    public static void main(String[] args) {
        W4Q3 cart = new W4Q3();
        cart.addProducts();
        cart.removeProduct(2); // Remove the 3rd product
        System.out.println("Total Price: " + cart.calculateTotalPrice());
        cart.findMostAndLeastExpensive();
    }
}
