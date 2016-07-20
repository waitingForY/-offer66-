#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int partition(int *arr,int start,int end)
{
	int set=start-1;
	for(int i=start;i<=end;++i)
	{
		if(arr[i]<=arr[end-1])
		{
			int tmp=arr[++set];
			arr[set]=arr[i];
			arr[i]=tmp;
		}
	}
	return set;
}

void find(int *arr,int start,int end,int num)
{
	if(arr==NULL|| start<0||end<=0||num<0)
	  return;
	int index=partition(arr,start,end);
	while(index!=num)
	{
		if(index>num)
		  index=partition(arr,start,index);
		else
		  index=partition(arr,index,end);
	}
	for(int i=0;i<index;++i)
	  printf("%d,",arr[i]);
	printf("\n");
}

int main(void)
{
	int arr[]={4,5,1,6,2,7,3,8};
	find(arr,0,7,6);
	return 0;
}
