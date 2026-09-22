//Write a program to print the factorial of given number using tail recursion.

#include <stdio.h>
int tail_fact(int n ,int acc)
{
	if(n<=1)
		return acc;
	else return ((tail_fact(n-1,n*acc)));
}

int fact (int n)
{
	tail_fact(n,1);
}

int main()
{
	int n;
	printf("Enter a number = ");
	scanf("%d",&n);
	if(n<0)
	{
		printf("Error:Cannot be negative");
		exit (-1);
	}
	else
	{
		printf("The factorial is = %d",fact(n));
	}
	return 0;
}

//Output:-

/*

Enter a number = 5
The factorial is = 120

*/