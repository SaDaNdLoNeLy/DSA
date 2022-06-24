#include <stdio.h>
#include <string.h>

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

int main(){
    node *root = makeNode(5);
    node *r = root;
    printf("%d %d", root->data, r->data);
}