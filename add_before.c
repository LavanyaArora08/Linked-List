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
void insert();
int main()
{
    int n;
    printf("ENter th enumber of node ");
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
void insert()
{
    struct Node *temp,*newnode,*prev;
    int a,b;
    temp=head;
    printf("Enter the value before which you want to insert data");
    scanf("%d",&a);
    while(temp->data!=a)
    {
        prev=temp;
        temp=temp->next;
    }
    newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("no memory is alocated");
    }
    printf("Enter data you want to insert");
    scanf("%d",&b);
    newnode->data=b;
    newnode->next=prev->next;
    prev->next=newnode;
}