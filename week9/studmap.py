from functools import reduce

students = [
    {'name': 'Rohan', 'age': 20, 'grade': 85},
    {'name': 'Aisha', 'age': 22, 'grade': 90},
    {'name': 'Karan', 'age': 19, 'grade': 78},
    {'name': 'Neha', 'age': 21, 'grade': 92}
]

names = list(map(lambda x: x['name'], students))
print(names)

adult_students = list(filter(lambda x: x['age'] >= 21, students))
print(adult_students)

grades = list(map(lambda x: x['grade'], students))
average_grade = reduce(lambda x, y: x + y, grades) / len(grades)
print(average_grade)