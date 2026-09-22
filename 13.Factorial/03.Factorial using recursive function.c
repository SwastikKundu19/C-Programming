//Write a program to print the factorial of given number using recursive function.

//Code:-

#include <stdio.h>
int fact(int n)
{
	if(n<0)
	{
		printf("Error:Cannot be negative");
		exit (-1);
	}
	if((n==0)||(n==1))
		return 1;
	else
		return (n*fact(n-1));
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