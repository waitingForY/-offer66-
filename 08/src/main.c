#include <stdio.h>
#include <stdlib.h>

int minInOrder(int *arr,int begin,int end)
{
	int i;
	int min=arr[begin];
	for(i=begin+1;i<=end;++i)
	{
		if(arr[i]<min)
		  min=arr[i];
	}
	return min;
}

int findMin(int *arr,int len)
{
	int begin=0;
	int end=len-1;
	int min=arr[end];
	while(arr[begin]>=arr[end])
	{
		if(end-begin==1)
		{
			min=arr[end];
			break;
		}
		int mid=(begin+end)/2;
		if(arr[begin]==arr[end]&&arr[begin]==arr[mid])
		  min=minInOrder(arr,begin,end);
		if(arr[mid]>arr[begin])
		  begin=mid;
		if(arr[mid]<arr[end])
		  end=mid;
	}
	return min;
}

int main(void)
{
	int arr[]={4,5,1,2,3};
	int res=findMin(arr,5);
	printf("min=%d\n",res);
	return 0;
}
