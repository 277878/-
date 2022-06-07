#include "body.h"
#include "exception.h"
#include <vector>
#include <algorithm>
//STL库的使用以及为系统添加安全保护
#include "exception.h"
#include <iostream>
using namespace std;

template <class T> bool isRight(T a, T b, T c) 
{
	if (c == 0) 
	{
		throw MyException(); //抛出异常 
	}
	if (a == b / c) 
	{
		return true;
	}
	return false;
}

bool isInRange(vector<int> vec) 
{
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); it++) 
	{
		if (max(*it, 100) > 100 && max(*it, 0) < 0) 
		{
			return false;
		}
	}
	return true;
}

int main() 
{
	vector<int> vec;
	int a, b, c;
	cout << "请输入三位（100以内）数字密码：" << endl;
	cin >> a >> b >> c;
	while (getchar() != '\n');
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	try
	{
		if (isRight(a, b, c) && isInRange(vec)) 
		{
			Game temp;
			temp.run();
		}
		else
		{
			cout << "密码不正确!" << endl;
		}
	}
	catch (const char *msg) 
	{
		cerr << msg << endl;
	}
	return 0;
}
