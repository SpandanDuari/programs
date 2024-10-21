# Pure Function: Find the maximum value in a list
def find_max(numbers):
    return max(numbers)

# Impure Function: Sort a list in ascending order
def sort_numbers():
    numbers = [int(x) for x in input("Enter numbers separated by space: ").split()]
    numbers.sort()
    print(f"Sorted list: {numbers}")

# Example Usage
numbers_list = [3, 5, 1, 9, 2]
print(f"Maximum value in the list: {find_max(numbers_list)}")

sort_numbers()
