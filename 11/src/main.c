#include <stdio.h>
#include <stdlib.h>

double powerWithUnsignedExponent(double base,unsigned int exponent)
{
	if(exponent==0)
	  return 0;
	if(exponent==1)
	  return base;
	double result=powerWithUnsignedExponent(base,exponent>>1);
	result*=result;
	if((exponent & 0x1)==1)
	  result*=base;
	return result;
}

double myPower(double base,int exponent)
{
	unsigned int absExponent;
	if(exponent<0)
	  absExponent=(unsigned int)-exponent;
	else
	  absExponent=(unsigned int)exponent;
	double result=powerWithUnsignedExponent(base,absExponent);
	if(exponent<0)
	  result=1.0/result;
	return result;

}
int main(void)
{
	double base;
	int exponent;
	double result;
	printf("input base:");
	scanf("%lf",&base);
	printf("input exponent:");
	scanf("%d",&exponent);
	result=myPower(base,exponent);
	printf("result=%lf\n",result);
	return 0;
}
