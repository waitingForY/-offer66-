#include <stdio.h>
#include <stdlib.h>


long fibonicc(unsigned int n)
{
	long res[2]={0,1};
	if(n<2)
	{
		return res[n];
	}

	long fibn=0;
	long fib1=0;
	long fib2=1;
	int i;
	for(i=2;i<=n;++i)
	{
		fibn=fib1+fib2;
		fib1=fib2;
		fib2=fibn;
	}
	return fibn;
}

int main(void)
{
	int n;
	printf("input:");
	scanf("%d,",&n);
	printf("the res=%ld\n",fibonicc(n));
	return 0;
	
}
