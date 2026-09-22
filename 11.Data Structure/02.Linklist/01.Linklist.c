//Code:-

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int i;
	struct node *next;
}node;

node* create_linklist();
node* create_node(int);
void display_linkedlist(node*);

int main()
{
	node *head = NULL;
	head = create_linklist();
	printf("Linklist is = ");
	display_linkedlist(head);
	return 0;
}

node* create_linklist()
{
	node *head = NULL;
	head = create_node(11);
	head ->next = create_node(99);
	head ->next ->next = create_node(33); 
	head ->next ->next ->next = create_node(22);
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