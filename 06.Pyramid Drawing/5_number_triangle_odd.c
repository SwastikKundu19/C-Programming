/*
    1
    13
    135
    1357
*/

#include <stdio.h>
int main()
{
	int r,i,j,a;
	printf("Enter number of rows=");
	scanf("%d",&r);
	for(i=1;i<=r;i++)
	{
		a=1;
		for(j=1;j<=i;j++)
		{
			printf("%d",a);
			a=a+2;
		}
		printf("\n");
	}
	return 0;
}