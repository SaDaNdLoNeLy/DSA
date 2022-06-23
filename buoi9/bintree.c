#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left_child;
    struct node *right_child;
}node;

node *makeNode(int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

node *find(node *root, int data){
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;
    node *sub_r = find(root->left_child, data);
    if (sub_r != NULL)
        return sub_r;
    return find(root->right_child, data); 
}

void addLeft(int p, int c, node *root){
    node* parent = find(root, p);
    if (parent == NULL)
        printf("Not found %d\n", p);
    if (parent->left_child != NULL)
        printf("Node already has left child\n");
    parent->left_child = makeNode(c);
}

void addRight(int p, int c, node *root){
    node* parent = find(root, p);
    if (parent == NULL)
        printf("Not found %d\n", p);
    if (parent->right_child != NULL)
        printf("Node already has left child\n");
    parent->right_child = makeNode(c);
}

void printTree(node *root){
    if (root == NULL)
        return;
    printf("Node: %d ", root->data);
    if (root->left_child == NULL)
        printf("Left child = NULL ");
    else
        printf("Left child = %d ", root->left_child->data);

    if (root->right_child == NULL)
        printf("Right child = NULL ");
    else
        printf("Right child = %d ", root->left_child->data);
    printf("\n");

    printTree(root->left_child);
    printTree(root->right_child);
}