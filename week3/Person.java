public class Person {
    // attributes
    String name;
    int age;
    String address;

    // default constructor
    public Person() {
        this.name = "Unknown";
        this.age = 0;
        this.address = "Unknown";
    }

    // parameterized constructor
    public Person(String name, int age, String address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }

    // method to display person information
    public void displayPersonInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Address: " + address);
    }

    public static void main(String[] args) {
        // create two Person objects
        Person person1 = new Person(); // using default constructor
        Person person2 = new Person("John Doe", 30, "123 Main St"); // using parameterized constructor

        // display information for both objects
        System.out.println("Person 1 Information:");
        person1.displayPersonInfo();
        System.out.println();

        System.out.println("Person 2 Information:");
        person2.displayPersonInfo();
    }
}