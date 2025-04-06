#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
void traverse() {
    struct node* u = head;
    while (u != NULL) {
        printf("%d ", u->data);
        u = u->next;
    }
    printf("\n");
}

void freq() {
    struct node* curr = head;

    
    while (curr != NULL && curr->next != NULL) {
        struct node* prev = curr;
        struct node* ptr = curr->next;
        int count = 1;  
        while (ptr != NULL) {
            if (curr->data == ptr->data) {
                prev->next = ptr->next;
                free(ptr);  
                ptr = prev->next; 
                count++;  
            } else {
                
                prev = ptr;
                ptr = ptr->next;
            }
        }

        printf("Freq %d: %d\n", curr->data, count);
        curr = curr->next;
    }
    if (curr != NULL) {
        printf("Freq %d: 1\n", curr->data);
    }
}

int main() {
    int i = 1, n;
    printf(" number of nodes ");
    scanf("%d", &n);
    struct node* nnode, * temp;
    head = NULL;
    while (i <= n) {
        nnode = (struct node*)malloc(sizeof(struct node));
        if (head == NULL) {
            head = nnode;
            temp = nnode;
        } else {
            temp->next = nnode;
            temp = nnode;
        }
        scanf("%d", &nnode->data);
        i++;
    }
    temp->next = NULL; 
    freq();
    return 0;
}
