#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

/* ---------------- STACK FUNCTIONS ---------------- */

void push(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;

    printf("Inserted %d\n", data);
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node *temp = top;
    top = top->next;

    printf("Deleted %d\n", temp->data);
    free(temp);
}

void displayStack() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


/* ---------------- QUEUE FUNCTIONS ---------------- */

void enqueue(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted %d\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted %d\n", temp->data);

    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


/* ---------------- MAIN PROGRAM ---------------- */

int main() {
    int ch;

    printf("Enter 1 for Stack implementation, 2 for Queue implementation: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            printf("\n--- STACK IMPLEMENTATION ---\n");
            printf("1: Push\n2: Pop\n3: Display\n0: Exit\n");

            do {
                printf("\nEnter your choice: ");
                scanf("%d", &ch);

                switch (ch) {
                    case 1: {
                        int x;
                        printf("Enter element to insert: ");
                        scanf("%d", &x);
                        push(x);
                        break;
                    }
                    case 2:
                        pop();
                        break;

                    case 3:
                        displayStack();
                        break;

                    case 0:
                        printf("Exiting stack menu\n");
                        break;

                    default:
                        printf("Invalid choice\n");
                }

            } while (ch != 0);
            break;

        case 2:
            printf("\n--- QUEUE IMPLEMENTATION ---\n");
            printf("1: Enqueue\n2: Dequeue\n3: Display\n0: Exit\n");

            do {
                printf("\nEnter your choice: ");
                scanf("%d", &ch);

                switch (ch) {
                    case 1: {
                        int x;
                        printf("Enter element to insert: ");
                        scanf("%d", &x);
                        enqueue(x);
                        break;
                    }
                    case 2:
                        dequeue();
                        break;

                    case 3:
                        displayQueue();
                        break;

                    case 0:
                        printf("Exiting queue menu\n");
                        break;

                    default:
                        printf("Invalid choice\n");
                }

            } while (ch != 0);
            break;

        default:
            printf("Invalid choice — please enter 1 or 2\n");
    }

    return 0;
}