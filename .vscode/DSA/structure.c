#include <stdio.h>

// Define a structure for employee
struct Employee {
    char name[100];
    float basicPay;
    float grossPay;
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Create an array of employees
    struct Employee employees[n];

    // Take input for each employee
    for (int i = 0; i < n; i++) {
        printf("Enter name of employee %d: ", i + 1);
        scanf("%s", employees[i].name);
        printf("Enter basic pay of employee %d: ", i + 1);
        scanf("%f", &employees[i].basicPay);

        // Calculate gross pay
        employees[i].grossPay = employees[i].basicPay + (employees[i].basicPay * 0.2) + (employees[i].basicPay * 0.1);
    }

    // Print gross pay for each employee
    for (int i = 0; i < n; i++) {
        printf("Gross pay of %s is: %.2f\n", employees[i].name, employees[i].grossPay);
    }

    return 0;
}