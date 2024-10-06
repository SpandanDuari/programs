// Stack implementation using array
#include <stdio.h>
#define MAX_SIZE 10

int main()
{
    int arr[MAX_SIZE];
    int i, val, TOP=-1, n;
    int choice;
    printf("Enter total number of elements you want to add to stack:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Stack element:");
        scanf("%d", &arr[i]);
    }
    printf("enter 1 to add element to stack or 2 to delete element from stack:");
    scanf("%d", &choice);
    TOP = n - 1;
    switch (choice)
    {
    case 1:
        printf("enter element that u want to add to  original stack");
        scanf("%d", &val);

        
        if (TOP == MAX_SIZE - 1)
        {
            printf("overflow");
        }
        else
        {
            TOP = TOP + 1;
            arr[TOP] = val;
        }
        break;

        case 2:
        printf("Deleting the top element of stack");
        if(TOP == -1){
            printf("underflow");
        }
        else{
            TOP=TOP-1;
        }
        break;

        default:
        printf("invalid choice");

    }

    for (i = 0; i <= TOP; i++)
    {
        printf("%d", arr[i]);
    }
}