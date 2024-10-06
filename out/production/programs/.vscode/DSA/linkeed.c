#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data); 
        ptr = ptr->next; 
    }
    
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 66;
    head->next = second;
    second->data = 76;
    second->next = third;
    third->data = 45;
    third->next = NULL;

    Traverse(head);

    return 0;
}