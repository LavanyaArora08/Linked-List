#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL, *tail=NULL;
void create(int n);
void display();
void delete_beg();
void delete_end();
void delete_mid(int position);
int main()
{
    int n, position, choice=1;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("Data in the list: ");
    display();
    while(choice!=0)
    {
        printf("\nEnter 1 to delete at beginning of the list");
        printf("\nEnter 2 to delete at end of the list");
        printf("\nEnter 3 to delete at middle of the list");
        printf("\nEnter 4 to print updated List");
        printf("\nEnter 0 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                delete_beg();
                break;
            case 2:
                delete_end();
                break;
            case 3:
                printf("\nEnter the position to delete node: " );
                scanf("%d", &position);
                delete_mid(position);
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
void create(int n)
{
    int i,data;
    struct node *newNode;
    if(n>=1)
    {
        head= (struct node*)malloc(sizeof(struct node));
        if(head!=NULL)
        {
            printf("Enter data");
            scanf("%d", &data);
            head->data=data;
            head->prev=NULL;
            head->next=NULL;
            tail=head;
            for(i=1;i<=n;i++)
            {
                newNode=(struct node*)malloc(sizeof(struct node));
                if(newNode!=NULL)
                {
                    scanf("%d", &data);
                    newNode->data=data;
                    newNode->prev=tail;
                    newNode->next=NULL;
                    tail->next=newNode;
                    tail=newNode;
                }
                else
                {
                    printf("Unable to allocate memory");
                    break;
                }
            }
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
}
void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=head;
    while(temp->next != NULL)
    {
        printf("%d, ", temp->data);
        temp=temp->next;
    }
}
void del_beg()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}
void del_end()
{
    struct node *temp;
    if(tail==NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
    }
}
void del_mid(int position)
{
    int i;
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        temp=head;
        for(i=1;i<position;i++)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("Position not found");
                return;
            }
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
