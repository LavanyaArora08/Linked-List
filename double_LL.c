//write a code to input a double linked list from user and print inputted list
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
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    create(n);
    printf("The list is: ");
    display();
    return 0;
}
void create(int n)
{
    struct node *newnode;
    int data,i;
    if(n>=1)
    {
        head=(struct node*)malloc(sizeof(struct node));
        if(head!=NULL)
        {
            printf("Enter data of node 1: ");
            scanf("%d",&data);
            head->data=data;
            head->next=NULL;
            head->prev=NULL;
            tail=head;
            for(i=2;i<=n;i++)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                if(newnode!=NULL)
                {
                    printf("Enter data of node %d: ",i);
                    scanf("%d",&data);
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
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
