/*
     54321
      4321
       321
        21
         1
*/

#include <stdio.h>
int main()
{
	int r,i,j;
	printf("Enter number of rows=");
	scanf("%d",&r);
	for(i=r;i<=0;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
	return 0;
}
//not solve