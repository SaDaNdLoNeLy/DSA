#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left_child;
    struct node *right_child;
}node;

node *makeNode(int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
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
        printf("1 Not found %d\n", p);
    if (parent->left_child != NULL)
        printf("Node already has left child\n");
    parent->left_child = makeNode(c);
}

void addRight(int p, int c, node *root){
    node* parent = find(root, p);
    if (parent == NULL)
        printf("2 Not found %d\n", p);
    if (parent->right_child != NULL)
        printf("Node already has right child\n");
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

void store(node *root, FILE *f){
    if (root == NULL)
        return;
    fprintf(f, "%d ", root->data);
    if (root->left_child == NULL)
        fprintf(f, "%d ", -1);
    else
        fprintf(f, "%d ", root->left_child->data);
    if (root->right_child == NULL)
        fprintf(f, "%d ", -1);
    else
        fprintf(f, "%d ", root->right_child->data);
    fprintf(f, "\n");

    store(root->left_child, f);
    store(root->right_child, f);
}

void storeProcess(node *root){
    char fname[50];

    printf("%s\n","Enter name of file: ");
    scanf("%s", fname);

    FILE *f = fopen(fname, "w");
    store(root, f);

    fprintf(f, "%d ", -2);
    fclose(f);
}

node *read(FILE *f){
    int p_data, left_data, right_data;
    int count=0;
    node *root, *return_root;
    do{
        fscanf(f, "%d %d %d", &p_data, &left_data, &right_data);
        if (p_data == -2)
            break;
        
        if (count == 0){
            root = makeNode(p_data);
            return_root = root;
        }
        else 
            root = find(return_root, p_data);

        if (left_data != -1)
            addLeft(p_data, left_data, root);
        if (right_data != -1)
            addRight(p_data, right_data, root);
        count++;
    } while (1);
    return return_root;
}

int count(node *root){
    if (root == NULL)
        return 0;
    else
        return 1 + count(root->left_child) + count(root->right_child);
}

void printLeave(node *root){
    if (root == NULL)
        return;
    if (root->left_child == NULL && root->right_child == NULL)
        printf("%d ");
    printLeave(root->left_child);
    printLeave(root->right_child);
}

int main(){
    FILE *f = fopen("bintree.txt", "r");
    FILE *fstore = fopen("storebintree.txt", "w");
    node *root = read(f);

    printf("%p", root);
    store(root, fstore);

    fclose(fstore);
    fclose(f);

}