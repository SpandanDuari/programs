import math

def calculate_circle_area(radius):
    return math.pi * radius * radius

def get_radius_and_print_area():
    radius = float(input("Enter the radius of the circle: "))
    area = calculate_circle_area(radius)
    print(f"The area of the circle with radius {radius} is {area}")

get_radius_and_print_area()
