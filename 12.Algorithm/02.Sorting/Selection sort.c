// Write a program to implement selection sort.

//Code:-

#include <stdio.h>
int main()
{
	int array[100];
	int n,i,j,smallest,pos;
	printf ("Enter number of elements = ");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&array[i]);
	}
	
	//main logic
	
	for(i=0;i<n-1;i++)
	{
		smallest=array[i];
		for(j=i+1;j<n;j++)
		{
			if(array[j]<smallest)
			{
				smallest=array[j];
				pos=j;
			}
		}
		array[pos]=array[i];
		array[i]=smallest;
	}
	
	printf("The sorted array is \n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",array[i]);
	}
	return 0;
}

//Output:-

/*

Enter number of elements = 5
Enter the array elements
11
2
44
3
88
The sorted array is
2
3
11
44
88

*/