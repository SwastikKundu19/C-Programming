#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int i;
	struct node *l;
	struct node *r;
} node;
node* createBT(int*,int*,int,int);
void preOrderRecursive(node*);
node* createNode();
int pertitionPreIn(int*,int*,int,int);
node* createBTPostIn(int*,int*,int,int,int);
int pertitionPostIn(int*,int*,int,int,int);
int main(int argc, char** argv)
{
	int pre[] = {11,12,14,15,13,16,17};
	int in[] = {14,12,15,11,16,13,17};
	int post[] = {14,15,12,16,17,13,11};
	int n = sizeof(pre)/sizeof(pre[0]);
	node *root = createBT(pre,in,0,n-1);
	preOrderRecursive(root);
	printf("\n");
	root = createBTPostIn(post,in,0,n-1,n);
	preOrderRecursive(root);
	printf("\n");
	return 0;
}
node* createBT(int *pre,int *in,int l,int h)
{
	if(l > h)
		return NULL;
	node *ptr = createNode();
	int i = pertitionPreIn(pre,in,l,h);
	ptr->i = in[i];
	ptr->l = createBT(pre,in,l,i-1);
	ptr->r = createBT(pre,in,i+1,h);
	return ptr;
}
node* createBTPostIn(int *post,int *in,int l,int h,int n)
{
	if(l > h)
		return NULL;
	node *ptr = createNode();
	int i = pertitionPostIn(post,in,l,h,n);
	ptr->i = in[i];
	ptr->r = createBTPostIn(post,in,i+1,h,n);
	ptr->l = createBTPostIn(post,in,l,i-1,n);
	
	return ptr;
}
int pertitionPostIn(int *post,int *in,int l,int h,int n)
{
	static int j = 0;
	int item = post[n-1-j];
	j++;
	int i;
	for(i = l; i <= h; i++)
	{
		if(item == in[i])
			return i;
	}
	return -1;
}
int pertitionPreIn(int *pre,int *in,int l,int h)
{
	static int j = 0;
	int item = pre[j++];
	int i;
	for(i = l; i <= h; i++)
	{
		if(item == in[i])
			return i;
	}
	return -1;
}
node* createNode()
{
	node *ptr = (node*)malloc(sizeof(node));
	ptr->i = 0;
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