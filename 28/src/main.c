#include <stdio.h>
#include <stdlib.h>

void permutation(char *str,char *begin);

void test(char *str)
{
	if(str==NULL)
	  return;
	permutation(str,str);
}

void permutation(char *str,char *begin)
{
	if(*begin=='\0')
	{
		printf("%s\n",str);
	}
	else
	{
		char *pch;
		for(pch=begin;*pch!='\0';++pch)
		{
			char tmp=*pch;
			*pch=*begin;
			*begin=tmp;
			permutation(str,begin+1);
			tmp=*pch;
			*pch=*begin;
			*begin=tmp;
			
		}
	}
}

int main(void)
{
	char str[]="abcd";
	test(str);
	return 0;
}
