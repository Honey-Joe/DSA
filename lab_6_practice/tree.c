#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int value){
    if(root == NULL){
        return create_node(value);
    }else if(value < root->data){
        root->left = insert(root->left , value);
    }else{
        root->right = insert(root->right , value);
    }

    return root;
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node*root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}



int main(){
    struct node* root= NULL;
    root = insert(root , 10);
    root = insert(root , 20);
    inorder(root);
    preorder(root);
    

}
