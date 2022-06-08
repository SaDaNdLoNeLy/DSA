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

void insertHead(node *head, int value){
    node *new_node = allocateData(value);
    if (head == NULL){
        head = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
    }
}


void printList(node *head){
    node *cur;
    printf("The linked-list: ");
    for (cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->data);
}

int main(){
    insertHead(head, 5);
    insertHead(head, 6);
    insertHead(head, 7);
    printList(head);
}

