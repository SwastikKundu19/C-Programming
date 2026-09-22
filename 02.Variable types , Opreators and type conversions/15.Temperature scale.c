//Write a c program top calculate fahrenheit temperature using the input temperature to centigrade temperature.

//Code:-

#include <stdio.h>
int main()
{
	float f , c ;
	printf("Enter a centigrade temperature = ");
	scanf("%f",&c);
	f=(9*c+160)/5 ;
	printf("Fahrenheit temperature = %f ",f);
	return 0;
}

//Output:-

/*

Enter a centigrade temperature = 20.67
Fahrenheit temperature = 69.206001

*/