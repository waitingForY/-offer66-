#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

bool ispoporder(int *input,int *output,int length)
{
	bool result=false;
	int *pin=input;
	int *pout=output;
	stack<int> tmp_stack;
	if(input==NULL||output==NULL||length<=0)
	  result=false;
	while(pout-output<length)
	{
		while(tmp_stack.empty()||tmp_stack.top()!=*pout)
		{
			if(pin-input==length)
			  break;
			tmp_stack.push(*pin);
			pin++;
		}
		if(tmp_stack.top()!=*pout)
		  break;
		tmp_stack.pop();
		pout++;
	}
	if(tmp_stack.empty()&&pout-output==length)
	  result=true;
	return result;
}

int main(void)
{
	int input[]={1,2,3,4,5};
	int output[]={4,5,3,2,1};
	string result=ispoporder(input,output,5)?"true":"false";
	//printf("result=%s\n",result);
	cout<<"result="<<result<<endl;
	return 0;
}
