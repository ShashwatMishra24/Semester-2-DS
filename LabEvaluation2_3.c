
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top1 = NULL;
struct Node* top2 = NULL;

void push(struct Node** top, int value) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;

    *top = newNode;
}

int pop(struct Node** top) {

    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = temp->next;

    free(temp);

    return popped;
}

void display(struct Node* top, int stackNum) {
    
    printf("Stack %d: ", stackNum);
    
    while (top!=NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    
    printf("\n");
}

void displayCombinedList(struct Node* top1, struct Node* top2) {
    printf("Linked List:\n");

    struct Node* temp = top1;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    temp = top2;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {

    push(&top1, 1);
    push(&top1, 2);
    push(&top1, 3);

    push(&top2, 4);
    push(&top2, 5);
    push(&top2, 6);

    printf("Popped from Stack 1: %d\n", pop(&top1));
    printf("Popped from Stack 2: %d\n", pop(&top2));
    
    printf("\n");
    displayCombinedList(top1,top2);
    return 0;
}
