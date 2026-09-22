#include <stdio.h>
void travers(int*,int,int);
int main(int argc, char** argv)
{
	int arr[]={99,11,55,33,44,77};
	int n=sizeof(arr)/sizeof(arr[0]);
	travers(arr,0,n-1);
	return 0;
}
void travers(int*arr,int l,int h)
{
	int i;
	for(i=l;i<=h;i++)
	{
		printf("%d\t",arr[i]);
	}
}

//Output:-

/*

99      11      55      33      44      77

*/