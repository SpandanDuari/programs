package week8;

import java.sql.ResultSet;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class Select
 {
    // JDBC URL, username, and password for MySQL
    static final String JDBC_URL = "jdbc:mysql://localhost:3306/testcon";  // Replace with your database name
    static final String USER = "root";  // Replace with your MySQL username
    static final String PASSWORD = "Spandan1234#";  // Replace with your MySQL password

    public static void main(String[] args) {
        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

        try {
            // 1. Load the MySQL JDBC driver (optional for newer versions of Java)
            Class.forName("com.mysql.cj.jdbc.Driver");

            // 2. Establish a connection to the database
            connection = DriverManager.getConnection(JDBC_URL, USER, PASSWORD);

            // 3. Create a statement object to execute the SQL query
            statement = connection.createStatement();

            // 4. Execute the SQL SELECT query
            String sql = "SELECT * FROM customers";
            resultSet = statement.executeQuery(sql);

            // 5. Process the result set
            while (resultSet.next()) {
                // Retrieve data from each row
                int customerId = resultSet.getInt("customer_id");
                String firstName = resultSet.getString("first_name");
                String lastName = resultSet.getString("last_name");
                String email = resultSet.getString("email");
                String phone = resultSet.getString("phone_number");

                // Print the data to the console
                System.out.println("Customer ID: " + customerId);
                System.out.println("First Name: " + firstName);
                System.out.println("Last Name: " + lastName);
                System.out.println("Email: " + email);
                System.out.println("Phone Number: " + phone);
                System.out.println("-------------------------------");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}


