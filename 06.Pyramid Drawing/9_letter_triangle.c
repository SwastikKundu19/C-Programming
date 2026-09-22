/*
    A
    AB
    ABC
    ABCD
*/

#include <stdio.h>
int main()
{
	int r,c,i,j,a,d;
	char ch;
	printf("Enter number of rows=");
	scanf("%d",&r);
	for(i=1;i<=r;i++)
	{
		a=1;
		for(j=1;j<=i;j++)
		{
			d=a+64;
			ch=(char)d;
			printf("%c",ch);
			a++;
		}
		printf("\n");
	}
	return 0;
}