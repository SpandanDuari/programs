import java.util.List;

class Student {
    String name;
    int age;
    double grade;

    public Student(String name, int age, double grade) {
        this.name = name;
        this.age = age;
        this.grade = grade;
    }
}

public class StudentManager {
    // Immutable function to find the average age of all students in the list
    public static double findAverageAge(List<Student> studentList) {
        return studentList.stream()
                .mapToInt(student -> student.age)
                .average()
                .orElse(0.0);
    }

    public static void main(String[] args) {
        List<Student> studentList = List.of(
            new Student("Alice", 20, 88.5),
            new Student("Bob", 21, 92.0),
            new Student("Charlie", 19, 75.0),
            new Student("David", 22, 85.0)
        );

        double averageAge = findAverageAge(studentList);
        System.out.println("The average age of students is: " + averageAge);
    }
}
