#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head, *head2, *head3, *temp2, *temp3;

void even(struct node *u) {
    if (head2 == NULL) {
        head2 = u;
        temp2 = u;
    } else {
        temp2->next = u;
        temp2 = u;
    }
}

void odd(struct node *u) {
    if (head3 == NULL) {
        head3 = u;
        temp3 = u;
    } else {
        temp3->next = u;
        temp3 = u;
    }
}
void traverse() {
    struct node* ptr,*prev;
    head2 = head3 = NULL; 
    temp2 = temp3 = NULL;  

    while (head != NULL) {
        ptr = head;
        head = head->next;  
        ptr->next = NULL;   

        if (ptr->data % 2 == 0) {
            even(ptr);  
        } else {
            odd(ptr);  
        }
        prev=ptr;
        ptr=ptr->next;
        free(ptr);
    }
   
}

void print(struct node *head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int i = 1, n;
    printf(" number of nodes ");
    scanf("%d", &n);
    
    struct node *nnode, *temp;
    head = NULL;
    
    while (i <= n) {
        nnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &nnode->data);

        if (head == NULL) {
            head = nnode;
            temp = nnode;
        } else {
            temp->next = nnode;
            temp = nnode;
        }

        i++;
    }
    
    temp->next = NULL; 

    traverse(); 
    
    printf("Even numbers: ");
    print(head2);
    printf("Odd numbers: ");
    print(head3);
    return 0;
}
