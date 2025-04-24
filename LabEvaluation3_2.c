#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define RANGE 256  // Range of possible values (can adjust as needed)

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int val) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = val;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int val = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}
int peek(Queue* q) {
    if (isEmpty(q)) return -1;
    return q->data[q->front];
}

int smallestNonRepeating(int arr[], int n) {
    int freq[RANGE] = {0};  
    Queue q;
    initQueue(&q);

    for (int i = 0; i < n; i++) {
        int val = arr[i];
        freq[val]++;
        enqueue(&q, val);
        while (!isEmpty(&q) && freq[peek(&q)] > 1) {
            dequeue(&q);
        }
    }

    return isEmpty(&q) ? -1 : peek(&q); 
}
int main() {
    int arr[] = {2, 3, 4, 2, 3, 5, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = smallestNonRepeating(arr, n);

    if (result == -1)
        printf("No non-repeating element found.\n");
    else
        printf("Smallest non-repeating element: %d\n", result);

    return 0;
}
