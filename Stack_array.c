#include<stdio.h>
int stack[100], choice, n, top, x, i;
void push(void);
void display(void);
void pop(void);
void push()
{
  if(top>=n-1)
  {
		printf("STACK is over flow");
	}
  else
  {
    printf(" Enter a value to be pushed:");
    scanf("%d",&x);
    top++;
    stack[top]=x;
	}
}
void pop()
{
	if(top<=-1)
	{
		printf("stack is underflow");
	}
	else
	{
		top --;
	}
}
void display()
{
  int i;
  if(top == -1)
  {
    printf("Stack is empty");
  }
  else
  {
	  printf("Stack elements are:\n");
    for(i=top; i>=0; i--)
    {
      printf("%d\n",stack[i]);
    }
  }
}
int main()
{
    top = -1;
    printf(" Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("STACK OPERATIONS USING ARRAY");
    printf(" 1.PUSH");
    printf(" 2.POP");
    printf(" 3.DISPLAY");
    printf(" 4.EXIT");
    do
    {
        printf(" Enter the Choice:");
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
                printf(" Exit Point ");
                break;
            }
            default:
            {
                printf(" Please Enter a Valid Choice(1/2/3/4)");
            }
        }
    }
    while(choice!=4);
    return 0;
}