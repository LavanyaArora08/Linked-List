//insert elements from beginning, middle and end of the list. use switch case to select the position of insertion
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
void create(int n);
void display();
void insert_beg(int data);
void insert_mid(int data, int position);
void insert_end(int data);
int main()
{
    int n, data, position, choice=1;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("Data in the list: ");
    display();
    while(choice!=0)
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
                insert_beg(data);
                break;
            case 2:
                printf("\nEnter data to insert at end of the list: ");
                scanf("%d", &data);
                insert_end(data);
                break;
            case 3:
                printf("\nEnter data to insert at middle of the list: ");
                scanf("%d", &data);
                printf("\nEnter the position to insert new node: " );
                scanf("%d", &position);
                insert_mid(data, position);
                break;
            case 4:
                printf("\nUpdated List: ");
                display();
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
void create(n)
{
    int i, data;
    struct node *newnode;
    if(n>=1)
    {
        head=(struct node*)malloc(sizeof(struct node));
        if(head!=NULL)
        {
            printf("Enter the data of node 1: ");
            scanf("%d", &data);
            head->data=data;
            head->next=NULL;
            head->prev=NULL;
            tail=head;
            for(i=2; i<=n; i++)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                if(newnode!=NULL)
                {
                    printf("Enter the data of node %d: ", i);
                    scanf("%d", &data);
                    newnode->data=data;
                    newnode->next=NULL;
                    newnode->prev=tail;
                    tail->next=newnode;
                    tail=newnode;
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
}
void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
}
void insert_beg(int data)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode!=NULL)
    {
        newnode->data=data;
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
        printf("Data inserted successfully.");
    }
    else
    {
        printf("Unable to allocate memory.");
    }
}
void insert_end(int data)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode!=NULL)
    {
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
        printf("Data inserted successfully.");
    }
    else
    {
        printf("Unable to allocate memory.");
    }
}
void insert_mid(int data, int position)
{
    int i;
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode!=NULL)
    {
        newnode->data=data;
        temp=head;
        for(i=2; i<=position-1; i++)
        {
            temp=temp->next;
            if(temp==NULL)
                break;
        }
        if(temp!=NULL)
        {
            newnode->next=temp->next;
            newnode->prev=temp;
            if(temp->next!=NULL)
                temp->next->prev=newnode;
            temp->next=newnode;
            printf("Data inserted successfully.");
        }
        else
        {
            printf("Invalid position unable to insert.");
        }
    }
    else
    {
        printf("Unable to allocate memory.");
    }
}

