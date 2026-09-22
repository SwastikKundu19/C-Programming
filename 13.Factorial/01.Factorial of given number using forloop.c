//Write a program to print the factorial of given number using forloop.

//Code:-

#include <stdio.h>
int main()
{
	int i,n,fact=1;
	printf("Enter a number = ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
	}
	printf("The factorial is = %d",fact);
	return 0;
}

//Output:-

/*

Enter a number = 5
The factorial is = 120

*/