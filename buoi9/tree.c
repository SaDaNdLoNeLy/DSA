#include <stdio.h>
<<<<<<< HEAD
=======
#include <stdlib.h>
>>>>>>> 46e24a93a12cc65b12bb418e2c871964dd891c0f
#include <string.h>

typedef struct node{
    char name[256];
    struct node *left_most_child;
    struct node *right_sibling;
}node;

node *root;

node *makeNode(char *name){
    node *new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->left_most_child = NULL;
    new_node->right_sibling = NULL;
    return new_node;
}

<<<<<<< HEAD
void readFile(FILE *f, node *r){
    char p_name[256], c_name[256];
    int count=0;
    do{
        fscanf(f, "%s", p_name);
        node *r = makeNode(p_name);
        do{
            count = 1;
            fscanf(f, "%s", c_name);
            node *c;
            if (c_name=="$")
                break;
            if (count == 1){
                c = makeNode(c_name);
                r->left_most_child = c;
                count++;
            }
            else{
                c->right_sibling = makeNode(c_name);
                count++;
            }
        } while (1);
        if (c_name=="$")
            continue;
        if (p_name=="$$")
            break;
    } while(1); 
}
=======

>>>>>>> 46e24a93a12cc65b12bb418e2c871964dd891c0f

node *find(node *root, char *name){
    if (root == NULL)
        return NULL;
    if (strcmp(root->name, name) == 0)
        return root;
    node *p = root->left_most_child;
    while (p != NULL){
        node *sub_p = find(p, name);
        if (sub_p != NULL)
            return sub_p;
        p = p->right_sibling;
    }
}

void findNameProcess(){
    char name[256];
    printf("Enter the name to find: ");
    scanf("%[^\n]%*c", name);
    node *found = find(root, name);
    if (found == NULL)
        printf("Name not found\n");
    else    
        printf("Found %s\n", name);
}

void findChildrenProcess(){
    char name[256];
    printf("Enter parent node: ");
    scanf("%[^\n]%*c", name);
    node *found = find(root, name);
    if (found == NULL)
        printf("Not found %s in the tree");
    else{
        printf("List of child nodes: ");
        node *found_child = found->left_most_child;
        while (found_child != NULL){
            printf("%s; ", found_child->name);
            found_child = found_child->right_sibling;
        }
    }
    printf("\n");
}

<<<<<<< HEAD
void addChild(char *p_name, char *c_name){
=======
void addChild(char *p_name, char *c_name, node *root){
>>>>>>> 46e24a93a12cc65b12bb418e2c871964dd891c0f
    node *p = find(root, p_name);
    if (p == NULL)
        printf("Not found %s\n", p_name);
    node *c = p->left_most_child;
<<<<<<< HEAD
    while (c->right_sibling != NULL)
        c = c->right_sibling;
    c->right_sibling = makeNode(c_name);
=======

    if (c==NULL){
        c = makeNode(c_name);
        p->left_most_child = c;
    }
    else{
    while (c->right_sibling != NULL)
        c = c->right_sibling;
    c->right_sibling = makeNode(c_name);
    }
>>>>>>> 46e24a93a12cc65b12bb418e2c871964dd891c0f
}

void addChildProcess(){
    char p_name[256], c_name[256];
    printf("Enter parent node for adding: ");
    scanf("%[^\n]%*c", p_name);
    printf("Enter child node for adding: ");
    scanf("%[^\n]%*c", c_name);
<<<<<<< HEAD
    addChild(p_name, c_name);
=======
    addChild(p_name, c_name, root);
>>>>>>> 46e24a93a12cc65b12bb418e2c871964dd891c0f
}

void printProcess(node *root){
    if (root == NULL)
        printf("No tree is found\n");

    printf("%s: ", root->name);
    node *child = root->left_most_child;
    while (child != NULL){
        printf("%s ", child->name);
        child = child->right_sibling;
    }
    printf("\n");
    child = root->left_most_child;
    while (child != NULL){
        printProcess(child);
        child = child->right_sibling;
    }
}

<<<<<<< HEAD
=======
node *readFile(FILE *f){
    node *root=NULL;
    int count=0;
    char p_name[256], c_name[256];
    do{
        fscanf(f, "%s", p_name);
        if (strcmp(p_name, "$$")==0)
            break;
        node *p = find(root, p_name);
        if (p == NULL){
            p=makeNode(p_name);
            if (count == 0)
                root = p;
        }
        do{
            fscanf(f, "%s", c_name);
            if (strcmp(c_name, "$")==0)
                break;
            addChild(p_name, c_name, root);
        } while(1);
        count++;
    } while(1);
    return root;
}

>>>>>>> 46e24a93a12cc65b12bb418e2c871964dd891c0f
void storeProcess(node *root, FILE *file){
    if (root == NULL)
        return;
    if (root->left_most_child != NULL)
        fprintf(file, "%s ", root->name);
    node *child = root->left_most_child;
    while (child != NULL){
        fprintf(file, "%s ", child->name);
        child = child->right_sibling;
    }
    fprintf(file, " $\n");
    child = root->left_most_child;
    while (child != NULL){
        storeProcess(child, file);
        child = child->right_sibling;
    }
}

int height(node *r){
    int max = 0;
    if (r == NULL)
        return 0;
    node *c = r->left_most_child;
    while (c != NULL){
        int h = height(c);
        max = max < h ? h : max;
        c = c->right_sibling;
    }
    return max+1;
}

void heightProcess(){}

int countNode(node *r){
    if (r == NULL)
        return 0;
    int count = 1;
    node *c = r->left_most_child;
    while (c != NULL){
        count += countNode(c);
        c = c->right_sibling;
    }
    return count;
}

int main(){
<<<<<<< HEAD
    int choice;
    do{
        printf("%-20s", "MENU");
        printf()

    } while()
=======
    FILE *f = fopen("file.txt", "r");
    FILE *store = fopen("store.txt", "w");
    node *root = readFile(f);

    printf("%p", root);
    storeProcess(root, store);
    fclose(f);
    fclose(store);
>>>>>>> 46e24a93a12cc65b12bb418e2c871964dd891c0f
}