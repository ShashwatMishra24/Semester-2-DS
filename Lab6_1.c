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

void dupli() {
    struct node* curr = head;

    
    while (curr != NULL && curr->next != NULL) {
        struct node* prev = curr;
        struct node* ptr = curr->next;

       
        while (ptr != NULL) {
            if (curr->data == ptr->data) {
                
                prev->next = ptr->next;
                free(ptr); 
                ptr = prev->next; 
            } else {
               
                prev = ptr;
                ptr = ptr->next;
            }
        }
        curr = curr->next; 
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
    dupli();
    traverse(); 
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
