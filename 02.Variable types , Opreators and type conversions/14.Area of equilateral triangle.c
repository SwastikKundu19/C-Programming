//Code:-

#include <stdio.h>
int main(int argc, char** argv)
{
	float area , side;
	printf("Enter the side of equilateral triangle = ");
	scanf("%f",&side);
	area = 0.433*side*side;     // (root3/4) = 0.433
	printf("Area of equilateral triangle = %f ",area);
	return 0;
}

//Output:-
/*

Enter the side of equilateral triangle = 23.67
Area of equilateral triangle = 242.596436

*/