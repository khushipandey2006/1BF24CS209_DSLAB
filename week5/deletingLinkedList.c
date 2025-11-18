#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL,*newNode,*temp;

void createList(int n){
    int data,i;
    if (n<=0){
        printf("List should be greater than 0 nodes.\n");
        return;
    }
    for (i=1;i<=n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        if (newNode==NULL){
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;
        if (head==NULL){
            head=newNode;
        }
        else{
            temp->next=newNode;
        }
        temp=newNode;
    }
}

void deleteFirst(){
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    temp=head;
    head=head->next;
    printf("Deleted data: %d\n",temp->data);
    free(temp);
}

void deleteLast(){
    if (head==NULL){
        printf("Empty list\n");
        return;
    }
    if (head->next==NULL){
        printf("Deleted data: %d\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node *prev=NULL;
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    printf("Deleted data: %d\n",temp->data);
    free(temp);
    prev->next=NULL;
}

void deleteSpecific(int val){
    if (head==NULL){
        printf("Empty list\n");
        return;
    }
    temp=head;
    if (head->data==val){
        head=head->next;
        printf("Deleted data : %d\n",temp->data);
        free(temp);
        return;
    }
    struct Node *prev=NULL;
    while(temp!=NULL && temp->data!=val){
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL){
        printf("Element not found.\n");
        return;
    }
    prev->next=temp->next;
    printf("Deleted data: %d\n",temp->data);
    free(temp);
}

void display(){
    if (head==NULL){
        printf("Empty list.\n");
        return;
    }
    struct Node *temp=head;
    printf("Linked List : \n");
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int data,n,ch;
    while(ch!=6){
        printf("Choose operation from the following to perform on singly linked list:\n");
        printf("1. Create a linked list\n");
        printf("2. Delete at beginning\n");
        printf("3. Delete at end\n");
        printf("4. Delete at a specific position\n");
        printf("5. Display linked list\n");
        printf("6. Exit \n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter no. of nodes: ");
                scanf("%d",&n);
                createList(n);
                break;
            case 2:
                deleteFirst();
                break;
            case 3:
                deleteLast();
                break;
            case 4: 
                printf("Enter data to be deleted: ");
                scanf("%d",&data);
                deleteSpecific(data);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exited\n");
                break;
            default:
                printf("Invalid");
        }
    }
    return 0;
}