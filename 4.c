#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][50];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(char doc[]) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1)
        front = 0;
    strcpy(queue[++rear], doc);
    printf("Document added: %s\n", doc);
}

void dequeue() {
    if (isEmpty()) {
        printf("No documents to print\n");
        return;
    }
    printf("Printing: %s\n", queue[front]);
    front++;
}

void display() {
    int i;
    if (isEmpty()) {
        printf("No pending documents\n");
        return;
    }
    printf("Pending documents:\n");
    for (i = front; i <= rear; i++) {
        printf("%s\n", queue[i]);
    }
}

int main() {
    int choice;
    char doc[50];

    do {
        printf("\n1. Add Document\n2. Print Document\n3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter document name: ");
                scanf("%s", doc);
                enqueue(doc);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}