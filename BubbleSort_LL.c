#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;  
}*head;
void createList(int n);
void traverseList();
void bubbleSort();
int main()
{
    int n;
    printf("enter the number of nodes ");
    scanf("%d",&n);
    createList(n);
    printf("\nData in list:\n");
    traverseList();
    printf("\nSorted Data: \n");
    bubbleSort();
    return 0;
}
void createList(int n)
{
    struct Node *newNode, *temp;
    int data, i;
    head = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL)
    {
        printf("Unable to allocate Memory");
        return;
    }
    printf("\nEnter Data:\n");
    scanf("%d", &data);
    head -> data = data;
    head -> next = NULL;
    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL)
        {
            printf("Unable to allocate memory");
            break;
        }
        scanf("%d", &data);
        newNode -> data = data;
        newNode -> next = NULL;
        temp -> next = newNode;
        temp = temp -> next;
    }
}
void traverseList()
{
    struct Node *temp;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    while( temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp -> next;
    }
}
void bubbleSort()
{
    struct Node *i, *j;
    int temp;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    for(i=head; i->next != NULL; i=i->next)
    {
        for(j= i->next; j!=NULL; j=j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    traverseList();
}