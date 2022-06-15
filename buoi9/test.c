#include <stdio.h>
#include <string.h>

typedef struct node{
    char name[256];
    struct node *left_most_child;
    struct node *right_sibling;
}node;

node *makeNode(char *name){
    node *new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->left_most_child = NULL;
    new_node->right_sibling = NULL;
    return new_node;
}

node *test(){
    node *root = NULL;
    return root;
}

int main(){
    node *root=test(), *tmp;
    tmp = root;
    printf("%p\n%p", root, tmp);
}