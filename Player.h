//����� 
#pragma once 
#include "Character.h"

struct Player : public Character
{
public:
	int attack; //���� 
	int defense; //���� 
	long int max_hp; //�������ֵ 
	int level; //�ȼ� 
	int exp; //����ֵ 
	int range_exp; //����ֵ���� 
	long int max_exp; //�����ֵ 
public:
	Player(const char name[21], int attack, int defense, int hp, int max_hp, int level, int exp, int range_exp, int max_exp) : Character(name, hp)
	{
		this->attack = attack;
		this->defense = defense;
		this->max_hp = max_hp;
		this->level = level;
		this->exp = exp;
		this->range_exp = range_exp;
		this->max_exp = max_exp;
	}
};


