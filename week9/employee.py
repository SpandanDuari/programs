from functools import reduce

employees = [
    {'name': 'Rahul', 'salary': 5000, 'department': 'Sales'},
    {'name': 'Priya', 'salary': 6000, 'department': 'Marketing'},
    {'name': 'Kumar', 'salary': 7000, 'department': 'Sales'},
    {'name': 'Nalini', 'salary': 8000, 'department': 'Marketing'}
]

names_and_salaries = list(map(lambda x: (x['name'], x['salary']), employees))
print(names_and_salaries)

sales_employees = list(filter(lambda x: x['department'] == 'Sales', employees))
print(sales_employees)

sales_salaries = list(map(lambda x: x['salary'], sales_employees))
average_sales_salary = reduce(lambda x, y: x + y, sales_salaries) / len(sales_salaries)
print(average_sales_salary)