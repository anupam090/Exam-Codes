#include <stdio.h>
#include <stdlib.h>

int insertionbeg(int);
int insertionend(int);
int insertionanypos(int, int);
int deletionbeg();
int deletionend();
int deletionanypos(int);
int printlinkedlist();


struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

int insertionbeg(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    temp->data = item;
    temp->next = head;
    head = temp;

    printf("Node inserted at the beginning successfully.\n");
    return 1;
}

int insertionend(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    temp->data = item;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    printf("Node inserted at the end successfully.\n");
    return 1;
}

int insertionanypos(int item, int position) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    temp->data = item;

    if (position == 1) {
        temp->next = head;
        head = temp;
    } else {
        struct node* ptr = head;
        for (int i = 1; i < position - 1 && ptr != NULL; i++) {
            ptr = ptr->next;
        }

        if (ptr == NULL) {
            printf("Invalid position.\n");
            free(temp);
            return 0;
        }

        temp->next = ptr->next;
        ptr->next = temp;
    }

    printf("Node inserted at position %d successfully.\n", position);
    return 1;
}

int deletionbeg() {
    if (head == NULL) {
        printf("Linked list is empty. Deletion failed.\n");
        return 0;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from the beginning successfully.\n");
    return 1;
}

int deletionend() {
    if (head == NULL) {
        printf("Linked list is empty. Deletion failed.\n");
        return 0;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node* ptr = head;
        struct node* prev = NULL;
        while (ptr->next != NULL) {
            prev = ptr;
            ptr = ptr->next;
        }
        free(ptr);
        prev->next = NULL;
    }

    printf("Node deleted from the end successfully.\n");
    return 1;
}

int deletionanypos(int position) {
    if (head == NULL) {
        printf("Linked list is empty. Deletion failed.\n");
        return 0;
    }

    if (position == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    } else {
        struct node* ptr = head;
        struct node* prev = NULL;

        for (int i = 1; i < position && ptr != NULL; i++) {
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr == NULL) {
            printf("Invalid position.\n");
            return 0;
        }

        prev->next = ptr->next;
        free(ptr);
    }

    printf("Node deleted from position %d successfully.\n", position);
    return 1;
}

int printlinkedlist() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return 0;
    }

    struct node* ptr = head;
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return 1;
}

int main() {
    int choice, item, position;

    do {
        printf("\n*** Linked List Operations ***\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from any position\n");
        printf("7. Print the linked list\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &item);
                insertionbeg(item);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &item);
                insertionend(item);
                break;
            case 3:
                printf("Enter the value to be inserted: ");
                scanf("%d", &item);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertionanypos(item, position);
                break;
            case 4:
                deletionbeg();
                break;
            case 5:
                deletionend();
                break;
            case 6:
                printf("Enter the position to be deleted: ");
                scanf("%d", &position);
                deletionanypos(position);
                break;
            case 7:
                printlinkedlist();
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);


    return 0;
}
