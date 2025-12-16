#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node *root) {
    return (root == NULL) ? 0 : root->height;
}

struct node *createnode(int key) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct node *rightrotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node *leftrotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct node *root) {
    return (root == NULL) ? 0 : height(root->left) - height(root->right);
}

struct node *insert(struct node *root, int key) {
    if (root == NULL)
        return createnode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightrotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftrotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftrotate(root->left);
        return   rightrotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void printTreeFancy(struct node *root, char *prefix, int isLeft) {
    if (root == NULL) return;

    printf("%s", prefix);
    printf(isLeft ? "├──" : "└──");
    printf("%d\n", root->key);

    char newPrefix[1000];
    strcpy(newPrefix, prefix);
    strcat(newPrefix, isLeft ? "│   " : "    ");

    if (root->right)
        printTreeFancy(root->right, newPrefix, 1);
    if (root->left)
        printTreeFancy(root->left, newPrefix, 0);
}

int main() {
    struct node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of the AVL tree is:\n");
    inorder(root);
    printf("\n");

    printf("\nAVL Tree structure:\n");
    printTreeFancy(root, "", 0);

    return 0;
}
