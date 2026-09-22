//Code:-

#include<stdio.h>
int main()
{
	int num1,num2,i,pow=1;
	printf("Enter a number = ");
	scanf("%d",&num1);
	printf("Enter power of this number = ");
	scanf("%d",&num2);
	for(i=1;i<=num2;i++)
	{
 		pow=pow*num1;
	}
	printf("Power of this number = %d",pow);
	return 0;
}

//Output:-

/*

Enter a number = 2
Enter power of this number = 3
Power of this number = 8

*/