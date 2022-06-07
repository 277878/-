#include "body.h"
#include "exception.h"
#include <vector>
#include <algorithm>
//STL���ʹ���Լ�Ϊϵͳ��Ӱ�ȫ����
#include "exception.h"
#include <iostream>
using namespace std;

template <class T> bool isRight(T a, T b, T c) 
{
	if (c == 0) 
	{
		throw MyException(); //�׳��쳣 
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
	cout << "��������λ��100���ڣ��������룺" << endl;
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
			cout << "���벻��ȷ!" << endl;
		}
	}
	catch (const char *msg) 
	{
		cerr << msg << endl;
	}
	return 0;
}
