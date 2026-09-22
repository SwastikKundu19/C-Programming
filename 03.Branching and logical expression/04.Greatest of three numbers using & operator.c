//Write a program to find greatest of three numbers using & operator.

//Code:-

#include <stdio.h>
int main()
{
	int a,b,c;
	printf("Enter three number = ");
	scanf("%d %d %d",&a,&b,&c);
	if(a>=b&&a>=c)
		printf("%d is greatest",a);
	else if(b>=a&&b>c)
		printf("%d is greatest",b);
	else
		printf("%d is greatest",c);
	return 0;
}

//Output:-

/*

Enter three number = 3
4
5
5 is greatest

*/