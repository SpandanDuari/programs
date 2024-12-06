package week8;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class UpdateOrder {
    static final String JDBC_URL = "jdbc:mysql://localhost:3306/testcon";
    static final String USER = "root";
    static final String PASSWORD = "Spandan1234#";

    public static void main(String[] args) {
        Connection connection = null;
        PreparedStatement preparedStatement = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(JDBC_URL, USER, PASSWORD);

            String sql = "UPDATE orders SET quantity = ?, total_amount = ? WHERE order_id = ?";
            preparedStatement = connection.prepareStatement(sql);

            preparedStatement.setInt(1, 4); // Update quantity to 4
            preparedStatement.setBigDecimal(2, new java.math.BigDecimal("4800.00")); // Update total amount
            preparedStatement.setInt(3, 1); // Update where order_id is 1

            int rowsUpdated = preparedStatement.executeUpdate();

            if (rowsUpdated > 0) {
                System.out.println("An existing order was updated successfully!");
            }

        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
