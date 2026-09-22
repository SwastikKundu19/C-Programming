#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int i;
	struct node *next;
} node;
node* create_linkedList();
node* createList();
void display_linkedList(node*);
node* insertLast(node*,int);
node* insertFirst(node*,int);
node* insertGivenItem(node*,int);
int main(int argc, char** argv)
{ 
	node *head =NULL;
	int item;
	head = createList();
	display_linkedList(head);
	printf("\n");
	printf("Enter the insert element :");
	scanf("%d",&item);
	head = insertGivenItem(head,item);
	display_linkedList(head);
	printf("\n");
	printf("Insert last node:\n");
	head = insertLast(head,item);
	display_linkedList(head);
	printf("\n");
	printf("Insert first node:\n");
	head = insertFirst(head , item);
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
node* inserGivenItem(node* head,int given_item,int insert_item)
{
	node*p=create_node(insert_item);
	node*ptr=head;
	while(ptr!=NULL)
	{
		if(given_item==ptr->i)
			break;
		else 
			ptr=ptr->next;
	}
	p->next=ptr->next;
	ptr->next=p;
	return head;
}
node* insertLast(node* head,int item)
{
	node *p = create_node(item);
	node *ptr = head;
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = p;
	return head;
}
node* insertFirst(node* head,int item)
{
	node*p = create_node(item);
	p->next = head;
	head = p;
	return head ;
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
