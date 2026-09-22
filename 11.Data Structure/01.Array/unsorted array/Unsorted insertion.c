#include <stdio.h>
void inert_at_beginning(int*,int,int,int);
int main()
{
	int item;
	int arr[7]={99,11,33,66,55,22};
	int n=7;
	printf("Enter the element=");
	scanf("%d",& item);
	inert_at_beginning(arr,0,n-2,item);
	int i;
	for(i=0;i<=n-1;i++)
	{
		printf(" %d ",arr[i]);
	}
	return 0;
}
void inert_at_beginning(int*arr,int l,int h,int item)
{
	int i;
	for(i=h;i>=l;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[l]=item;
}