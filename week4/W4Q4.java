import java.util.*;
import java.util.stream.Collectors;

class Order {
    private String orderId;
    private String customerName;
    private double orderAmount;
    private String orderStatus;

    public Order(String orderId, String customerName, double orderAmount, String orderStatus) {
        this.orderId = orderId;
        this.customerName = customerName;
        this.orderAmount = orderAmount;
        this.orderStatus = orderStatus;
    }

    public String getOrderId() { return orderId; }
    public double getOrderAmount() { return orderAmount; }
    public String getOrderStatus() { return orderStatus; }

    @Override
    public String toString() {
        return orderId + " " + orderStatus + " " + orderAmount;
    }
}

public class W4Q4 {
    public static void main(String[] args) {
        List<Order> orders = Arrays.asList(
            new Order("1", "Alice", 250.00, "Pending"),
            new Order("2", "Bob", 150.00, "Shipped"),
            new Order("3", "Charlie", 200.00, "Delivered"),
            new Order("4", "David", 300.00, "Cancelled"),
            new Order("5", "Eve", 180.00, "Pending")
        );

        List<Order> pendingOrders = orders.stream()
            .filter(o -> "Pending".equals(o.getOrderStatus()))
            .collect(Collectors.toList());
        System.out.println("Pending Orders: " + pendingOrders);

        double totalAmount = orders.stream()
            .mapToDouble(Order::getOrderAmount)
            .sum();
        System.out.println("Total Amount: " + totalAmount);

        Order maxOrder = orders.stream()
            .max(Comparator.comparingDouble(Order::getOrderAmount))
            .orElse(null);
        System.out.println("Most Expensive Order: " + maxOrder);

        List<Order> sortedOrders = orders.stream()
            .sorted(Comparator.comparingDouble(Order::getOrderAmount))
            .collect(Collectors.toList());
        System.out.println("Orders Sorted by Amount: " + sortedOrders);
    }
}