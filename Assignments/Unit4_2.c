#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

struct Node *minValueNode(struct Node *root) {
    struct Node *temp = root;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValueNode(root->right);

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int values[] = {40, 20, 60, 10, 30, 50, 70};
    int n = 7;

    struct Node *root = NULL;

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Original BST: ");
    inorder(root);

    root = deleteNode(root, 10);
    printf("\nAfter deleting 10: ");
    inorder(root);

    root = deleteNode(root, 60);
    printf("\nAfter deleting 60: ");
    inorder(root);

    root = deleteNode(root, 40);
    printf("\nAfter deleting 40: ");
    inorder(root);

    return 0;
}
