#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void createList(int n);
void traverseList();
void reverseList();
int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\n The entered list is: ");
    traverseList();
    printf("\nThe reversed List is: ");
    reverseList();
}
void createList(int n)
{
    int i,data;
    struct Node *newNode;
    head=(struct Node*)malloc(sizeof(struct Node));
    if(head != NULL)
    {
        printf("Enter Data: \n");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        head->prev = NULL;
        tail= head;
        for(i=2;i<=n;i++)
        {
            newNode=(struct Node*)malloc(sizeof(struct Node));
            if(newNode!=NULL)
            {
                scanf("%d",&data);
                    newNode->data=data;
                    newNode->next=NULL;
                    newNode->prev=tail;
                    tail->next=newNode;
                    tail=newNode;
            }
            else
            {
                printf("Unable to allocate memory.");
                break;
            }
        }
    }
    else
    {
        printf("Unable to allocate memory.");
    }
}
void traverseList()
{
    struct Node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void reverseList()
{
    struct Node *ptr=tail;
    while(ptr!=NULL)
    {
        printf("%d, ", ptr->data);
        ptr= ptr->prev;
    }
}