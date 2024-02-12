#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int a[], int n);
void selection_sort(int a[], int n);
void insertion_sort(int a[], int n);

int main() {
    int n, choice;
    int a[10], b[10], c[10];

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("Enter the elements to be sorted:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        c[i] = a[i];
    }

    printf("Choose an option below:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubble_sort(a, n);
            printf("Sorted using Bubble Sort:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            break;

        case 2:
            selection_sort(b, n);
            printf("Sorted using Selection Sort:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", b[i]);
            }
            break;

        case 3:
            insertion_sort(c, n);
            printf("Sorted using Insertion Sort:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", c[i]);
            }
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Exiting program.\n");
    }

    return 0;
}

void bubble_sort(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int a[], int n) {
    int small_index, temp;
    for (int i = 0; i < n - 1; i++) {
        small_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[small_index]) {
                small_index = j;
            }
        }
        temp = a[i];
        a[i] = a[small_index];
        a[small_index] = temp;
    }
}

void insertion_sort(int a[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
