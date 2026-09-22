#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct node
{
	int i;
	struct node *l;
	struct node *r;
} node;
typedef struct stack
{
	int top;
	node* *arr;
} stack;
node* create_BT();
node* create_node(int);
void preOrderRecursive(node*);
void inOrderRecursive(node*);
void postOrderRecursive(node*);
void push(stack*,node*);
node* pop(stack*);
int isEmpty(stack*);
int isFull(stack*);
node* peek(stack*);
void preOrderNonrecursive(node*);
void inOrderNonrecursive(node*);
void postOrderNonrecursive(node*);
int main(int argc, char** argv)
{
	node *root = create_BT();
	printf("PRE Recursive : ");
	preOrderRecursive(root);
	printf("\n");
	printf("PRE Nonrecursive: ");
	preOrderNonrecursive(root);
	printf("\n");
	printf("IN Recursive : ");
	inOrderRecursive(root);
	printf("\n");
	printf("IN Nonrecursive: ");
	inOrderNonrecursive(root);
	printf("\n");
	printf("\n");
	printf("POST Recursive: ");
	postOrderRecursive(root);
	printf("\n");
	printf("POST Nonrecursive: ");
	postOrderNonrecursive(root);
	printf("\n");
	
	return 0;
}
node* create_BT()
{
	node *root = create_node(45);
	root->l = create_node(64);
	root->r = create_node(32);
	node *n1 = root->l;
	n1->l = create_node(19);
	n1 = root->r;
	n1->l = create_node(60);
	n1->r = create_node(11);
	n1=n1->l;
	n1->r = create_node(20);
	return root;
}
node* create_node(int item)
{
	node *ptr = (node*)malloc(sizeof(node));
	ptr->i = item;
	ptr->l = NULL;
	ptr->r = NULL;
	return ptr;
}
void preOrderRecursive(node *root)
{
	if(root != NULL)
	{
		printf("%d ",root->i);
		preOrderRecursive(root->l);
		preOrderRecursive(root->r);
	}
}
void inOrderRecursive(node *root)
{
	if(root != NULL)
	{	
		inOrderRecursive(root->l);
		printf("%d ",root->i);
		inOrderRecursive(root->r);
	}
}
void postOrderRecursive(node *root)
{
	if(root != NULL)
	{
		postOrderRecursive(root->l);
		postOrderRecursive(root->r);
		printf("%d ",root->i);
	}
}
void preOrderNonrecursive(node *root)
{
	stack *st = (stack*)malloc(sizeof(stack));
	st->top = -1;
	st->arr = (node**)malloc(MAX*sizeof(node*));
	node *ptr = root;
	push(st,NULL);
	while(ptr != NULL)
	{
		printf("%d ",ptr->i);
		if(ptr->r != NULL)
		{
			push(st,ptr->r);
		}
		if(ptr->l != NULL)
		{
			ptr = ptr->l;
		}
		else
		{
			ptr = pop(st);
		}
	}
	printf("\n");
}
void inOrderNonrecursive(node *root)
{
	stack *st = (stack*)malloc(sizeof(stack));
	st->top = -1;
	st->arr = (node**)malloc(MAX*sizeof(node*));
	node *ptr = root;
	push(st,NULL);
	do
	{
		while(ptr != NULL)
		{
			push(st,ptr);
			ptr = ptr->l;
		}
		ptr = pop(st);
		while(ptr != NULL)
		{
			printf("%d ",ptr->i);
			if(ptr->r != NULL)
			{
				ptr = ptr->r;
				break;
			}
			else
			{
				ptr = pop(st);
			}
		}
	}while(ptr != NULL);
}
void postOrderNonrecursive(node *root)
{
	stack *st = (stack*)malloc(sizeof(stack));
	st->top = -1;
	st->arr = (node**)malloc(MAX*sizeof(node*));
	node *ptr = root;
	push(st,NULL);
	do
	{
		while(ptr != NULL)
		{
			if(ptr->r != NULL)
			{
				push(st,ptr->r);
			}
			push(st,ptr);
			ptr = ptr->l;
		}
		ptr = pop(st);
		while(ptr != NULL)
		{	
			if(ptr->r != NULL && ptr->r == peek(st))
			{
				node *p = ptr;
				ptr = pop(st);
				push(st,p);
				break;
			}
			else
			{
				printf("%d ",ptr->i);
				ptr = pop(st);
			}
		}
	}while(ptr != NULL);
}
void push(stack *st, node *root)
{
	if(!isFull(st))
	{
		st->top = st->top + 1;
		st->arr[st->top] = root;
	}
}
node* pop(stack *st)
{
	node *ptr;
	if(!isEmpty(st))
	{
		ptr = st->arr[st->top];
		st->top = st->top - 1;
	}
	return ptr;
}
node* peek(stack *st)
{
	return st->arr[st->top];
} 
int isFull(stack *st)
{
	if(st->top == MAX - 1)
		return 1;
	return 0;
}
int isEmpty(stack *st)
{
	if(st->top == -1)
		return 1;
	return 0;
}




