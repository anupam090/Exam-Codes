#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* new_node(int data) {
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void print_inorder(struct node* node) {
    if (node == NULL)
        return;
    print_inorder(node->left);
    printf("%d ", node->data);
    print_inorder(node->right);
}

void print_preorder(struct node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    print_preorder(node->left);
    print_preorder(node->right);
}

void print_postorder(struct node* node) {
    if (node == NULL)
        return;
    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int r, r1, n;

    printf("Enter the 1st element: ");
    scanf("%d", &r);
    struct node *root = new_node(r);

    printf("Enter the 2nd element: ");
    scanf("%d", &r1);
    root->left = new_node(r1);

    printf("Enter the 3rd element: ");
    scanf("%d", &n);
    root->right = new_node(n);

    printf("Enter the 4th element: ");
    scanf("%d", &n);
    root->left->left = new_node(n);

    printf("Enter the 5th element: ");
    scanf("%d", &n);
    root->left->right = new_node(n);

    printf("\nPreorder traversal of binary tree is: \n");
    print_preorder(root);

    printf("\nPostorder traversal of binary tree is: \n");
    print_postorder(root);

    printf("\nInorder traversal of binary tree is: \n");
    print_inorder(root);

    return 0;
}
