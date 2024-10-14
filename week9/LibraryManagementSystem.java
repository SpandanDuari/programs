import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

// Book class to store book information
class Book {
    String title, author, isbn, genre;
    int publicationYear;
    boolean available;

    public Book(String title, String author, String isbn, int publicationYear, String genre, boolean available) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.publicationYear = publicationYear;
        this.genre = genre;
        this.available = available;
    }
}

public class LibraryManagementSystem extends JFrame {
    private ArrayList<Book> bookList = new ArrayList<>();
    private JTextField titleField, authorField, isbnField, yearField, searchField;
    private JComboBox<String> genreComboBox;
    private JCheckBox availabilityCheckBox;
    private DefaultTableModel tableModel;

    public LibraryManagementSystem() {
        setTitle("Library Management System");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Setup menu bar
        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        JMenu editMenu = new JMenu("Edit");
        JMenu helpMenu = new JMenu("Help");
        menuBar.add(fileMenu);
        menuBar.add(editMenu);
        menuBar.add(helpMenu);
        setJMenuBar(menuBar);

        // Setup tool bar
        JToolBar toolBar = new JToolBar();
        JButton addButton = new JButton("Add Book");
        JButton removeButton = new JButton("Remove Book");
        JButton searchButton = new JButton("Search");
        toolBar.add(addButton);
        toolBar.add(removeButton);
        toolBar.add(searchButton);
        add(toolBar, BorderLayout.NORTH);

        // Tabbed pane setup
        JTabbedPane tabbedPane = new JTabbedPane();
        JPanel bookDetailsPanel = createBookDetailsPanel();
        JPanel bookListPanel = createBookListPanel();
        tabbedPane.addTab("Book Details", bookDetailsPanel);
        tabbedPane.addTab("Book List", bookListPanel);
        add(tabbedPane, BorderLayout.CENTER);

        // Add button action listener for adding a book
        addButton.addActionListener(e -> addBook());

        // Remove button action listener for removing a book
        removeButton.addActionListener(e -> removeBook());

        // Search button action listener for searching books
        searchButton.addActionListener(e -> searchBook());
    }

    // Create Book Details Panel
    private JPanel createBookDetailsPanel() {
        JPanel panel = new JPanel(new GridLayout(6, 2, 10, 10));

        panel.add(new JLabel("Title:"));
        titleField = new JTextField();
        panel.add(titleField);

        panel.add(new JLabel("Author:"));
        authorField = new JTextField();
        panel.add(authorField);

        panel.add(new JLabel("ISBN:"));
        isbnField = new JTextField();
        panel.add(isbnField);

        panel.add(new JLabel("Publication Year:"));
        yearField = new JTextField();
        panel.add(yearField);

        panel.add(new JLabel("Genre:"));
        genreComboBox = new JComboBox<>(new String[]{"Fiction", "Non-Fiction", "Science", "Biography"});
        panel.add(genreComboBox);

        availabilityCheckBox = new JCheckBox("Available");
        panel.add(availabilityCheckBox);

        JButton addBookButton = new JButton("Add Book");
        addBookButton.addActionListener(e -> addBook());
        panel.add(addBookButton);

        JButton updateBookButton = new JButton("Update Book");
        updateBookButton.addActionListener(e -> updateBook());
        panel.add(updateBookButton);

        return panel;
    }

    // Create Book List Panel
    private JPanel createBookListPanel() {
        JPanel panel = new JPanel(new BorderLayout());

        String[] columnNames = {"Title", "Author", "ISBN", "Genre", "Available"};
        tableModel = new DefaultTableModel(columnNames, 0);
        JTable bookTable = new JTable(tableModel);
        JScrollPane scrollPane = new JScrollPane(bookTable);
        panel.add(scrollPane, BorderLayout.CENTER);

        JPanel searchPanel = new JPanel(new BorderLayout());
        searchField = new JTextField();
        JButton searchButton = new JButton("Search");
        searchButton.addActionListener(e -> searchBook());
        searchPanel.add(searchField, BorderLayout.CENTER);
        searchPanel.add(searchButton, BorderLayout.EAST);
        panel.add(searchPanel, BorderLayout.NORTH);

        return panel;
    }

    // Method to add a book to the list
    private void addBook() {
        String title = titleField.getText();
        String author = authorField.getText();
        String isbn = isbnField.getText();
        int year = Integer.parseInt(yearField.getText());
        String genre = (String) genreComboBox.getSelectedItem();
        boolean available = availabilityCheckBox.isSelected();

        Book book = new Book(title, author, isbn, year, genre, available);
        bookList.add(book);
        tableModel.addRow(new Object[]{title, author, isbn, genre, available});
        JOptionPane.showMessageDialog(this, "Book added successfully.", "Success", JOptionPane.INFORMATION_MESSAGE);
    }

    // Method to update an existing book
    private void updateBook() {
        JOptionPane.showMessageDialog(this, "Update functionality to be implemented.", "Information", JOptionPane.INFORMATION_MESSAGE);
    }

    // Method to remove a book from the list
    private void removeBook() {
        int selectedRow = tableModel.getRowCount() - 1;
        if (selectedRow >= 0) {
            tableModel.removeRow(selectedRow);
            bookList.remove(selectedRow);
            JOptionPane.showMessageDialog(this, "Book removed successfully.", "Success", JOptionPane.INFORMATION_MESSAGE);
        } else {
            JOptionPane.showMessageDialog(this, "No book selected to remove.", "Warning", JOptionPane.WARNING_MESSAGE);
        }
    }

    // Method to search for books
    private void searchBook() {
        String searchText = searchField.getText().toLowerCase();
        for (Book book : bookList) {
            if (book.title.toLowerCase().contains(searchText) || book.author.toLowerCase().contains(searchText)) {
                JOptionPane.showMessageDialog(this, "Book found: " + book.title + " by " + book.author, "Search Result", JOptionPane.INFORMATION_MESSAGE);
                return;
            }
        }
        JOptionPane.showMessageDialog(this, "Book not found.", "Search Result", JOptionPane.INFORMATION_MESSAGE);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            LibraryManagementSystem libraryApp = new LibraryManagementSystem();
            libraryApp.setVisible(true);
        });
    }
}
