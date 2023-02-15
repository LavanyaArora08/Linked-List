#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head;
void createList(int n);
void traverseList();
void reverseList();
int main()
{
    int n;
    printf("Enter the number of nodes ");
    scanf("%d",&n);
    createList(n);
    printf("\n Data in list\n");
    traverseList();
    reverseList();
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
        printf("%d, ", temp->data);
        temp = temp -> next;
    }
}
//Condition is head and last node should be changed
void reverseList()
{
    struct Node *prevNode, *curNode;
    if(head == NULL)
    {
        printf("List is empty");
        return;
    }
    prevNode = head;
    curNode = head -> next;
    head = head -> next;
    prevNode -> next = NULL;
    while(head != NULL)
    {
        head = head -> next;
        curNode -> next = prevNode;
        prevNode = curNode;
        curNode = head;
    }
    head = prevNode;
    printf("\n Data in reverse list\n");
    traverseList();
}