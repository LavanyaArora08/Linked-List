#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head;
void createList(int n);
void traverseList();
void deleteFromStart();
void deleteFromEnd();
void deleteValue(int n);
int main()
{
    int n, choice, data;
    head = NULL;
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);
    createList(n);
    printf("Data in the list \n");
    traverseList();
    while(choice != 0)
    {
        printf("\nEnter 1 to delete from beginning of the list");
        printf("\nEnter 2 to delete from end of the list");
        printf("\nEnter 3 to delete a value");
        printf("\nEnter 4 to print updated List");
        printf("\nEnter 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                deleteFromStart();
                break;
            case 2:
                deleteFromEnd();
                break;
            case 3:
                printf("\nEnter the value which you want to delete: ");
                scanf("%d", &data);
                deleteValue(data);
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
    return 0;
}
void createList(int n)
{
    struct Node *newNode, *temp;
    int data, i;
    head = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL)
    {
        printf("Memory not allocated");
        return;
    }
    printf("\nEnter data:\n");
    scanf("%d", &data);
    head -> data = data;
    head -> next = NULL;
    temp = head;
    for(i =2; i<=n;i++)
    {
        newNode= (struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL)
        {
            printf("memory not allocated");
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
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}
void deleteFromStart()
{
    struct Node *temp;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    head = head -> next;
}
void deleteFromEnd()
{
    struct Node *temp, *prev;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    while(temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    free(temp);
}
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