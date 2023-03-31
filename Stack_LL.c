#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display();  
struct node   
{  
int data;  
struct node *next;  
}*ptr,*head;
void push()
{
	int val;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("No node is available");
	}
	else
	{
		scanf("%d", &val);
		if(head==NULL)
		{
			ptr->data = val;
			ptr->next = NULL;
			head = ptr;
		}
		else
		{
			ptr->data= val;
			ptr->next = head;
			head=ptr;
		}
	}
}
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->data;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped");  
          
    }  
}
void display()  
{  
    int i;  
    struct node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->data);  
            ptr = ptr->next;  
        }  
    }  
}
void main ()  
{  
    int choice=0;     
    while(choice != 4)  
    {  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        }
		}
}
	