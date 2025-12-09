#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left, *right;
};
struct Node * createNode(int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    } 
    else if (val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(struct Node* root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root){
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void display(struct Node *root){
    printf("BST Elements:\n");
    inorder(root);
    printf("\n");
}

int main(){
    struct Node *root=NULL;
    int choice, val;
    while(1){
        printf("1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Display BST\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice!=6){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                display(root);
                break;
            case 6:
                printf("Exit\n");
            default:
                printf("Invalid choice!\n");
        } 
    }  
}