import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {

    // JDBC URL, username, and password of MySQL server
    static final String JDBC_URL = "jdbc:mysql://localhost:3306/testcon"; // Update with your DB name
    static final String USER = "root"; // Update with your DB username
    static final String PASSWORD = "Spandan1234#"; // Update with your DB password

    public static void main(String[] args) {
        Connection connection = null;

        try {
            // 1. Load the MySQL JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver"); // Optional for newer versions of Java

            // 2. Establish the connection
            connection = DriverManager.getConnection(JDBC_URL, USER, PASSWORD);

            if (connection != null) {
                System.out.println("Connection to the MySQL database established successfully!");
            } else {
                System.out.println("Failed to connect to the MySQL database.");
            }

        } catch (SQLException e) {
            // Handle SQL errors
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            // Handle error for Class.forName (if the driver class is not found)
            e.printStackTrace();
        } finally {
            try {
                // 3. Close the connection
                if (connection != null) {
                    connection.close();
                    System.out.println("Connection closed successfully.");
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
