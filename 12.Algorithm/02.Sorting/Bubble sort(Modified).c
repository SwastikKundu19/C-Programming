 //Code:-

#include <stdio.h>
int main()
{
	int array[100];
	int n,temp,flag,i,j;
	printf ("Enter number of element = ");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&array[i]);
	}
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
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

Enter number of element = 5
Enter the array elements
1
55
2
88
7
The sorted array is
1
2
7
55
88

*/