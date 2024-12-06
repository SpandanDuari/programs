package week8;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {
    static final String JDBC_URL = "jdbc:mysql://localhost:3306/testcon";
    static final String USER = "root";
    static final String PASSWORD = "Spandan1234#";

    public Main() {
    }

    public static void main(String[] args) {
        Connection connection = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/testcon", "root", "Spandan1234#");
            if (connection != null) {
                System.out.println("Connection to the MySQL database established successfully!");
            } else {
                System.out.println("Failed to connect to the MySQL database.");
            }
        } catch (SQLException var13) {
            SQLException e = var13;
            e.printStackTrace();
        } catch (ClassNotFoundException var14) {
            ClassNotFoundException e = var14;
            e.printStackTrace();
        } finally {
            try {
                if (connection != null) {
                    connection.close();
                    System.out.println("Connection closed successfully.");
                }
            } catch (SQLException var12) {
                SQLException e = var12;
                e.printStackTrace();
            }

        }

    }
}
