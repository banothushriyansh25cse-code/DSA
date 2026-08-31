#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Insert an element
void insert(int value) {
    // Queue is full
    if ((rear + 1) % MAX == front) {
        printf("Overflow\n");
        return;
    }

    // First element
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d inserted\n", value);
}

// Delete an element
void delete() {
    int value;

    // Queue is empty
    if (front == -1) {
        printf("Underflow\n");
        return;
    }

    value = queue[front];
    printf("%d deleted\n", value);

    // Queue becomes empty
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}

// Display queue
void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    // Delete two elements
    delete();
    delete();

    display();

    // Reuse the positions freed by deletion
    insert(60);
    insert(70);

    display();

    // Try inserting when queue is full
    insert(80);

    return 0;
}