#include <stdio.h> 
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right; 
};

struct node *create_node(int key){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root , int key){
    if(root == NULL){
        return create_node(key);
    }

    if(key < root->data){
        root->left = insert(root->left , key);
    }else if(key > root->data){
        root->right = insert(root->right , key);
    }

    return root;
}

struct node *findMin(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct node *delete(struct node *root , int key){
    if(root == NULL){
        return root;
    }
    if(key < root->data){
        root->left = delete(root->left , key);
    }else if(key > root->data){
        root->right = delete(root->right , key);
    }else{
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right , temp->data);
    }

    return root;
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void main(){
    struct node * root = NULL;

    root = insert(root , 10);
    root = insert(root , 20);

    root = delete(root , 10);

    inorder(root);
}