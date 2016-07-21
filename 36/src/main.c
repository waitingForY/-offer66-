#include <stdio.h>
#include <stdlib.h>



void merge(int *arr,int *tmp,int left,int mid,int rigth)
{
	int i=left,j=mid,m=mid+1,n=rigth;
	int index=0;
	while(i<=j&&m<=n)
	{
		if(arr[i]<arr[m])
		  tmp[index++]=arr[i++];
		else
		  tmp[index++]=arr[m++];
	}
	while(i<=j)
	  tmp[index++]=arr[i++];
	while(m<=n)
	  tmp[index++]=arr[m++];
	int k;
	for(k=0;k<index;k++)
	  arr[left++]=tmp[k];
}

void sort(int *arr,int *tmp,int left,int rigth)
{
	if(left<rigth)
	{
		int mid=(left+rigth)/2;
		sort(arr,tmp,left,mid);
		sort(arr,tmp,mid+1,rigth);
		merge(arr,tmp,left,mid,rigth);
	}

}

void printarr(int *arr,int length)
{
	int i=0;
	while(i<length)
	  printf("%d,",arr[i++]);
	printf("\n");
}
int main(void)
{
	int arr[]={4,2,5,1,6,9,8,7,3};
	int tmp[9];
	sort(arr,tmp,0,8);
	printarr(arr,9);
	return 0;
}
