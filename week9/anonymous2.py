numbers = [1, 2, 3, 4]
squared_numbers = list(map(lambda x: x ** 2, numbers))
print(squared_numbers)

numbers = [1, 2, 3, 4, 5, 6]
even_numbers = list(filter(lambda x: x % 2 == 0, numbers))
print(even_numbers)