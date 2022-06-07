//玩家类 
#pragma once 
#include "Character.h"

struct Player : public Character
{
public:
	int attack; //攻击 
	int defense; //防御 
	long int max_hp; //最大生命值 
	int level; //等级 
	int exp; //经验值 
	int range_exp; //经验值区间 
	long int max_exp; //最大经验值 
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


