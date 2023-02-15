//enter value from user. first value should be stored at end of list, second at second last position and so on.
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next; 
}*head;