#include <stdio.h>

void print_array(int arr[],int n);
void bubble_sort(int arr[],int n);
void modified_bubble_sort(int arr[],int n);
void selection_sort(int arr[],int n);
void insertion_sort(int arr[],int n);
//void merge_sort(int arr[],int n);
//void quick_sort(int arr[],int n);

int main()
{
	int a[]={5,7,3,9,8,12,10,11,25,34};
	int n=sizeof(a)/sizeof(a[0]);
	
	char i;
	printf("You press:-\n Bubble sort code = B \n modified_bubble_sort code = b \n Selection sort code = S \n Insertion sort code = I \n Merge sort code = M \n Quick sort code = Q \n\n");
	printf("Press your choosable sorting code = ");
	scanf("%c",&i);
	
	switch(i)
	{
	   case 'B':
			bubble_sort(a,n);
			break;
		case 'b':
			modified_bubble_sort(a,n);
			break;
		case 'S':
			selection_sort(a,n);
			break;
	    case 'I':
			insertion_sort(a,n);
			break;
		/*case 'M':
			merge_sort(a,n);
			break;
		case 'Q':
			quick_sort(a,n);
			break;*/
	    default:printf("press correct symbol");
	}
	
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


void bubble_sort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("Bubble sort : ");
	print_array(arr,n);
}


void modified_bubble_sort(int arr[],int n)
{
	int i,j,flag,temp;
		for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	printf("Modified bubble sort : ");
	print_array(arr,n);
}


void selection_sort(int arr[],int n)
{
	int i,j,smallest,pos;
	for(i=0;i<n-1;i++)
	{
		smallest=arr[i];
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<smallest)
			{
				smallest=arr[j];
				pos=j;
			}
		}
		arr[pos]=arr[i];
		arr[i]=smallest;
	}
	printf("Selection sort : ");
	print_array(arr,n);
	
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
	printf("Insertion sort : ");
	print_array(arr,n);
}