//������ 
#pragma once 
#include "Character.h"

class Enemy : public Character
{
public:
	char item[12]; //������Ʒ���� 
	int attack; //���� 
	int defense; //���� 
	int money; //��Ǯ 
	long int exp; //����ֵ 
	int item_sign; //��Ʒ��Ӧ���� 
	int itempro; //��Ʒ��ǿ 
	int double_attack; //���� 
	int miss; //���� 
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

