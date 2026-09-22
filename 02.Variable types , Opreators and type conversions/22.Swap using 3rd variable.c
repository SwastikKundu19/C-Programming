//WRITE A PROGRAM TO SWAP THE VALUE OF TWO VARIABLE.

//Code:-

#include <stdio.h>
int main(int argc, char** argv)
{
	int a,b,temp;
	printf("Enter 1st number=");
	scanf("%d",&a);
	printf("Enter 2nd number=");
	scanf("%d",&b);
	temp =a;
	a=b;
	b=temp;
	printf("1st number=%d\n",a);
	printf("2nd number=%d",b);
	return 0;
}

//Output:-

/*



*/