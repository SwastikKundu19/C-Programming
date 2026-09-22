// Write a program to implement insertion sort.

//Code:-

#include <stdio.h>
void print_array(int arr[],int n);
void insertion_sort(int arr[],int n);
int main()
{
	int a[]={5,7,3,9,8,12,10,11,25,34};
	int n=sizeof(a)/sizeof(a[0]);
	insertion_sort(a,n);
	print_array(a,n);
	return 0;
}
void print_array(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
void insertion_sort(int arr[],int n)
{
	int key,i,j;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

//Output:-

/*



*/