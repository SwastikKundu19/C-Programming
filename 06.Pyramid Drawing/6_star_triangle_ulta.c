/*
   ****
    ***
     **
      *
*/

#include <stdio.h>
int main()
{
	int r,i,j;
	printf("Enter number of rows=");
	scanf("%d",&r);
	for(i=r;i<=0;i++)
	{
		for(j=i;j<=0;j--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
//not solve
