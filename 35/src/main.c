#include <stdio.h>
#include <stdlib.h>


char findFirst(char *str)
{
	int hashTable[256]={0};
	if(str==NULL)
	  return '\0';
	char *p=str;
	while(*p!='\0')
	  hashTable[(int)*(p++)]++;
	p=str;
	while(*p!='\0')
	{
		if(hashTable[(int)*p]==1)
		  return *p;
		p++;
	}
	return '\0';
}

int main(void)
{
	char arr[]="abaccdeff";
	printf("%c\n",findFirst(arr));
	return 0;
}
