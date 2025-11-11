#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createnode(int key){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int height(struct node *root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int max(int a ,int b){
    return a>b?a:b;
}

int getBalance(struct node *root){
    if(root == NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}

struct node *leftrotate(struct node *x){
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->right) , height(x->left))+1;
    y->height = max(height(y->left) , height(y->right))+1;

    return y;
}

struct node *rightrotate(struct node *y){
    struct node *x  = y->left;
    struct node *T2  = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left) , height(y->right))+1;
    x->height = max(height(x->right) , height(x->left))+1;

    return x;
}

struct node *insert(struct node *root ,int key){
    if(root == NULL){
        return createnode(key);
    }

    if(key > root->key){
        root->right = insert(root->right , key);
    }else if(key < root->key){
        root->left = insert(root->left , key);
    }else {
        return root;
    }

    root->height = max(height(root->right) , height(root->left))+ 1 ;

    int balance = getBalance(root);

    if(balance > 1 && key < root->left->key){
        return rightrotate(root);
    }

    if(balance < -1 && key > root->right->key){
        return leftrotate(root);
    }

    if(balance > 1 && key > root->left->key){
        root->left = leftrotate(root);
        return rightrotate(root);
    }
    if(balance < -1 && key < root->right->key){
        root->right = rightrotate(root);
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

    return 0;
}

