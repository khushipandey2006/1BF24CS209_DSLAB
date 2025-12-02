#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// -------------------- Display --------------------
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// -------------------- Sorting --------------------
struct node * sortList(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("Linked list sorted\n");
    return head;
}

// -------------------- Reverse --------------------
struct node * reverseLinkedList(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    printf("Linked list reversed\n");
    return prev;
}

// -------------------- Concatenate --------------------
struct node * concatenateLists(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct node *temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    printf("Lists concatenated\n");
    return head1;
}

// -------------------- Create List --------------------
struct node * createList(int n) {
    if (n <= 0) {
        printf("Number of nodes must be > 0\n");
        return NULL;
    }

    struct node *head = NULL, *temp = NULL, *newNode;

    for (int i = 1; i <= n; i++) {
        newNode = malloc(sizeof(struct node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            return head;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    return head;
}

// -------------------- MAIN --------------------
int main() {
    int ch, n, m, n1, n2;
    struct node *head = NULL, *head2 = NULL;

    printf("1: Sort list\n2: Reverse list\n3: Concatenate lists\n0: Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        if (ch == 0) break;

        switch (ch) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                head = createList(n);
                head = sortList(head);
                display(head);
                break;

            case 2:
                printf("Enter number of nodes: ");
                scanf("%d", &m);
                head = createList(m);
                head = reverseLinkedList(head);
                display(head);
                break;

            case 3:
                printf("Enter number of nodes in list 1 and 2: ");
                scanf("%d %d", &n1, &n2);
                head = createList(n1);
                head2 = createList(n2);
                head = concatenateLists(head, head2);
                display(head);
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


