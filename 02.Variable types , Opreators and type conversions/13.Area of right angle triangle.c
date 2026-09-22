//Code:-

#include <stdio.h>
int main(int argc, char** argv)
{
	float area , base , height ;
	printf("Enter the base of right angle triangle = ");
	scanf("%f",&base);
	printf("Enter the height of right angle triangle = ");
	scanf("%f",&height);
	area = (base*height)/2;
	printf("Area of right angle triangle = %f ",area);
	return 0;
}

//Output:-

/*

Enter the base of right angle triangle = 2.3
Enter the height of right angle triangle = 5.2
Area of right angle triangle = 5.980000

*/
