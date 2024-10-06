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

struct Node *deleteatstart(struct Node *head)
{
    struct Node *ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}
struct Node *deleteatIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    int i=0;
    while(i!=index)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteatend(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head;
    while (ptr->next != NULL)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return head;
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
    printf("\n");
    head = deleteatIndex(head,2);
    Traverse(head);

    return 0;
}
