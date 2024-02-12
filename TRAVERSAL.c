#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void inorderTraversal(Node *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

Node *createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
	    exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    int data;
    printf("Enter the data of root node: ");
    scanf("%d", &data);
    Node *root = createNode(data);
    printf("Enter the data of left node: ");
    scanf("%d", &data);
    root->left = createNode(data);
    printf("Enter the data of right node: ");
    scanf("%d", &data);
    root->right = createNode(data);

    printf("Enter the data for left child of left node: ");
    scanf("%d", &data);
    root->left->left = createNode(data);
    printf("Enter the data for right child of left node: ");
    scanf("%d", &data);
    root->left->right = createNode(data);

    printf("\nInorder traversal: ");
    inorderTraversal(root);

    printf("\nPreorder traversal: ");
    preorderTraversal(root);

    printf("\nPostorder traversal: ");
    postorderTraversal(root);
    return 0;
}
