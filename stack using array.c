#include <stdio.h>
#include <stdlib.h>

int push(int[], int, int);
int pop(int[], int);
int display(int[], int);

int push(int a[], int top, int n) {
    if (top > n - 1) {
        printf("Stack Full\n");
    } else {
        printf("Enter item to be pushed: ");
        top = top + 1;
        scanf("%d", &a[top]);
        printf("Stack is:\n");
        display(a, top);
    }
    return top;
}

int pop(int a[], int top) {
    if (top < 0) {
        printf("Empty Stack\n");
    } else {
        printf("Popped element is: %d\n", a[top]);
        top = top - 1;
        printf("New Stack is:\n");
        display(a, top);
    }
    return top;
}

int display(int a[], int top) {
    int i;
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("\t%d", a[i]);
        }
        printf("\n");
    }
    return top;
}

int main() {
    int n, a[10], top = -1, choice;
    printf("Enter size of stack: ");
    scanf("%d", &n);
    do {
        printf("\nEnter Choice:\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Display\n");
        printf("4) Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                top = push(a, top, n);
                break;
            case 2:
                top = pop(a, top);
                break;
            case 3:
                display(a, top);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
