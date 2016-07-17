#include <stdio.h>
#include <stdlib.h>

int numberOf1(int n)
{
	int count=0;
	while(n)
	{
		count++;
		n=(n-1)&n;
	}
	return count;
}

int main(void)
{
	int n;
	printf("input:");
	scanf("%d",&n);
	printf("result=%d\n",numberOf1(n));
	return 0;
}
