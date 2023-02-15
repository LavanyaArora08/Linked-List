//creating a linked list using union
#include<stdio.h>
#include<stdlib.h>
union Node
{
	int data;
	union Node *next;
};
void printlist(union Node* n)
{
	while(n!=NULL)
    {
		printf(" %d ", n->data);
	    n = n->next;
    }
} 
int main()
{
	union Node *head = NULL;
	union Node *second = NULL;
	union Node *third = NULL;
	head = (union Node*)malloc(sizeof(union Node)); 
	second = (union Node*)malloc(sizeof(union Node));
	third = (union Node*)malloc(sizeof(union Node));
	head -> data = 1;
	head -> next = second;
	second -> data = 2;
	second -> next = third;
	third -> data = 3; 
	third -> next = NULL;
	printlist(head);
    return(0);
}