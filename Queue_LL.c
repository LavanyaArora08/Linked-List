//Create Queue using Linked List
#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int info;
    struct Queue *link;
}*front=NULL,*rear=NULL;
void insert(int item);
int del();
void display();
int main()
{
    int choice,item;
    while(1)
    {
        printf("1.Insert element to queue\n");
        printf("2.Delete element from queue\n");
        printf("3.Display all elements of queue\n");
        printf("4.Quit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                item=del();
                printf("Deleted element is %d",item);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice");
        }
    }
}
void insert(int item)
{
    struct Queue *tmp;
    tmp=(struct Queue*)malloc(sizeof(struct Queue));
    if(tmp==NULL)
    {
        printf("Queue is full");  
        return;
    }
    tmp->info=item;
    tmp->link=NULL;
    if(front==NULL)
        front=tmp;
    else
        rear->link=tmp;
    rear=tmp;
}
int del()
{
    struct Queue *tmp;
    int item;
    if(front==NULL)
    {
        printf("Queue is empty");
        exit(1);
    }
    tmp=front;
    item=tmp->info;
    front=front->link;
    free(tmp);
    return item;
}
void display()
{
    struct Queue *ptr;
    ptr=front;
    if(front==NULL)
        printf("Queue is empty");
    else
    {
        printf("Queue is\n");
        printf("Front->");
        while(ptr!=rear)
        {
            printf("%d->",ptr->info);
            ptr=ptr->link;
        }
        printf("%d->",ptr->info);
        printf("Rear");
    }
}
