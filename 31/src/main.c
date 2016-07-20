
#include <stdio.h>
#include <stdlib.h>

int find(int *arr,int length)
{
	if(arr==NULL||length<=0)
	  exit(EXIT_FAILURE);
	int i=0;
	int benifition=0;
	int max=arr[i];
	while(i<length)
	{
		benifition=arr[i]>(arr[i]+benifition)?arr[i]:arr[i]+benifition;
		max=max>benifition?max:benifition;
		i++;
	}
	return max;
}

int main(void)
{
	int arr[]={1,-2,3,10,-4,7,2,-5};
	printf("result=%d\n",find(arr,8));
	return 0;
}
