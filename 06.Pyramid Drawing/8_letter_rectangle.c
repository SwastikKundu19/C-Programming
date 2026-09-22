/*
    ABCD
    ABCD
    ABCD
    ABCD
    ABCD
*/

#include <stdio.h>
int main()
{
	int r,c,i,j,a,d;
	char ch;
	printf("Enter number of rows=");
	scanf("%d",&r);
	printf("Enter number of columns=");
	scanf("%d",&c);
	for(i=1;i<=r;i++)
	{
		a=1;
		for(j=1;j<=c;j++)
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