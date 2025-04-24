#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void reverse(struct node **head_ref, int k) {
    if (*head_ref == NULL || k == 1) return;

    struct node *current = *head_ref;
    struct node *prev = NULL, *next = NULL;
    struct node *tail = NULL;
    int count = 0;

    // Reverse the first k nodes of the linked list
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Connect the k-th to next node
    if (tail != NULL) {
        tail->next = current;
    }

    // Fix the head pointer
    *head_ref = prev;
    
    if (*head_ref != NULL) {
        tail = *head_ref;
        while (tail->next != NULL) {
            tail = tail->next;
        }
    }
}

void print(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int main() {
    int n, k, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Enter the data for the nodes:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &data);
        insert(data);
    }

    reverse(&head, k);

    print(head);

    return 0;
}
