#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int c;
	int h;
	struct node *L;
	struct node *R;
}node;
node* createNode(int);
void inOrder(node*);
void preOrder(node*);
node* maxElement(node*);
node* insert(node*,int);
node* deleteNode(node*,node*,int);
int maximum(int,int);
int calculateHeight(node*);
int calculateBF(node*);
node* LL_Rotation(node*);
node* RR_Rotation(node*);
node* LR_Rotation(node*);
node* RL_Rotation(node*);

int main(int argc, char** argv)
{	
	node *root = NULL;
	root = insert(root,40);
	root = insert(root,60);
	root = insert(root,50);
	root = insert(root,33);
	root = insert(root,55);
	root = insert(root,11);
	//root = deleteNode(root,NULL,55);
//	root = deleteNode(root,NULL,60);
//	root = deleteNode(root,NULL,33);
	inOrder(root);
	printf("\n");
	preOrder(root);
	return 0;
}
node* createNode(int item)
{
	node *ptr = (node*)malloc(sizeof(node));
	ptr->c = item;
	ptr->h =  1;
	ptr->L = NULL;
	ptr->R = NULL;
	return ptr;
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
void preOrder(node *root)
{
	if(root!= NULL)
	{
		printf("%d ",root->c);
		preOrder(root->L);
		preOrder(root->R);
	}
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
		root->L = insert(root->L,item);		
	}
	else
	{
		root->R = insert(root->R,item);		
	}
	root->h = 1 + maximum(calculateHeight(root->L),calculateHeight(root->R));
	int BF = calculateBF(root);
	if(BF > 1 && item < root->L->c)
	{
		root = LL_Rotation(root);
	}
	if(BF < -1 && item > root->R->c) 
	{
		root = RR_Rotation(root);
	}
	if(BF > 1 && item > root->L->c)
	{
		root = LR_Rotation(root);
	}
	if(BF < -1 && item < root->R->c)
	{
		root = RL_Rotation(root);
	}
	return root;
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

node* deleteNode(node *root,node *parent,int item)
{
	if(root == NULL)
		return root;
	if(item < root->c)
	{
		if(root->L != NULL)
		{
			root->L = deleteNode(root->L,root,item);
		}
		//return root;
	}
	else if(item > root->c)
	{
		if(root->R != NULL)
		{
			root->R = deleteNode(root->R,root,item);
		}
		//return root;
	}
	else
	{
		if(root->L == NULL && root->R == NULL)
		{
			if(parent == NULL)
			{
				root = NULL;
			}
			else
			{
				if(parent->L == root)
				{
					parent->L = NULL;
				}
				else
				{
					parent->R = NULL;
				}
			}
			root = NULL;
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
				if(parent->L == root)
				{
					parent->L = root->L;
				}
				else
				{
					parent->R = root->L;
				}
			}
			root = root->L;
			//return root;
		}
		else if(root->L == NULL && root->R != NULL)
		{
			if(parent == NULL)
			{
				root = root->R;
			}
			else
			{
				if(parent->L == root)
				{
					parent->L = root->R;
				}
				else
				{
					parent->R = root->R;
				}
			}
			root = root->R;
			//return root;
		}
		else if(root->L != NULL && root->R != NULL)
		{
			node *pred = maxElement(root->L);
			int item = pred->c;
			//node *save = searchParent(root,parent,pred->c);
			//root->c = pred->c;
		   	deleteNode(root->L,root,pred->c);
			root->c = item;
			//return root;	
		}		
	}
	root->h = 1 + maximum(calculateHeight(root->L),calculateHeight(root->R));
	int BF = calculateBF(root);
	if(BF < -1 && (calculateBF(root->R) == 0 || calculateBF(root->R) == -1))
	{
		root = RR_Rotation(root);
	}
	if(BF < -1 && calculateBF(root->R) == 1)
	{
		root = RL_Rotation(root);
	}
	if(BF > 1 && (calculateBF(root->L) == 0 || calculateBF(root->L) == 1))
	{
		root = LL_Rotation(root);
	}
	if(BF > 1 && (calculateBF(root->L) == -1))
	{
		root = LR_Rotation(root);
	}
	return root;
}
int maximum(int i, int j)
{
	if(i > j)
		return i;
	return j;
}
int calculateHeight(node *ptr)
{
	if(ptr == NULL)
		return 0;
	return ptr->h;
}
int calculateBF(node *ptr)
{
	return (calculateHeight(ptr->L)-calculateHeight(ptr->R));
}
node* LL_Rotation(node *root)
{
	node *A = root;
	node *B = root->L;
	root = B;
	node *ptr = B->R;
	B->R = A;
	A->L = ptr;
	A->h = 1 + maximum(calculateHeight(A->L),calculateHeight(A->R));
	B->h = 1 + maximum(calculateHeight(B->L),calculateHeight(B->R));
	return B;
}
node* RR_Rotation(node *root)
{
	node *A = root;
	node *B = root->R;
	root = B;
	node *ptr = B->L;
	B->L = A;
	A->R = ptr;
	A->h = 1 + maximum(calculateHeight(A->L),calculateHeight(A->R));
	B->h = 1 + maximum(calculateHeight(B->L),calculateHeight(B->R));
	return B;
}
node* LR_Rotation(node *root)
{
	root->L = RR_Rotation(root->L);
	return LL_Rotation(root);
}
node* RL_Rotation(node *root)
{
	root->R = LL_Rotation(root->R);
	return RR_Rotation(root);
}