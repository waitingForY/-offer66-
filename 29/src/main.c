#include <stdio.h>
#include <stdlib.h>

int find(int *arr,int length)
{
	if(arr==NULL||length<0)
	  exit(EXIT_FAILURE);
	int result=arr[0];
	int times=1;
	int i=1;
	while(i<length)
	{
		if(times==0)
		{
			result=arr[i];
			times=1;
		}
		else if(arr[i]==result)
		  times++;
		else
		  times--;
		i++;
	}
	if(times>0)
	  return result;
	else
	  exit(EXIT_FAILURE);
}

int main(void)
{
	int arr[]={1,3,2,2,2,4,2,2,2,5};
	int result=find(arr,10);
	printf("result=%d\n",result);
	return 0;
}
