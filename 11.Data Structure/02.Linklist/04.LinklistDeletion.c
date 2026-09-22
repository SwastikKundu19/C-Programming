#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int i;
	struct node *next;
} node;
node* create_linkedList();
node* createList();
//node* create_node(int);
void display_linkedList(node*);
node* deletelast(node*);
node* deletefirst(node*);
node* deleteGivenItem(node*,int);
int main(int argc, char** argv)
{ 
	node *head =NULL;
	int item;
	head = createList();
	display_linkedList(head);
	printf("\n");
	printf("Enter the element to delete:");
	scanf("%d",&item);
	head = deleteGivenItem(head,item);
	display_linkedList(head);
	printf("\n");
	printf("delete last node:\n");
	head = deletelast(head);
	display_linkedList(head);
	printf("\n");
	printf("delete first node:\n");
	head = deletefirst(head);
	display_linkedList(head);
	return 0;
}

node* create_node(int item)
{
	node *ptr = (node*)malloc(sizeof(node));
	ptr->i = item;
	ptr->next = NULL;
	return ptr;
}
void display_linkedList(node *head)
{
	node *ptr = head;
	while(ptr != NULL)
	{
		printf("%d ",ptr->i);
		ptr = ptr->next;
	}
}
node* createList()
{
	int n,item;
	printf("Enter the number of items : ");
	scanf("%d",&n);
	printf("Enter %d items :\n",n);
	int i = 0;
	node *head = NULL, *save = NULL,*ptr = NULL;
	while(i < n)
	{
		scanf("%d",&item);
		ptr = create_node(item);
		ptr->next = save;
		save = ptr;
		i++;
	}
	head = ptr;
	return head;
}
node* deleteGivenItem(node* head,int item)
{
	if(item == head->i)
	{
		head = head->next;
		head->next = NULL;
	}
	else
	{
		node *locp = head;
		node *loc = head->next;
		while(item != loc->i)
		{
			locp = loc;
			loc = loc->next;
		}
		locp->next = loc->next;
		loc->next = NULL;
	}
	return head;
}
node* deletelast(node *head)
{
	if(head->next == NULL)
	{
		head = NULL;
		return head;
	}
	node *loc = head->next;
	node *locp = head;
	while(loc->next != NULL)
	{
		locp = loc;
		loc = loc->next;
	}
	locp->next = loc->next;
	return head;
}
node* deletefirst(node *head)
{
	node *ptr = head;
	head = head->next;
	ptr->next = NULL;
	return head;
}


//Output:-

/*

Enter the number of items : 5
Enter 5 items :
22
33
44
55
66
66 55 44 33 22
Enter the element to delete:33
66 55 44 22
delete last node:
66 55 44
delete first node:
55 44
 
*/
