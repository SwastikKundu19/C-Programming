/*
    *
    *
  *****
    *
    *
*/

#include <stdio.h>
int main()
{
	int r,a=0,i,j;
	printf("Enter any odd number of rows=");
	scanf("%d",&r);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=r;j++)
		{
			a=r/2+1;
			if(j==a || i==a)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}