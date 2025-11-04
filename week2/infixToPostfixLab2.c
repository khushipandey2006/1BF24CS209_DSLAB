#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
int precedence(char o){
    if (o=='+' || o=='-') return 1;
    else if (o=='*' || o=='/') return 2;
    else if (o=='^') return 3;
    else if (o=='(') return 0;
}
int associativity(char o){
    if (o=='^') return 1;
    else return 0;
}
void push(char x){
    if (top==MAX-1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=x;
}
char pop(){
    if (top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}
char peek(){
    if (top==-1) printf("Stack is empty\n");
    return stack[top];
}
void infixtopostfix(char infix[],char postfix[]){
    int p=0;
    char ch;
    for (int i=0;i<strlen(infix);i++){
        ch=infix[i];
        if (isalnum(ch)) postfix[p++]=ch;
        else if (ch=='(') push(ch);
        else if (ch==')'){
            while(peek()!='('){
                postfix[p++]=pop();
            }
            pop();
        }
        else{
            while(top!=-1 && ((precedence(peek())> precedence(ch))|| (precedence(peek())==precedence(ch) && associativity(ch)==0))){
                postfix[p++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1){
        postfix[p++]=pop();
    }
    postfix[p]='\0';
}

int main(){
    char infix[MAX],postfix[MAX];
    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("The postfix expression is: %s\n",postfix);
    return 0;
}
