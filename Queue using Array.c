//9.  Perform queue operations using array.

#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, n, i;

int isEmpty() {
    return (front == -1 && rear == -1);
}

void printQueue(int queue[]) {
	if (isEmpty()) {
		printf("Queue is empty.");
		return;
	}
	printf("Queue: ");
	for (i = front; i < rear + 1; i++)
		printf("%d ", queue[i]);
}

int main() {
	printf("Enter size of the queue: ");
	scanf("%d", &n);
	int queue[n], choice, value;
	printf("\nQueue created.");

	while (1) {
		printf("\n\nOperations Menu:\n");
		printf("1. Enqueue\n2. Dequeue\n");
		printf("3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if (rear == n - 1) {
				printf("Queue is full. Cannot enqueue");
				break;
			}
			if (isEmpty()) front = 0;
			printf("Enter item to push: ");
			scanf("%d", &value);
			queue[++rear] = value;
			printf("%d enqueued.", value);
			break;
		case 2:
			if (isEmpty()) {
				printf("Queue is empty. Cannot dequeue");
				break;
			}
			printf("%d dequeued from the queue", queue[front]);
			if (front == rear) front = rear = -1;
			else front++;
			break;
		case 3:
			printQueue(queue);
			break;
		case 4:
			printf("Program exited!\n");
			exit(0);
		default:
			printf("Invalid choice!");
		}
	}

	return 0;
}


