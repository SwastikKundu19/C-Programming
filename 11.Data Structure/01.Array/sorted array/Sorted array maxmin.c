// Suppose the array is sorted in assending order find the maximum and minimum.

#include <stdio.h>
int min(int arr[],int n)
{
	return arr[0];
}
int max(int arr[],int n)
{
	return arr[n-1];
}
int main()
{
	int arr[]={2,4,5,7,10,12};
	int n =sizeof(arr)/sizeof(arr[0]);
	printf("Minimum element is %d",min(arr , n));
	printf("\n");
	printf("Maximum element is %d",max(arr , n));	
	return 0;
}

//Output

/*
Minimum element is 2
Maximum element is 12
*/