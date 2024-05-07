#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;
} CircularFifo;

void init(CircularFifo* fifo) {
    fifo->front = 0;
    fifo->rear = -1;
    fifo->count = 0;
}

int isFull(CircularFifo* fifo) {
    return fifo->count == MAX_SIZE;
}

int isEmpty(CircularFifo* fifo) {
    return fifo->count == 0;
}

void enqueue(CircularFifo* fifo, int item) {
    if (isFull(fifo)) {
        fifo->rear = (fifo->rear + 1) % MAX_SIZE;
        fifo->data[fifo->rear] = item;
        fifo->front = (fifo->front + 1) % MAX_SIZE;
    } else {
        fifo->rear = (fifo->rear + 1) % MAX_SIZE;
        fifo->data[fifo->rear] = item;
        fifo->count++;
    }
}

int dequeue(CircularFifo* fifo) {
    if (isEmpty(fifo)) {
        printf("FIFO is empty.\n");
        return -1;
    } else {
        int item = fifo->data[fifo->front];
        fifo->front = (fifo->front + 1) % MAX_SIZE;
        fifo->count--;
        return item;
    }
}

int main() {
    CircularFifo fifo;
    init(&fifo);

    // Enqueue some items
    enqueue(&fifo, 10);
    enqueue(&fifo, 20);
    enqueue(&fifo, 30);

    // Dequeue and print items
    printf("%d\n", dequeue(&fifo));
    printf("%d\n", dequeue(&fifo));
    printf("%d\n", dequeue(&fifo));

    // Enqueue some more items to demonstrate overwrite
    enqueue(&fifo, 40);
    enqueue(&fifo, 50);
    enqueue(&fifo, 60);

    // Dequeue and print items again
    printf("%d\n", dequeue(&fifo));
    printf("%d\n", dequeue(&fifo));
    printf("%d\n", dequeue(&fifo));

    return 0;
}

/*

   █████▒█    ██  ▄████▄   ██ ▄█▀       ██████╗ ██╗   ██╗ ██████╗
 ▓██   ▒ ██  ▓██▒▒██▀ ▀█   ██▄█▒        ██╔══██╗██║   ██║██╔════╝
 ▒████ ░▓██  ▒██░▒▓█    ▄ ▓███▄░        ██████╔╝██║   ██║██║  ███╗
 ░▓█▒  ░▓▓█  ░██░▒▓▓▄ ▄██▒▓██ █▄        ██╔══██╗██║   ██║██║   ██║
 ░▒█░   ▒▒█████▓ ▒ ▓███▀ ░▒██▒ █▄       ██████╔╝╚██████╔╝╚██████╔╝
  ▒ ░   ░▒▓▒ ▒ ▒ ░ ░▒ ▒  ░▒ ▒▒ ▓▒       ╚═════╝  ╚═════╝  ╚═════╝
  ░     ░░▒░ ░ ░   ░  ▒   ░ ░▒ ▒░
  ░ ░    ░░░ ░ ░ ░        ░ ░░ ░
           ░     ░ ░      ░  ░

*/