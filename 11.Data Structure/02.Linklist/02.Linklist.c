//Code:-

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int i;
	struct node *next;
}node;

node* create_linklist(int*,int,int);
node* create_node(int);
void display_linkedlist(node*);

int main()
{
	int arr[]={11,99,33,22};
	int n = sizeof(arr)/sizeof(arr[0]);
	node *head = NULL;
	head = create_linklist(arr,0,n-1);
	printf("Linklist is = ");
	display_linkedlist(head);
	return 0;
}

node* create_linklist(int *arr,int l,int h)
{
	int i = h;
	node *head = NULL, *save = NULL, *ptr = NULL;
	while(i >= 1)
	{
		ptr = create_node(arr[i]);
		ptr->next = save;
		save = ptr;
		i--;
	}
	head = save;
	return head;
}

node* create_node(int item)
{
	node *ptr=(node*)malloc(sizeof(node));
	ptr -> i = item;
	ptr ->next = NULL;
	return ptr;
}

void display_linkedlist(node *head)
{
	node *ptr=head;
	while(ptr != NULL)
	{
		printf("%d->",ptr -> i);
		ptr = ptr -> next;
	}
	printf("NULL");
}

//Output:-

/*
Linklist is = 11->99->33->22->NULL
*/