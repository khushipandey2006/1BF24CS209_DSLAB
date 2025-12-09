#include<stdio.h>
#define N 5
int front=-1;
int rear=-1;
int queue[N];
void enqueue(){
    int x;
    printf("Enter an element: \n");
    scanf("%d",&x);
    if (front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front){
        printf("Queue is full\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if (front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        printf("Dequeued element=%d\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("Dequeued element=%d\n",queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    printf("The elements are:\n");
    if (front==-1 && rear==-1){
        printf("Queue is empty\n");
        return;
    }
    else{
        if (front<rear){
            for (int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
            }
        }
        else{
            for (int i=front;i<N;i++){
                printf("%d\n",queue[i]);
            }
            for (int i=0;i<=rear;i++){
                printf("%d\n",queue[i]);
            }
        }
        
    }
    printf("\n");
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
        case 4:
            printf("Exit");
            break;
        default:
            printf("Invalid\n");
        }
        printf("Choose: \n");
        scanf("%d",&c);
    }
}