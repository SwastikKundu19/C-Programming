//Code:-

#include <stdio.h>
int binarySearch(int arr[], int left, int right, int key)
{
	int mid;
	while(left<=right)
	{
		mid = (left+right)/2;
		if(arr[mid]==key)
		{
			return (mid);
		}
		else if(arr[mid]>key)
		{
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	return (-1);
}

int main()
{
	int a[]={2,4,5,6,7,8,9,15,100};
	int key,pos;
	int size=sizeof(a)/sizeof(a[0]);
	printf("Enter the key : ");
	scanf("%d",&key);
	pos=binarySearch(a,0,size-1,key);
	if(pos==-1)
	{
		printf("Key not found \n");
	}
	else
	{
		printf("Key found at position = %d \n",pos);
	}
	return 0;
}

//Output:-

/*

Enter the key : 7
Key found at position = 4

*/