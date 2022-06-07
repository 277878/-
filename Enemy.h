//怪物类 
#pragma once 
#include "Character.h"

class Enemy : public Character
{
public:
	char item[12]; //掉落物品名称 
	int attack; //攻击 
	int defense; //防御 
	int money; //金钱 
	long int exp; //经验值 
	int item_sign; //物品对应号码 
	int itempro; //物品加强 
	int double_attack; //暴击 
	int miss; //闪避 
	Enemy(const char* name, const char item[12], int attack, int defense, int hp, int money, long int exp, int item_sign, int itempro, int double_attack, int miss) : Character(name, hp)
	{
		strcpy(this->item, item);
		this->attack = attack;
		this->defense = defense;
		this->money = money;
		this->exp = exp;
		this->item_sign = item_sign;
		this->itempro = itempro;
		this->double_attack = double_attack;
		this->miss = miss;
	}
};

