#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void push(){
    int x;
    printf("Enter data: ");
    scanf("%d",&x);
    if (top==N-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}

void pop(){
    if (top==-1) printf("Stack Underflow\n");
    else{
        printf("Item deleted= %d\n",stack[top]);
        top--;
    }
}                                                                             

void peek(){
    if (top==-1) printf("Stack Empty\n");
    else printf("Item at the top= %d\n",stack[top]);
}

void display(){
    if (top==-1) printf("Stack Empty\n");
    else{
        for (int i=0;i<N;i++){
            printf("%d\n",stack[i]);
        }
    }
}

void main(){
    int ch;
    do{
        printf("Choose from the following options: 1-push, 2-pop, 3-peek, 4-display, 5-exit\n");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid\n");
        }
    }while(ch!=5);
}