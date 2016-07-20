#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int partition(int *arr,int left,int right)
{
	int set=left-1;
	for(int i=left;i<=right;++i)
	  if(arr[i]<=arr[right])
		swap(arr[++set],arr[i]);
	return set;
}
void mergesort(int *arr,int left,int right)
{
	if(left<right)
	{
		int dipart=partition(arr,left,right);
		mergesort(arr,left,dipart-1);
		mergesort(arr,dipart+1,right);
	}
}

void printarr(int *arr,int length)
{
	int i=0;
	while(i<=length)
	{
		printf("%d,",arr[i]);
		i++;
	}
	printf("\n");
}


int main(void)
{
	int arr[]={1,6,3,2,5,7,2,3,1,8,4};
	printf("befor change:");
	printarr(arr,10);
	printf("after change:");
	//int part=partition(arr,3);
	mergesort(arr,0,10);
	printarr(arr,10);
	//printf("part=%d\n",part);
	return 0;
}
