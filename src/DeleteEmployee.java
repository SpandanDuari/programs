import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class DeleteEmployee {
    static final String JDBC_URL = "jdbc:mysql://localhost:3306/testcon";
    static final String USER = "root";
    static final String PASSWORD = "Spandan1234#";

    public static void main(String[] args) {
        Connection connection = null;
        PreparedStatement preparedStatement = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(JDBC_URL, USER, PASSWORD);

            String sql = "DELETE FROM employees WHERE employee_id = ?";
            preparedStatement = connection.prepareStatement(sql);

            preparedStatement.setInt(1, 1); // Specify the employee_id to delete

            int rowsDeleted = preparedStatement.executeUpdate();

            if (rowsDeleted > 0) {
                System.out.println("An employee was deleted successfully");
            } else {
                System.out.println("No employee found with the specified ID.");
            }

        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            try {
                if (preparedStatement != null) preparedStatement.close();
                if (connection != null) connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
