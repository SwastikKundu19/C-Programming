//Write a program to print the factorial of given number using function.

//Code:-

#include <stdio.h>
int fact(int n)
{
	int i,fact=0;
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
	}
	return (fact);
}

int main()
{
	int n;
	printf("Enter a number = ");
	scanf("%d",&n);
	
	printf("The factorial is = %d",fact(n));
	return 0;
}

//Output:-

/*

Enter a number = 5
The factorial is = 120

*/