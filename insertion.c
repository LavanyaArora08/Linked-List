//insertion in a linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head;
void createList(int n);
void traverseList();
void insertNodeAtBeginning(int data);
void insertNodeAtEnd(int data);
void insertNodeAtMiddle(int data, int position);
int main()
{
    int position, n, data, choice=1;
    head = NULL;
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);
    createList(n);
    printf("Data in the list \n");
    traverseList();
    while(choice != 0)
    {
        printf("\nEnter 1 to insert at beginning of the list");
        printf("\nEnter 2 to insert at end of the list");
        printf("\nEnter 3 to insert at middle of the list");
        printf("\nEnter 4 to print updated List");
        printf("\nEnter 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter data to insert at beginning of the list: ");
                scanf("%d", &data);
                insertNodeAtBeginning(data);
                break;
            case 2:
                printf("\nEnter data to insert at end of the list: ");
                scanf("%d", &data);
                insertNodeAtEnd(data);
                break;
            case 3:
                printf("\nEnter data to insert at middle of the list: ");
                scanf("%d", &data);
                printf("\nEnter the position to insert new node: " );
                scanf("%d", &position);
                insertNodeAtMiddle(data, position);
                break;
            case 4:
                printf("\nUpdated List: ");
                traverseList();
                printf("\n");
                break;
            case 0:
                break;
            default:
                printf("\nError! Invalid choice.");
        }
    }
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
void insertNodeAtBeginning(int data)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    newNode -> data = data;
    newNode -> next = head;
    head = newNode;
}
void insertNodeAtEnd(int data)
{
    struct Node *newNode, *temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    temp = head;
    while(temp -> next != NULL)
        temp = temp -> next;
    temp -> next = newNode;
}
void insertNodeAtMiddle(int data, int position)
{
    struct Node *newNode, *temp;
    int i;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    temp = head;
    for(i=2; i<=position-1; i++)
    {
        temp = temp -> next;
        if(temp == NULL)
            break;
    }
    if(temp != NULL)
    {
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    else
    {
        printf("Unable to insert data at the given position");
    }
}