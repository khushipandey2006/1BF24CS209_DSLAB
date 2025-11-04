#include <stdio.h>
#define N 5
int front=-1;
int rear=-1;
int queue[N];
void enqueue(){
    int x;
    printf("Enter an element:");
    scanf("%d",&x);
    if (front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if(rear==N-1){
        printf("Queue is full\n");
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void dequeue(){
    if (front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else if (front==rear){
        printf("Dequeued element=%d\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("Dequeued element=%d\n",queue[front]);
        front++;
    }
}
void display(){
    if (front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("The elements in the queue are:\n");
        for (int i=0;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
}

int main(){
    int c;
    printf("Choose: 1.enqueue, 2.dequeue, 3.display, 4.exit\n");
    scanf("%d",&c);
    while(c!=4){
        switch(c){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Exit\n");
        }
        printf("Choose: 1.enqueue, 2.dequeue, 3.display, 4.exit\n");
        scanf("%d",&c);
    }
}