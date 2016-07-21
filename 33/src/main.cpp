#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool compare(const string &str1,const string &str2)
{
	return str1+str2<str2+str1;
}

void numToStr(vector<int> &num,vector<string> &str)
{
	vector<int>::iterator it=num.begin();
	while(it!=num.end())
	{
		stringstream ss;
		ss<<*it;
		string tmp=ss.str();
		str.push_back(tmp);
		++it;
	}
}

void printResult(vector<string> &str)
{
	sort(str.begin(),str.end(),compare);
	string result;
	for(vector<string>::iterator it=str.begin();it!=str.end();++it)
	{
		result.append(*it);
	}
	cout<<result<<endl;
}

int main(void)
{
	vector<int> num={3,32,321};
	vector<string> str;
	numToStr(num,str);
	printResult(str);
	return 0;
}
