#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL,* tail = NULL;

void createList(int n){
    int data,i;
    struct Node* newNode;
    for (i=1;i<=n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=newNode->prev=NULL;
        if (head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
    }
    printf("Doubly Linked List created with %d nodes.\n",n);
}

void insertAtBeginning(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (head==NULL){
        head=tail=newNode;
        return;
    }
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    head = newNode;
}

void insertEnd(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (head==NULL){
        head=tail=newNode;
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void insertPos(int data,int pos){
    struct Node* newNode,* temp=head;
    if (pos==1){
        insertAtBeginning(data);
        return;
    }
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    for (int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if (temp==NULL || temp->next==NULL){
        insertEnd(data);
        return;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;
}

void deleteFront(){
    struct Node* temp=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    if (head==tail){
        head=tail=NULL;
    }
    else{
        head=head->next;
        head->prev=NULL;
    }
    free(temp);
}

void deleteEnd(){
    struct Node* temp=tail;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    if (head==tail){
        head=tail=NULL;
    }
    else{
        tail=tail->prev;
        tail->next=NULL;
    }
    free(temp);
}

void deleteSpecific(int value){
    struct Node* temp=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    while (temp!=NULL && temp->data!=value){
        temp=temp->next;
    }
    if (temp==NULL){
        printf("Value not found in the list\n");
        return;
    }
    if (temp==head){
    deleteFront();
    }
    else if (temp==tail){
        deleteEnd();
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}

void display(){
    struct Node* temp=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp!=NULL){
        printf("%d<-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int n,choice,data,pos,value;
    printf("\nMenu:\n1. Create List\n2. Insert at Position\n3. Delete Specific Value \n4. Display List\n5.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    while(choice!=5){
        switch(choice){
            case 1:
                printf("Enter the number of nodes to create: ");
                scanf("%d",&n);
                createList(n);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                printf("Enter position to insert at: ");
                scanf("%d",&pos);
                insertPos(data,pos);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d",&value);
                deleteSpecific(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("Enter your choice: ");
        scanf("%d",&choice);
    }
    return 0;
}