//��ɫ�� �������������ң� 
#pragma once 
#include <string.h>
using namespace std;

class Character
{
public:
	char name[20];
	int hp;
	Character(const char *name, int hp)
	{
		strcpy(this->name, name);
		this->hp = hp;
	}
	~Character(){}
};


