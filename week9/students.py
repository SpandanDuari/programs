def add_student(students, name, age, grade):
    students.append({'name': name, 'age': age, 'grade': grade})

def average_age(students):
    total_age = sum(student['age'] for student in students)
    return total_age / len(students) if students else 0

students_list = []

add_student(students_list, 'Alice', 20, 'A')
add_student(students_list, 'Bob', 22, 'B')
add_student(students_list, 'Charlie', 21, 'A')

print("Student Records:", students_list)

avg_age = average_age(students_list)
print(f"Average Age: {avg_age}")