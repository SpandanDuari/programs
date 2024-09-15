#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5  // Define the maximum size of the queue

int queue[MAX_SIZE];  // Array to store queue elements
int front = -1;  // Front pointer
int rear = -1;   // Rear pointer

// Check if the queue is full
bool isFull() {
    return rear == MAX_SIZE - 1;
}

// Check if the queue is empty
bool isEmpty() {
    return front == -1 || front > rear;
}

// Add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
    } else {
        if (front == -1) {
            front = 0;  // Initialize front when the first element is enqueued
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Delete an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;  // Return -1 when the queue is empty
    } else {
        int dequeuedValue = queue[front];
        front++;
        printf("Dequeued %d\n", dequeuedValue);
        return dequeuedValue;
    }
}

// Display the queue elements
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
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