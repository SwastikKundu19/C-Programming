#include <stdio.h>
int main(int argc, char** argv)
{
	int arr[]={2,4,6,8,10};
	int n = ((sizeof(arr)/sizeof(arr[0]))+1);
	int low =0,mid,high=n-1;
	int ie,p,i;  //position
	printf("Array element = ");
	for(i=0;i<n-1;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
	printf("Enter insert element =");
	scanf("%d",&ie);
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]<ie)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	p = low;
	for(i=n;i>p;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[p]=ie;
	n++;
	printf("Array after insert element = ");
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
}