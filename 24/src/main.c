#include <stdio.h>
#include <stdlib.h>

int islastorder(int *order,int length)
{
	if(order==NULL||length<=0)
	  return 0;
	int root=order[length-1];
	int i=0;
	while(i<length-1)
	{
		if(order[i]>root)
		  break;
		i++;
	}
	int j=i;
	while(j<length-1)
	{
		if(order[j]<root)
		  return 0;
		j++;
	}
	int left=1;
	if(i>0)
	  left=islastorder(order,i);
	int right=1;
	if(i<length-1)
	  right=islastorder(order+i,length-i-1);
	return left&&right;
}

int main(void)
{
	int order[]={5,7,6,9,11,10,8};
	printf("result=%s\n",islastorder(order,7)==1?"yes":"no");
	return 0;
}
