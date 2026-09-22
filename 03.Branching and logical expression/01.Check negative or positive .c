//Write a program to find whether a given number is positive.

//Code:-

#include <stdio.h>
int main()
{
	int a;
	printf("Enter a number = ");
	scanf("%d",&a);
	if(a>0)
		printf("%d is positive",a);
	else if(a==0)
		printf("%d is zero",a);
	else
		printf("%d is negative",a);
	return 0;
}

//Output:-

/*

Enter a number = 3
3 is positive

Enter a number = -3
-3 is negative

*/