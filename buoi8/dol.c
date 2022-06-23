#include <stdio.h>
#include <stdlib.h>

typedef struct dllist
{
    int data;
    struct dllist *next;
    struct dllist *prev;
}duo_list;

duo_list *head, *tail;

void deleteNode(duo_list *delete, duo_list **head, duo_list **tail){
    if (delete == *head){
        delete->next->prev = NULL;
        *head = delete->next;
    }
    else if (delete == *tail){
        delete->prev->next = NULL;
        *tail = delete->prev;
    }
    else{
        delete->prev->next = delete->next;
        delete->next->prev = delete->prev;
    }
    free(delete);
}

/*lollol */

void printList(duo_list *head){
    duo_list *cur;
    printf("The linked-list: ");
    for (cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->data);
    printf("\n");
}

int main(){
    duo_list *node1 = (duo_list*)malloc(sizeof(duo_list));
    duo_list *node2 = (duo_list*)malloc(sizeof(duo_list));
    duo_list *node3 = (duo_list*)malloc(sizeof(duo_list));

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;

    node1->prev = NULL;
    node2->prev = node1;
    node3->prev = node2;

    node1->next = node2; 
    node2->next = node3;
    node3->next = NULL;

    deleteNode(node1, &node1, &node3);

    printList(node1);
}
