#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

int main()
{
    struct node *head;
    struct node *ptr;
    struct node *newnode;
    struct node *temp;
    struct node *temp1;
    int val;

    head = 0;
    int choice=1;

    while (choice == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter new node data");
        scanf("%d", &newnode->data);

        newnode->prev = 0;
        newnode->next = 0;
        if (head == 0)
        {
            head = ptr = newnode;
            ptr->prev = 0;
        }
        else
        {
            ptr->next = newnode;
            newnode->prev = ptr;
            ptr = newnode;
        }

        printf("enter 1 insert a node or 0 to terminate");
        scanf("%d", &choice);
    }

    temp = head;
    while (temp != 0)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    // Insertion of new node at the beginning

    printf("inserting a new node at the beginning\n");
    newnode = (struct node *)malloc(sizeof(struct node *));
    printf("enter new node data");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->prev = 0;

    newnode->next = head;
    head->prev = newnode;
    head = newnode;

    temp = head;
    while (temp != 0)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    // Inserting a new node at the end

    printf("inserting a new node at the end of the list\n");
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter new node data\n");
    scanf("%d", &newnode->data);

    newnode->next = 0;
    newnode->prev = 0;

    ptr = head;
    while (ptr->next != 0)
    {
        ptr = ptr->next;
    }
    newnode->prev = ptr;
    ptr->next = newnode;

    temp = head;
    while (temp != 0)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    // Inserting a new node after a given node
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data of newnode that you want to add after a node");
    scanf("%d", &newnode->data);
    printf("enter data of node after which you want to enter the new node");
    scanf("%d", &val);

    ptr = head;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }

    newnode->next = ptr->next;
    ptr->next->prev = newnode;
    ptr->next = newnode;

    temp = head;
    while (temp != 0)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    //Inserting a newnode before a given node

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter newnode data");
    scanf("%d",&newnode->data);

    newnode->next=0;
    newnode->prev=0;

    printf("enter node data before which you want to enter new node");
    scanf("%d",&val);

    ptr=head;
    while(ptr->data!=val){
        ptr=ptr->next;
    }
    
    ptr->prev->next=newnode;
    newnode->prev=ptr->prev;
    newnode->next=ptr;
    ptr->prev=newnode;

    temp=head;
    while(temp!=0){
        printf("%d\n",temp->data);
        temp=temp->next;
    }

    //Deletion of first node 
    printf("deleting the first node\n");
    temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    free(temp);

    ptr=head;
    while(ptr!=0){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

    //Deletion of the last node
    

    printf("Deleting the last node\n");
    ptr=head;
    while(ptr->next!=0){
        ptr=ptr->next;
    }
    ptr->prev->next=0;
    free(ptr);

    ptr=head;
    while(ptr!=0){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }


    //Deletion after a given node

    printf("enter data of node of which you want to delete next node");
    scanf("%d",&val);

    ptr=head;
    while(ptr->data!=val){
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);

    ptr=head;
    while(ptr!=0){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

    //Deleting the node before the given node
    printf("enter value of node to delete the node before it ");
    scanf("%d",&val);

    ptr=head;
    while(ptr->data!=val){
        ptr=ptr->next;
    }

    temp=ptr->prev;
    temp->prev->next=ptr;
    ptr->prev=temp->prev;
    

    free(temp);

    ptr=head;
    while(ptr!=0){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }

    



    
}