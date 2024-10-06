#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the queue is empty
int isEmpty(struct Node *front)
{
    return (front == NULL);
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Node **front, struct Node **rear, int value)
{
    struct Node *newNode = createNode(value);
    if (*rear == NULL)
    {
        *front = *rear = newNode;
        printf("Enqueued %d\n", value);
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
    printf("Enqueued %d\n", value);
}

// Function to delete an element from the queue (dequeue)
int dequeue(struct Node **front, struct Node **rear)
{
    if (isEmpty(*front))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    struct Node *temp = *front;
    int dequeuedValue = temp->data;
    *front = (*front)->next;

    if (*front == NULL)
    {
        *rear = NULL;
    }

    free(temp);
    printf("Dequeued %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the queue elements
void displayQueue(struct Node *front)
{
    if (isEmpty(front))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        struct Node *temp = front;
        printf("Queue: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Node *front = NULL;
    struct Node *rear = NULL;
    int choice, value;

    do
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&front, &rear, value);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            displayQueue(front);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}