void deleteValue(int n)
{
    struct Node *temp, *prev;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    while(temp -> data != n)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = temp -> next;
    temp -> next = NULL;
    free(temp);
}