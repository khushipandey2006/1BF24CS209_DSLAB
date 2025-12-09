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

void insertBegin(int data){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=head;
    head=newNode;
    printf("Node inserted at beginning.\n");
}

void inserEnd(int data){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if (head==NULL){
        head=newNode;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Node inserted at end.\n");
}

void insertAtPos(int pos,int data){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    temp=head;
    if (pos<1){
        printf("Invalid.\n");
        return;
    }
    if (pos==1){
        insertBegin(data);
        return;
    }
    newNode->data=data;
    for (int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if (temp==NULL){
        printf("Position out of range.\n");
        free(newNode);
    }
    else{
        newNode->next=temp->next;
        temp->next=newNode;
        printf("Value entered at position: %d\n",pos);
    }
}

void display(){
    if (head==NULL){
        printf("Empty list.\n");
        return;
    }
    struct Node *temp=head;
    printf("Linked List : \n");
    while(temp-> next!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

int main(){
    int data,n,pos,ch;
    while(1){
        printf("Choose operation from the following to perform on singly linked list:\n");
        printf("1. Create a linked list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at a specific position\n");
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
                printf("Enter data to insert: ");
                scanf("%d",&data);
                insertBegin(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d",&data);
                inserEnd(data);
                break;
            case 4: 
                printf("Enter data and position: ");
                scanf("%d",&data);
                scanf("%d",&pos);
                insertAtPos(pos,data);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exited");
                break;
            default:
                printf("Invalid");
        }
    }
    return 0;
}