void printList(node *head){
    node *cur;
    printf("The linked-list: ");
    for (cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->data);
}