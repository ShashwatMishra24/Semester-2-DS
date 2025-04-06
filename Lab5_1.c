#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void splitList(struct Node* head, struct Node** front, struct Node** back) {
    struct Node* mid = head;
    struct Node* start = head->next;
    while (start != NULL) {
        start = start->next;
        if (start != NULL) {
            mid = mid->next;
            start = start->next;
        }
    }
    *front = head;
    *back = mid->next;
    mid->next = NULL; 
}
struct Node* merge(struct Node* a, struct Node* b) {
    struct Node* result = NULL;
    if (a == NULL) return b;
    if (b == NULL) return a;
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}
void mergeSort(struct Node** ptr) {
    struct Node* temp = *ptr;
    struct Node* a;
    struct Node* b;
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    splitList(temp, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *ptr = merge(a, b);
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    int i=1,n;
    printf("no of nodes");
    scanf("%d",&n);
    struct Node *head ,*nnode,*temp;
    head=NULL;
    while(i<=n)
    {
        nnode=(struct Node*)malloc(sizeof(struct Node));
        if(head==NULL)
        {
            head=nnode;
            temp=nnode;
            printf("enter data");
            scanf("%d",&nnode->data);
        }
        else{
           
            temp->next=nnode;
            temp=nnode;
            scanf("%d",&nnode->data);
        }
        i++;
    }
    temp->next=NULL;
    mergeSort(&head);
    printList(head);
    return 0;
}
