#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *head;

node *allocateData(int value){
    node *p = (node*)malloc(sizeof(node));
    p->data = value;
    p->next = NULL;
    return p;
}

node *insertHead(node *head, int value){
    node *new_node = allocateData(value);
    if (head == NULL){
        head = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
    }
    return head;
}

node *insertAfter(node *cur, int value){
    node *new_node = allocateData(value);
    new_node->next = cur->next;
    cur->next = new_node;
    return new_node;
}

void insertBefore(node **head, node *cur, int value){
    node *new_node = allocateData(value);
    if (cur == *head){
        new_node->next = cur;
        *head = new_node;
    }
    else{
        node *prev = *head;
        while (prev->next != cur)
            prev = prev->next;
        prev->next = new_node;
        new_node->next = cur;
    }
}

node *deleteNode(node *head, node *del){
    if (head == del){
        head = del->next;
        free(del);
    }
    else{
        node *prev = head;
        while (prev->next != del)
            prev = prev->next;
        prev->next = del->next;
        free(del);
    }
    return head;
}

node *deleteList(node *head){
    node *del = head;
    while (del != NULL){
        head = head->next;
        free(del);
        del = head;
    }
    return head;
}

void printList(node *head){
    node *cur;
    printf("The linked-list: ");
    for (cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->data);
}

node *searchData(node *head, int value){
    node *cur = head;
    while (cur->data != value){
        if (cur->next == NULL)
            
        cur = cur->next;
        
    }
    return cur;
}

int main(){
    node *node1 = allocateData(1);
    node *node2 = allocateData(2);
    node *node3 = allocateData(3);
    node *node4 = allocateData(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node1 = deleteList(node1);

    printList(node1);

    
}

