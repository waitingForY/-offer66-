#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int increment(char* number)
{
	int ntakeover=0;//这个表示进位；
	int length=strlen(number);
	int i;
	int isoverflow=0;
	for(i=length-1;i>=0;i--)
	{
		int nSum=number[i]-'0'+ntakeover;
		if(i==length-1)
		  nSum++;
		if(nSum>=10)
		{
			if(i==0)
			  isoverflow=1;//如果第一位发生了进位；return
			else
			{
				nSum-=10;
				ntakeover=1;
				number[i]=nSum+'0';
			}
		}
		else
		{
			number[i]='0'+nSum;
			break;
		}
	}
	return isoverflow;
}

void printNumber(char *number)
{
	int beginwith0=1;
	int length=strlen(number);
	int i;
	for(i=0;i<length;++i)
	{
		if(beginwith0&&number[i]!='0')
		  beginwith0=0;
		if(!beginwith0)
		  printf("%c",number[i]);
	}
	printf(",");
}

int main(void)
{
	
	int n;
	printf("input:");
	scanf("%d",&n);
	if(n==0)
	  exit(EXIT_FAILURE);
	char *number=(char*)malloc(n+1);
	memset(number,'0',n+1);
	number[n]='\0';
	while(!increment(number))
	{
		printNumber(number);
	}
	printf("\n");
	return 0;
}
