#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
}*head;
void createList(int n);  //creation of linked list
void traverseList();     //printing the element of linked list
int main()
{
	int n;
	printf("Enter the number of nodes ");
	scanf("%d", &n);
	createList(n);
	printf("\n Data in the list\n");
	traverseList();
    return 0;
}
void createList(int n)
{
	struct Node *newNode,*temp;
	int data, i;
    head = (struct Node*)malloc(sizeof(struct Node));
	if(head==NULL)
	{
		printf("Unable to allocate memory");
		return;
	}
	printf("Enter the data of node 1: ");
	scanf("%d", &data);
	head -> data = data;
	head -> next = NULL;
	temp=head;
	for(i=2; i<=n; i++)
	{
		newNode = (struct Node*)malloc(sizeof(struct Node));
		if(newNode == NULL)
		{
			printf("Unbale to allocate mamory");
			break;
		}
		printf("Enter the data of node %d:  ", i);
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
		printf("list is empty");
		return;
	}
	temp = head;
	while(temp!=NULL)
	{
		printf("Data= %d\n", temp -> data);
		temp = temp -> next;
    }
}