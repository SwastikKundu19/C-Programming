//WRITE A PROGRAM TO CALCULATE COMPOUND INTEREST.

//Code:-

#include <stdio.h>
#include <math.h>
int main(int argc, char** argv)
{
	float p,t,r,i;
	printf("Enter Principal Amount = ");
	scanf("%f",&p);
	printf("Enter Time (Year) = ");
	scanf("%f",&t);
	printf("Enter Rate = ");
	scanf("%f",&r);
	i=p*((pow((1+r/100),t)));
	printf("COMPOUND INTEREST = %f",i);
	return 0;
}

//Output:-

/*

Enter Principal Amount = 100
Enter Time (Year) = 2
Enter Rate = 2
COMPOUND INTEREST = 104.040001

*/
