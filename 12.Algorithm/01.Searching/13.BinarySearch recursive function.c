//Code:-

#include <stdio.h>
int recursive_binary_search(int arr[],int left , int right ,int key)
{
	int mid=(left + right )/2;
	if(arr[mid]==key)
	{
		return (mid);
	}
	else if(arr[mid]>key)
	{
	    return (recursive_binary_search(arr,left,mid-1,key));
	}
	else
	{
	    return (recursive_binary_search(arr,mid+1,right,key));
	}
}



int main(int argc, char** argv)
{
	int a[]={2,4,5,6,7,8,9,15,100};
	int key,pos;
	int size=sizeof(a)/sizeof(a[0]);
	printf("Enter the key : ");
	scanf("%d",&key);
	pos=recursive_binary_search(a,0,size-1,key);
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

