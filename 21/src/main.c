#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

class Mystack
{
	public:
		void mypush(int value);
		void mypop();
		int getmin();
	private:
		stack<int> data_stack;
		stack<int> min_stack;
};

void Mystack::mypush(int value)
{
	data_stack.push(value);
	if(min_stack.size()==0||value<min_stack.top())
	  min_stack.push(value);
	else
	  min_stack.push(min_stack.top());
}

void Mystack::mypop()
{
	if(!data_stack.empty()&&!min_stack.empty())
	{
		data_stack.pop();
		min_stack.pop();
	}
}

int Mystack::getmin()
{
	int res;
	if(!min_stack.empty())
	{
		res=min_stack.top();
	}
	return res;
}

int main(void)
{
	Mystack mstack;
	mstack.mypush(2);
	mstack.mypush(3);
	mstack.mypush(6);
	mstack.mypush(1);
	mstack.mypop();
	mstack.mypush(4);
	mstack.mypop();
	printf("min=%d\n",mstack.getmin());
	return 0;
}
