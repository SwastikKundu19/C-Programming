#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int c;
	struct node *L;
	struct node *R;
}node;
node* createNode(int);
node* createList();
void displayList(node*);
node* createBST(node*);
void inOrder(node*);
node* search(node*,int);
node* searchIterative(node*,int);
node* insert(node*,int);
node* insertIterative(node*,int);
node* searchParent(node*,node*,int);
node* searchParentIterative(node*,node*,int);
node* minElement(node*);
node* minElementIterative(node*);
node* maxElement(node*);
node* maxElementIterative(node*);
node* InorderSuccessor(node*,int);
node* InorderPredessor(node*,int);
node* deleteItem(node*,node*,int);
int main(int argc, char** argv)
{
	int item;
	node *ptr = createList();
	displayList(ptr);
	printf("\n");
	ptr = createBST(ptr);
	inOrder(ptr);
	printf("\n");
	
	scanf("%d",&item);
	//node* succ = InorderPredessor(ptr,item);
	//printf("%d\n",succ->c);
	ptr = deleteItem(ptr,NULL,item);
	inOrder(ptr);
	return 0;
}
node* createNode(int item)
{
	node *ptr = (node*)malloc(sizeof(node));
	ptr->c = item;
	ptr->L = NULL;
	ptr->R = NULL;
	return ptr;
}
node* createList()
{
	int n,i,item;
	printf("Enter the no of item to insert:");
	scanf("%d",&n);
	printf("\nEnter the items:");
	i = 0;
	node *head = NULL, *save = NULL, *ptr = NULL;
	while(i < n)
	{
		scanf("%d",&item);
		ptr = createNode(item);
		if(head == NULL)
		{
			head = ptr;
		}
		else
		{
			save->R = ptr;
		}
		save = ptr;
		i++;
	}
	return head;
}
void displayList(node *head)
{
	node *ptr = head;
	printf("\nHead->");
	while(ptr != NULL)
	{
		printf("%d->",ptr->c);
		ptr = ptr->R;
	}
	printf("NULL");
}
node* createBST(node *head)
{
	if(head == NULL)
		return NULL;
	node *root = createNode(head->c);
	node *ptr = head;
	while(ptr->R != NULL)
	{
		node *next = root;
		while(next != NULL)
		{
			if(ptr->R->c < next->c)
			{
				if(next->L == NULL)
				{
					next->L = createNode(ptr->R->c);
					break;
				}
				next = next->L;
			}
			else
			{
				if(next->R == NULL)
				{
					next->R = createNode(ptr->R->c);
					break;
				}
				next = next->R;
			}
		}
		ptr = ptr->R;
	}
	return root;
}
void inOrder(node *root)
{
	if(root!= NULL)
	{
		inOrder(root->L);
		printf("%d ",root->c);
		inOrder(root->R);
	}
}
node* search(node *root,int item)
{
	if(root == NULL)
		return NULL;
	if(root->c == item)
		return root;
	else if(root->c > item)
	{
		return search(root->L,item);
	}
	else
	{
		return search(root->R,item);
	}
}
node* searchIterative(node *root,int item)
{
	if(root == NULL)
		return NULL;//unsuccess
	node *ptr = root;
	while(ptr!=NULL)
	{
		if(ptr->c == item)
			return ptr; //success
		else if(ptr->c > item)
		{
			ptr = ptr->L;
		}
		else
		{
			ptr = ptr->R;
		}		
	}
	return NULL;//unsuccess
}
node* insert(node *root,int item)
{
	if(root == NULL)
	{
		root = createNode(item);
		return root;
	}
	if(item < root->c)
	{
		if(root->L == NULL)
		{
			root->L = createNode(item);
		}
		else
		{
			root->L = insert(root->L,item);
		}
	}
	else
	{
		if(root->R == NULL)
		{
			root->R = createNode(item);
		}
		else
		{
			root->R = insert(root->R,item);
		}
	}
	return root;
}
node* insertIterative(node *root, int item)
{
	if(root == NULL)
	{
		root = createNode(item);
		return root;
	}
	node *ptr = root;
	while(ptr != NULL)
	{
		if(item < ptr->c)
		{
			if(ptr->L == NULL)
			{
				ptr->L = createNode(item);
				break;
			}
			else
			{
				ptr = ptr->L;
			}
		}
		else
		{
			if(ptr->R == NULL)
			{
				ptr->R = createNode(item);
				break;
			}
			else
			{
				ptr = ptr->R;
			}
		}
	}
	return root;
}
node* searchParent(node *root,node *parent,int item)
{
	if(item == root->c)
	{
		return parent;
	}
	else
	{
		if(item < root->c)
		{
			return searchParent(root->L,root,item);
		}
		else
		{
			return searchParent(root->R,root,item);
		}
	}
}
node* searchParentIterative(node *root, node *parent, int item)
{
	if(item == root->c)
	{
		return parent;
	}
	node *ptr = root;
	while(ptr != NULL)
	{
		if(item == ptr->c)
		{
			break;
		}
		if(item < ptr->c)
		{
			parent = ptr;
			ptr = ptr->L;			 
		}
		else
		{
			parent = ptr;
			ptr = ptr->R;
		}
	}
	return parent;
}
node* minElement(node *root)
{
	if(root == NULL)
		return root;
	if(root->L != NULL)
	{
		return minElement(root->L);
	}
	else
	{
		return root;
	}
}
node* minElementIterative(node *root)
{
	if(root == NULL)
		return root;
	node *ptr = root;
	while(ptr->L != NULL)
	{
		ptr = ptr->L;
	}
	return ptr;
}
node* maxElement(node *root)
{
	if(root == NULL)
		return root;
	if(root->R != NULL)
		return maxElement(root->R);
	else
		return root;
}
node* maxElementIterative(node *root)
{
	if(root == NULL)
		return root;
	node *ptr = root;
	while(ptr->R != NULL)
	{
		ptr = ptr->R;
	}
	return ptr;
}
node* InorderSuccessor(node *root,int item)
{
	node* ptr = search(root,item);
	if(ptr->R != NULL)
		return minElement(ptr->R);
	node *parent = searchParent(root,NULL,ptr->c);
	while(parent != NULL && parent->R == ptr)
	{
		ptr = parent;
		parent = searchParent(root,NULL,ptr->c);
	}
	return parent;
}
node* InorderPredessor(node *root,int item)
{
	node* ptr = search(root,item);
	if(ptr->L != NULL)
		return maxElement(ptr->L);
	node *parent = searchParent(root,NULL,ptr->c);
	while(parent != NULL && parent->L == ptr)
	{
		ptr = parent;
		parent = searchParent(root,NULL,ptr->c);
	}
	return parent;
}
node* deleteItem(node *root,node *parent,int item)
{
	if(root == NULL)
		return root;
	if(item < root->c)
	{
		if(root->L != NULL)
		{
			deleteItem(root->L,root,item);
		}
		return root;
	}
	if(item >root->c)
	{
		if(root->R != NULL)
		{
			deleteItem(root->R,root,item);
		}
		return root;
	}
	if(root->L == NULL && root->R == NULL)
	{
		if(parent == NULL)
		{
			root = NULL;
		}
		else
		{
			if(root == parent->L)
			{
				parent->L = NULL;
			}
			else
			{
				parent->R = NULL;
			}
		}
		return root;
	}
	else if(root->L != NULL && root->R == NULL)
	{
		if(parent == NULL)
		{
			root = root->L;
		}
		else
		{
			if(root == parent->L)
			{
				parent->L = root->L;
			}
			else
			{
				parent->R = root->L;
			}
		}
		return root;
	}
	else if(root->L == NULL && root->R != NULL)
	{
		if(parent == NULL)
		{
			root = root->R;
		}
		else
		{
			if(root == parent->L)
			{
				parent->L = root->R;
			}
			else
			{
				parent->R = root->R;
			}
		}
		return root;
	}
	else if(root->L != NULL && root->R != NULL)
	{
		node *pred = maxElement(root->L);
		int i = pred->c;
		deleteItem(root->L,root,pred->c);
		root->c = i;
		return root;
	}
	return root;
}












