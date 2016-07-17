#include <stdio.h>
#include <stdlib.h>

void reOrder(int *arr,int len)
{
	int begin=0;
	int end=len-1;
	while(begin<end)
	{
		while(begin<end && (arr[begin] & 0x1)==1)
		  begin++;
		while(begin<end && (arr[end] & 0x1)==0)
		  end--;
		if(begin<end)
		{
			int tmp=arr[begin];
			arr[begin]=arr[end];
			arr[end]=tmp;
		}
	}
}
int main(void)
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	reOrder(arr,10);
	int i;
	for(i=0;i<10;++i)
	  printf("%d,",arr[i]);
	printf("\n");
	return 0;
}
