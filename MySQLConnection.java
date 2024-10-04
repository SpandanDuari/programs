import java.sql.*;


public class MySQLConnection {
    // Database URL, Username, and Password
    static final String JDBC_URL = "jdbc:mysql://localhost:3306/mydb"; // Replace with your database name
    static final String USER = "root"; // Replace with your username
    static final String PASS = "Spandan1234#"; // Replace with your password

    public static void main(String[] args) {
        Connection conn = null;
        try {
            // 1. Register JDBC driver (optional for newer JDBC versions, but safe to include)
            Class.forName("com.mysql.cj.jdbc.Driver");

            // 2. Open a connection
            System.out.println("Connecting to database...");
            conn = DriverManager.getConnection(JDBC_URL, USER, PASS);

            System.out.println("Connected successfully!");

        } catch (SQLException se) {
            // Handle errors for JDBC
            se.printStackTrace();
        } catch (Exception e) {
            // Handle errors for Class.forName
            e.printStackTrace();
        } finally {
            // Close connection
            try {
                if (conn != null) conn.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }
    }
}
