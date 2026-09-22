#define max 100
#include <stdio.h>
#include <stdlib.h>

typedef struct stk
{
	int data[max];
	int top;
}stk;

stk s1;

void push(stack*s)
{
	if(s->top>=max)
	{
		printf("Error : Stack Overflow ");
		exit(-1);
	}
	else if(s->top<0)
	{
		s->top=0;
		s->data[s->top]=x;
	}
	else
	{
		/*
		s->top++;
		s->data[s->top]=x;
		
		This code in one line below
		*/
		s->data[++s->top]=x;
	}
}

int pop(stk*s)
{
	if(s->top<0)
	{
		printf("Error : Stack underflows ");
		exit(-1);
	}
	else
	{
		return(s->data[s->top--]);
	}
}

int isEmpty(stk*s)
{
	if(s->top<0)
		return(1);
	else
		return(0); 
}

void display(stk*s)
{
	int i;
	if(s->top<0)
	{
		printf("\nThe stack is empty");
	}
	else
	{
		for(i=o;i<s->top;i++)
		{
			printf("%d-",s->data[i]);
		}
	}
}

int main()
{
	stk s1;
	s1.
	push(&s1,10);
	push(&s1,10);
	push(&s1,10);
	printf("\n The first stack is ");
	display(&s1);
	return 0;
}