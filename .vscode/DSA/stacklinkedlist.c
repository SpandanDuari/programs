#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    struct node* newnode;
    struct node* head;
    struct node* ptr;
    struct node* temp;
    int choice=1;
    head=0;
    temp=0;

    while(choice==1){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter newnode data");
        scanf("%d",&newnode->data);
        newnode->next=0;

        if(head==0){
            ptr=head=newnode;
            newnode->next=0;

        }
        else{
            ptr->next=newnode;
            ptr=newnode;
        }
        printf("if u want to add newnode enter 1 or 0 to terminate");
        scanf("%d",&choice);
    }

    temp=head;
    while(temp!=0){
        printf("%d",temp->data);
        temp=temp->next;
    }

    
    //Pushing new element to stack
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter element to be pushed to  stack:");
    scanf("%d",&newnode->data);
    temp=head;
    newnode->next=temp;
    head=newnode;

    temp=head;
    while(temp!=0){
        printf("%d",temp->data);
        temp=temp->next;
    }

    //poping element from stack
    printf("Poping the top most element of stack");
    ptr=head;
    head=head->next;
    free(ptr);

    temp=head;
    while(temp!=0){
        printf("%d",temp->data);
        temp=temp->next;
    }


    
}