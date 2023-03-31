//infix to postfix order using arrays
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(int item)
{
    if(top==MAX-1)
    {
        printf("stack overflow");
        return;
    }
    else
    {
        stack[++top]=item;
    }
}
int pop()
{
    if(top<0)
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
int priority(char symbol)
{
    if(symbol=='^')
    {
        return 3;
    }
    else if(symbol=='*'||symbol=='/'||symbol=='%')
    {
        return 2;
    }
    else if(symbol=='+'||symbol=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void infix_to_postfix(char infix[],char postfix[])
{
    int i,j=0;
    char symbol;
    for(i=0,j=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        if(symbol==' ' || symbol=='\t')
        {
            continue;
        }
        if(symbol == '(')
        {
            push(symbol);
        }
        else if(symbol==')')
        {
            while(stack[top]!='(')
            {
                postfix[j++]=pop();
            }
            pop(symbol);
        }
        else if(priority(symbol))
        {
            while(priority(stack[top])>=priority(symbol))
            {
                postfix[j++]=pop();
            }
            push(symbol);
        }
        else
        {
            postfix[j++]=symbol;
        }
    }
    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';    
}

int main()
{
    char infix[100],postfix[100];
    printf("enter the infix expression");
    gets(infix);
    infix_to_postfix(infix,postfix);
    printf("the postfix expression is");
    puts(postfix);
    return 0;
}
