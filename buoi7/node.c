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
    int len, n;
    printf("Enter the length of list: ");
    scanf("%d%*c", &len);
    for (int i=0; i<len; i++){
        printf("Enter the int: ");
        scanf("%d%*c", &n);
        head = insertHead(head, n);
    }
    printList(head);
    insertBefore(&head, head, 6);
    printList(head);
}

