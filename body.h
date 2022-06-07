//游戏的主要功能选项 
#pragma once 
#include "Enemy.h"
#include "Player.h"
#include "Place.h"
#include <windows.h>
#include <time.h> 
#include <fstream> 
#include <iostream>
using namespace std;

ifstream txt;
char out[1024]={0};

class Game 
{
private:
	Enemy Monster1;
	Enemy Monster2;
	Enemy Monster3;
	Enemy big_Monster3;
	Enemy Monster4;
	Enemy Monster5;
	Enemy Monster6;
	Enemy Monster;
	Enemy BOSS;
	Player player;
	Place place;
	static int fang4n;
	static int fang3n;
	static int fang2n;
	static int gong4n;
	static int gong3n;
	static int gong2n;
	static int fang1n;
	static int gong1n;
	char gongname[512];
	char fangname[512];
protected:
	int gong;
	int gong1;
	int gong2;
	int gong3;
	int gong4;
	int fang;
	int fang1;
	int fang2;
	int fang3;
	int fang4;
	char proof;
	int s;
	int smedicine, mmedicine, lmedicine, Xlmedicine, sboom, mboom, lboom, sstone, mstone, lstone, KEY;
	int choose_number;
	int battle;
	int money;
	int getNum(int min, int max) 
	{
		int r, i;
		i = 0;
		while(1)
		{
			cin >> r;
			if (r > max || r < min)
			{
				i++;
				if (i > 2)
				{
					throw "数据出错，游戏重新启动";
					return -1;
				}
				else
				{
					cout<<"请重新输入。"<<endl;
				}
			}
			else
			{
				break;
			}
		}
		return r;
    }
public:
	Game():Monster3("兔崽子", "锁子黄金甲", 40, 50, 350, 200, 100, 1, 2, 1, 0),
		   Monster2("小花兔", "凤翅紫金冠", 25, 15, 100, 50, 50, 2, 2, 1, 1),
		   Monster1("小野兔", "藕丝步云履", 18, 10, 50, 30, 35, 3, 3, 2, 2),
		   big_Monster3("兔崽子王", "胡萝卜", 40 * 5, 50 * 5, 200 * 5, 200 * 5, 100 * 5, 4, 4, 2, 0),
		   Monster6("大兔子", "名剑轩辕", 60, 30, 280, 200, 100, 5, 2, 1, 0),
		   Monster5("小白兔", "名刀月隐", 28, 12, 90, 50, 50, 6, 2, 1, 1),
		   Monster4("小黑兔", "名刀司命", 17, 11, 60, 30, 35, 7, 3, 2, 2),
		   BOSS("发出反派的笑声的兔子", "\0", 50 * 8, 50 * 8, 300 * 8, 300 * 8, 300 * 8, 9, 1, 1, 0),
		   Monster("\0", "\0", 0, 0, 0, 0, 0, 0, 0, 0, 0), //初始化 
		   player("玩家", 40, 40, 100, 100, 1, 0, 0, 100),
		   place(1, 2, 3, 4, 5, 6, 7, 8)
	{
		smedicine = 1;
		mmedicine = 1;
		lmedicine = 1;
		Xlmedicine = 1;
		sboom = 1;
		mboom = 1;
		lboom = 0;
		sstone = 0;
		mstone = 0;
		lstone = 0;
		KEY = 0;
		money = 500;
		memset(gongname, 0, 512);
		memset(fangname, 0, 512);
		gong = 0;
		gong1 = 10;
		gong2 = 50;
		gong3 = 100;
		gong4 = 300;
		fang = 0;
	    fang1 = 10;
		fang2 = 50;
		fang3 = 100;
		fang4 = 300;
	}
	void run()
	{
		int i = 0, j = 0, k = 0;
		char player_name[21] = {0};		
		Sleep(1000);
		cout << "--------------------------欢迎来到德莱联盟，王牌飞行员额走错片场了。。。。。。-----------------------\n\n\n";
		//如果想使用外挂，名字请输入：“包叽 ”。
		//如果想体验友尽，名字请输入：“兔叽 ”。 
		Sleep(1000);
		cout << "从前有座山，山上有个兔，兔兔说：“听我说，谢谢你……”\n\n\n伟大的玩家啊~拿起你们的武器,干掉统治了兔子王国上亿年的发出反派笑声的兔子吧！\n\n\n告诉我你的名字: (20个字符)\n\n\n";
		char ch;
		while (1) 
		{
			ch = getchar();
			if (ch == '\n') 
			{
				break;
			}
			if (i >= 21) 
			{
				throw "字符超过最长限制";
				break;
			}
			player_name[i++] = ch;
		}
		strncpy(player.name, player_name, 20);
		if (strcmp(player.name, "包叽") == 0)
		{
			cout << "\n\n\n封印多年的包叽血统啊!\n\n\n你终于觉醒了!\n\n\n包叽，你成为了天选之包，请你找到答案吧！\n\n\n";
			player.attack = 9999;
			player.defense = 9999;
			player.hp = 9999;
			player.max_hp = 99999;
		}
		if (strcmp(player.name, "兔叽") == 0)
		{
			cout << "\n\n\n封印多年的兔叽血统啊!\n\n\n你终于觉醒了!\n\n\n兔叽，你成为了大傻之兔，请你找到答案吧！\n\n\n";
			player.attack = 1;
			player.defense = 1;
			player.hp = 1;
			player.max_hp = 1;
		}
		OrdinaryAct();
	}
	int SuiJi()
	{
		srand((unsigned)time(NULL));
		return rand() % 10;
	}
	int SuiJi100()
	{
		srand((unsigned)time(NULL));
		return rand() % 100;
	}
	void Chooseitem()
	{
		cout << "物品: 1,小药瓶" << smedicine << "个 " << "2, 中药瓶" << mmedicine << "个" << "3, 大药瓶" << lmedicine << "个 " << "4, 圣药" << Xlmedicine << "个 " << "5, 手雷" << sboom << "个 " << "6, 导弹" << mboom << "个 " << "7, 核爆" << lboom << "个 " << "8, 小经验石" << sstone << "个 "<< "9, 中经验石" << mstone << "个 " << "10, 大经验石" << lstone << "个 " << "11, 胡萝卜" << KEY << "个 " << "0, 返回\n\n\n";
		switch (choose_number = getNum(0,11), choose_number)
		{
		case 1:
			if (smedicine > 0)
			{
				cout << "使用小药瓶,HP增加60\n\n\n";
				smedicine--;
				if (player.hp + 60 > player.max_hp)player.hp = player.max_hp;
				else player.hp += 60;
			}
			else cout << "没有小药瓶了\n\n\n";
			break;
		case 2:
			if (mmedicine > 0)
			{
				cout << "使用中药瓶,HP增加80\n\n\n";
				mmedicine--;
				if (player.hp + 80 > player.max_hp)player.hp = player.max_hp;
				else player.hp += 80;
			}
			else cout << "没有中药瓶了\n\n\n";
			break;
		case 3:
			if (lmedicine > 0)
			{
				cout << "使用大药瓶,HP增加120\nz\n\n";
				lmedicine--;
				if (player.hp + 120 > player.max_hp)player.hp = player.max_hp;
				else player.hp += 120;
			}
			else cout << "没有大药瓶了\n\n\n";
			break;
		case 4:
			if (Xlmedicine > 0)
			{
				cout << "使用圣药,HP增加200\n\n\n";
				Xlmedicine--;
				if (player.hp + 200 > player.max_hp)player.hp = player.max_hp;
				else player.hp += 200;
			}
			else cout << "没有圣药了\n\n\n";
			break;
		case 5:
			if (battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
			{
				if (sboom > 0)
				{
					cout << "使用手雷,敌人HP减少100\n\n\n";
					sboom--;
					Monster.hp -= 100;
					AttackResult();
				}
			}
			else cout << "非战斗状态,不能使用手雷!\n\n\n";
			break;
		case 6:
			if (battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
			{
				if (mboom > 0)
				{
					cout << "使用导弹,敌人HP减少200\n\n\n";
					mboom--;
					Monster.hp -= 200;
					AttackResult();
				}
			}
			else cout << "非战斗状态,不能使用导弹!\n\n\n";
			break;
		case 7:
			if (battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
			{
				if (lboom > 0)
				{
					cout << "使用核爆,敌人HP减少666666666\n\n\n";
					lboom--;
					Monster.hp -= 666666666;
					AttackResult();
				}
			}
			else cout << "非战斗状态,不能使用核爆!\n\n\n";
			break;
		case 8:
			if (sstone > 0 && player.level < 1000)
			{

				cout << "使用小经验石,等级增加10级\n\n\n";
				sstone--;
				player.level += 10;
				cout << "等级：" << player.level << "\n";
			}
			else    if (sstone < 1)
			{
				cout << "没有小经验石了\n\n\n";
			}
			else cout << "等级超过45级,修为太高，无法使用。\n\n\n";
			break;
		case 9:
			if (mstone > 0 && player.level < 1000)
			{
				if (player.level > 44 && player.level < 1000)
				{
					int sheng;
					sheng = 45 - player.level;
					player.level += sheng;
					cout << "使用中经验石,等级增加" << sheng << "级";
					cout << "等级：" << player.level << "\n";
				}
				else
				{

					cout << "使用中经验石,等级增加2级\n\n\n";
					mstone--;
					player.level += 2;
					cout << "等级：" << player.level << "\n";
				}
			}
			else if (mstone < 1)
			{
				cout << "没有中经验石了";
			}
			else cout << "等级超过45级,修为太高，无法使用。\n\n\n";
			break;
		case 10:
			if (lstone > 0 && player.level < 1000)
			{
				if (player.level > 42 && player.level < 1000)
				{
					int sheng;
					sheng = 45 - player.level;
					player.level += sheng;
					cout << "使用大经验石,等级增加" << sheng << "级\n";
					cout << "等级：" << player.level << "\n";
				}
				else
				{
					cout << "使用大经验石,等级增加10级\n";
					lstone--;
					player.level += 10;
				}
			}
			else if (lstone < 1)
			{
				cout << "没有大经验石了\n\n\n";
			}
			else cout << "等级超过45级,修为太高，无法使用。\n\n\n";
			break;
		case 11:
			if (KEY > 0 && player.level < 10000)
			{
				if (player.level > 29 && player.level < 10000)
				{
					int sheng;
					sheng = 45 - player.level;
					player.level += sheng;
					cout << "使用胡萝卜,等级增加" << sheng << "级";
					cout << "等级：" << player.level << "\n";
				}
				else
				{
					cout << "使用胡萝卜,等级增加16级\n\n\n";
					KEY--;
					player.level += 16;
					cout << "等级：" << player.level << "\n";
				}
			}
			else if (KEY < 1)
			{
				cout << "没有胡萝卜了。\n\n\n";
			}
			else cout << "等级超过45级,修为太高，无法使用。\n\n\n";
			break;
		case 0:
			break;
		default:
			cout << "Chooseitem error!\n\n\n";
		}
	}
	int AttackResult()
	{ 
		int *s = new int;
		if (Monster.hp <= 0)
		{
			battle = 0;
			cout << "战斗胜利!获得金币" << Monster.money << ",经验" << Monster.exp << "\n\n\n";
			player.exp += Monster.exp;
			player.range_exp += Monster.exp;
			money += Monster.money;
			*s = SuiJi();
			if (*s < Monster.itempro)
			{
				cout << "从敌人尸骸中发现";
				cout << Monster.item << "\n\n\n";
				Additem(Monster.item_sign);
			}
			WhetherLevelUp();
			if (strcmp(Monster.name, "发出反派的笑声的兔子") == 0)
			{
				cout << "战斗胜利，找到答案！！！";
				getchar();
				getchar();
				exit(0);
			}
			delete s;
			return 1; //攻击有结果了返回1,否则返回0,用于判断是否继续做战斗行为
		}
		else 
		{
			int s = SuiJi();

			if ((Monster.attack + s - player.defense / 3) < 0)
			{
				player.hp -= 1;
				cout << Monster.name << "反击,你的HP减少了 1\n\n";
			}
			else
			{
				player.hp -= Monster.attack + s - player.defense / 3;
				cout << Monster.name << "反击,你的HP减少了" << Monster.attack + s - player.defense / 3 << "\n\n";
			}
			if (player.hp < 0)
			{
				battle = 0;
				cout << player.name << "战死!金币掉落" << player.level * 2000 << "  满血复活!" << "\n\n\n";
				money -= player.level * 2000;
				player.hp = player.max_hp;
				OrdinaryAct();//
				return 1;
			}
		}
		return 0;
	}

	void Additem(int item_sign)
	{
		switch (item_sign)
		{
		case 1:
			fang4n++;
			break;
		case 2:
			fang3n++;
			break;
		case 3:
			fang2n++;
			break;
		case 4:
			KEY = 1;
			break;
		case 5:
			gong4n++;
			break;
		case 6:
			gong3n++;
			break;
		case 7:
			gong2n++;
			break;
		default:
			cout << "Additem error\n\n\n";
		}
	}
	void WhetherLevelUp()
	{
		int i = 0, j = 0;
		int l1 = player.range_exp / 100;
		int l2 = player.range_exp / 300;
		int l3 = player.range_exp / 600;
		if (player.level <= 15 && l1 > 0) //15级以下,经验足够 都满足则升级
		{
			if (l1 == 1)
			{
				cout << player.name;
				cout << " 升级!\n\n\n攻击力+3, 防御力+2, HP上限+20\n\n\n";
				player.exp = player.exp + Monster.exp - (player.exp + Monster.exp) % 100;
				player.attack += 3;
				player.defense += 2;
				player.max_hp += 20;
				player.hp = player.max_hp;
				player.level++;
				player.range_exp = 0;
				player.exp = player.max_exp;
				player.max_exp += 100;
			}
			else
			{
				cout << "好厉害!连升11级!";
				cout << "攻击力+" << 3 * l1 << ", 防御力 + " << 2 * l1 << ", HP上限 + " << 20 * l1 << "\n\n\n";
				player.exp = (player.exp + Monster.exp) || player.exp - ((player.exp + Monster.exp) || player.exp) % 100;
				player.attack += 3 * l1;
				player.defense += 2 * l1;
				player.max_hp += 20 * l1;
				player.hp = player.max_hp;
				player.level += l1;
				player.range_exp = 0;
				player.exp = player.max_exp;
				player.max_exp += 100 * l1;
			}
		}
		else if (player.level <= 40 && l2 > 0)
		{
			if (l2 == 1)
			{
				cout << player.name;
				cout << " 升级!\n\n\n攻击力+3, 防御力+2, HP上限+20\n\n\n";
				player.exp = player.exp + Monster.exp - (player.exp + Monster.exp) % 100;
				player.attack += 3;
				player.defense += 2;
				player.max_hp += 20;
				player.hp = player.max_hp;
				player.level++;
				player.range_exp = 0;
				player.exp = player.max_exp;
				player.max_exp += 300;
			}
			else
			{
				cout << "好厉害!连升l1级!";
				cout << "攻击力+36, 防御力+24, HP上限+240\n\n\n";
				player.exp = player.exp + Monster.exp - (player.exp + Monster.exp) % 100;
				player.attack += 3 * l2;
				player.defense += 2 * l2;
				player.max_hp += 20 * l2;
				player.hp = player.max_hp;
				player.level += l2;
				player.range_exp = 0;
				player.exp = player.max_exp;
				player.max_exp += 300 * l2;
			}
		}
		else if (l3 > 0)
		{
			if (l3 == 1)
			{
				cout << player.name;
				cout << " 升级!\n\n\n攻击力+3, 防御力+2, HP上限+20\n\n\n";
				player.exp = player.exp + Monster.exp - (player.exp + Monster.exp) % 100;
				player.attack += 3;
				player.defense += 2;
				player.max_hp += 20;
				player.hp = player.max_hp;
				player.level++;
				player.range_exp = 0;
				player.exp = player.max_exp;
				player.max_exp += 600;
			}
			else
			{
				cout << "好厉害!连升l1级!";
				cout << "攻击力+" << 3 * l3 << ", 防御力+" << 2 * l3 << ", HP上限+" << 20 * l3 << "\n\n\n";
				player.exp = player.exp + Monster.exp - (player.exp + Monster.exp) % 100;
				player.attack += 3 * l3;
				player.defense += 2 * l3;
				player.max_hp += 20 * l3;
				player.hp = player.max_hp;
				player.level += l3;
				player.range_exp = 0;
				player.exp = player.max_exp;
				player.max_exp += 600 * l3;
			}
		}
	}
	void OrdinaryAct()
	{
		int s;
		int place_sign;		
		while (1)
		{
			cout << "===================================================================================================================" << endl;
			cout << " 要做什么?\n\n\n 1,移动  2,道具  3,对话  4,查看状态  5,装备  6,关于游戏  7,查看说明 0,退出游戏\n\n\n";
			cout << "===================================================================================================================" << endl;
			switch (choose_number = getNum(0, 7), choose_number)
			{
			case 1: //显示移动菜单
				cout << "要去哪里?\n\n\n";
				cout << " 1,萝卜广场  2,萝卜小屋  3,萝卜商店  4，萝卜黑市  5，兔兔冒险 \n\n\n";
				switch (choose_number = getNum(1, 5), choose_number)
				{
				case 1:
					place_sign = place.ground; //记录目前位置-酒吧
					// OrdinaryAct();
					break;
				case 2:
					place_sign = place.house; //进入旅店
					cout << "金币：" << money;
					cout << "要休息吗? 200个金币 1,是 0,否\n\n\n";
					choose_number = 1;
					switch (choose_number = getNum(0, 1), choose_number)
					{
					case 1:
						if (money - 200 < 0) //判断钱是否够
						{
							cout << "Sorry,你的钱不够~\n\n\n";
							cout << "金币：" << money;
						}
						else
						{
							cout << "好好休息\n你的HP满了\n到第二天了\n\n";
							cout << "金币: " << money << "\n";
							money -= 200; //花费200住店费
							player.hp = player.max_hp; //体力满
						}
						break;
					case 0:
						cout << "下次再来!\n\n\n";
						break;
					default:
						cout << "house talk error!\n\n\n";
					}
					place_sign = 0;
					break;
				case 3:
					int yongju;
					cout << "您要购买什么物品？\n\n\n 1,攻击装备  2，防御装备  3,一次性武器\n\n\n";
					yongju = getNum(1, 3);
					switch (yongju)
					{
					case 1:
						int gong; 
						cout << "您要购买什么武器?\n\n\n 1,胡萝卜根￥500  2，名刀司命￥1000  3，名刀月隐￥2000\n\n\n";
						gong = getNum(1, 3);
						switch (gong)
						{
						case 1:
							if (money >= 500)
							{
								gong1n++;
								money = money - 500;
								cout << "胡萝卜根+1\n";
								cout << "胡萝卜根:" << gong1n << "个\n";
								cout << "金币：" << money << "\n";
								break;
							}
							else
							{
								cout << "钱不够!\n";
								cout << "金币：" << money << "\n";
								break;
							}
						case 2:
							if (money >= 1000)
							{
								gong2n++;
								money = money - 1000;
								cout << "名刀司命+1\n";
								cout << "名刀司命:" << gong2n << "个\n";
								cout << "金币：" << money << "\n";
								break;
							}
							else
							{
								cout << "钱不够!\n";
								cout << "金币：" << money << "\n";
								break;
							}
						case 3:
							if (money >= 2000)
							{
								gong3n++;
								money = money - 2000;
								cout << "名刀月隐+1\n";
								cout << "名刀月隐:" << gong3n << "个\n";
								cout << "金币：" << money << "\n";
								break;
							}
							else
							{
								cout << "钱不够!\n";
								cout << "金币：" << money << "\n";
								break;
							}
						default:
							cout << "对不起，我们只会打造以上武器。";
							break;
						}
						break;
					case 2:
						int fang;
						cout << "请问您要购买什么防具?\n\n\n 1,胡萝卜叶￥500  2，藕丝步云履￥1000  3，凤翅紫金冠￥2000\n\n\n";
						fang = getNum(1, 3);
						switch (fang)
						{
						case 1:
							if (money >= 500)
							{
								fang1n++;
								money = money - 500;
								cout << "胡萝卜叶+1\n";
								cout << "胡萝卜叶:" << fang1n << "个\n";
								cout << "金币：" << money << "\n";
							}
							else
							{
								cout << "钱不够!\n";
								cout << "金币：" << money << "\n";
							}

							break;
						case 2:
							if (money >= 1000)
							{
								fang2n++;
								money = money - 1000;
								cout << "藕丝步云履+1\n";
								cout << "藕丝步云履:" << fang2n << "个\n";
								cout << "金币：" << money << "\n";
							}
							else
							{
								cout << "钱不够!\n";
								cout << "金币：" << money << "\n";
							}
							break;
						case 3:
							if (money >= 2000)
							{
								fang3n++;
								money = money - 2000;
								cout << "凤翅紫金冠+1\n";
								cout << "凤翅紫金冠:" << fang3n << "个\n";
								cout << "金币：" << money << "\n";
							}
							else
							{
								cout << "钱不够!\n";
								cout << "金币：" << money << "\n";
							}
						default:
							cout << "对不起，我们只会打造以上防具。";
							break;
						}
						cout << "金币：" << money << "\n";
						break;
					case 3:
						cout << "请问您要购买什么一次性伤害武器？\n 1,手雷￥1000  2，导弹￥2000  3，核爆￥5000\n\n\n";
						int o;
						o = getNum(1, 3);
						switch (o)
						{
						case 1:
							if (money >= 1000 && sboom < 5)
							{
								sboom++;
								money = money - 1000;
								cout << "手雷 +1\n";
								cout << "手雷：" << sboom << "\n";
								cout << "金币：" << money << "\n";
							}
							else
							{
								cout << "钱不够!\n";
								cout << "金币：" << money << "\n";
							}
							break;
						case 2:
							if (money >= 2000 && mboom < 4)
							{
								mboom++;
								money = money - 2000;
								cout << "导弹 +1\n";
								cout << "导弹：" << mboom << "\n";
								cout << "金币：" << money << "\n";
							}
							else
							{
								cout << "钱不够!\n";
								cout << "金币：" << money << "\n";
							}
							break;
						case 3:
							if (money >= 5000 && lboom < 2)
							{
								lboom = lboom + 1;
								money = money - 5000;
								cout << "核爆 +2\n";
								cout << "核爆：" << lboom << "\n";
								cout << "金币：" << money << "\n";
							}
							else
							{
								cout << "钱不够!\n\n\n";
								cout << "金币：" << money << "\n";
							}
							break;
						}
					}
					break;
				case 4:
					cout << "欢迎您光临本黑市，请问您要卖什么东西？\n\n";
					cout << "攻击装备: 1,胡萝卜根:" << gong1n << "个 " << "2,名刀司命：" << gong2n << "个 " << "3,名刀月隐:" << gong3n << "个 " << "4,名剑轩辕:" << gong4n << "个\n";
					cout << "防御装备: 5,胡萝卜叶:" << fang1n << "个 " << "6,藕丝步云履:" << fang2n << "个 " << "7,凤翅紫金冠:" << fang3n << "个 " << "8,锁子黄金甲:" << fang4n << "个\n" << "9，胡萝卜:" << KEY << "个 " << "0,返回\n\n\n";
					int m, n, i;
					m = getNum(0, 9);
					switch (m)
					{
					case 1:
						cout << "请问您要出售几件？";
						scanf("%d", &n);
						if (gong1n >= n)
						{
							gong1n = gong1n - n;
							money = money + n * 240;
							cout << "胡萝卜根：" << gong1n << "\n";
							cout << "金币：" << money << "\n";
							break;
						}
						else
						{
							cout << "装备数不够，无法出售！\n";
							break;
						}
						break;
					case 2:
						cout << "请问您要出售几件？\n";
						scanf("%d", &n);
						if (gong2n >= n)
						{
							gong2n = gong2n - n;
							money = money + n * 400;
							cout << "名刀司命：" << gong2n << "\n";
							cout << "金币：" << money << "\n";
							break;
						}
						else
						{
							cout << "装备数不够，无法出售！\n";
							break;
						}
					case 3:
						cout << "请问您要出售几件？\n";
						scanf("%d", &n);
						if (gong3n >= n)
						{
							gong3n = gong3n - n;
							money = money + n * 800;
							cout << "名刀月隐：" << gong3n << "\n";
							cout << "金币：" << money << "\n";
							break;
						}
						else
						{
							cout << "装备数不够，无法出售！\n";
							break;
						}
					case 4:
						cout << "请问您要出售几件？\n";
						scanf("%d", &n);
						if (gong4n >= n)
						{
							gong4n = gong4n - n;
							money = money + n * 1500;
							cout << "名剑轩辕：" << gong4n << "\n";
							cout << "金币：" << money << "\n";
							break;
						}
						else
						{
							cout << "装备数不够，无法出售！\n";
							break;
						}
					case 5:
						cout << "请问您要出售几件？\n";
						scanf("%d", &n);
						if (fang1n >= n)
						{
							fang1n = fang1n - n;
							money = money + n * 240;
							cout << "胡萝卜叶：" << fang1n << "\n";
							cout << "金币：" << money << "\n";
							break;
						}
						else
						{
							cout << "装备数不够，无法出售！\n";
							break;
						}
					case 6:
						cout << "请问您要出售几件？\n";
						scanf("%d", &n);
						if (fang2n >= n)
						{
							fang2n = fang2n - n;
							money = money + n * 500;
							cout << "藕丝步云履：" << fang2n << "\n";
							cout << "金币：" << money << "\n";
							break;
						}
						else
						{
							cout << "装备数不够，无法出售！\n";
							break;
						}
					case 7:
						cout << "请问您要出售几件？\n";
						scanf("%d", &n);
						if (fang3n >= n)
						{
							fang3n = fang3n - n;
							money = money + n * 800;
							cout << "凤翅紫金冠：" << fang3n << "\n";
							cout << "金币：" << money << "\n";
							break;
						}
						else
						{
							cout << "装备数不够，无法出售！\n";
							break;
						}
						break;
					case 8:
						cout << "请问您要出售几件？\n";
						scanf("%d", &n);
						if (fang1n >= n)
						{
							fang4n = fang4n - n;
							money = money + n * 1500;
							cout << "锁子黄金甲：" << fang4n << "\n";
							cout << "金币：" << money << "\n";
							break;
						}
						else
						{
							cout << "装备数不够，无法出售！\n";
							break;
						}
					case 9:
						cout << "请问您要出售几颗？";
						scanf("%d", &n);
						if (KEY >= n)
						{
							KEY = KEY - n;
							money = money + n * 2000;
							cout << "胡萝卜：" << KEY << "\n";
							cout << "金币：" << money << "\n";
						}
						else
						{
							cout << "胡萝卜数量不够，无法出售！\n";
							break;
						}
						break;
					case 0:
						break;
						break;
					default:
						cout << "没有该装备，无法出售！\n";
						break;
					}

					break;
				case 5:
					int task;
					while (1)
					{
						cout << "=============================================================================\n";
						cout << "要去哪冒险呢？";
						cout << "\n\n 1,兔兔沙滩 危险程度：★\n\n 2,云隐兔山 危险程度：★★\n\n 3,迷兔之森  危险程度：★★★\n\n 4,兔梦桃源 危险程度：★★★★\n\n 5,兔仙古城 危险程度：★★★★★\n\n 6,龙兔禁地 危险程度：★★★★★★\n\n 0,离开\n";
						cout << "=============================================================================\n";
						task = getNum(0,6);
						switch (task)
						{
						case 1:
							place_sign = place.map1;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster1;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								Monster = Monster2;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else
							{
								cout << "这里安全\n\n\n";	//不用调用OAct函数,会自动执行OAct函数;
							}
							break;
						case 3:
							place_sign = place.map2;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster2;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								Monster = Monster4;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else
							{
								cout << "这里安全\n\n\n";
							}
							break;
						case 5:
							place_sign = place.map3;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster3;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								Monster = big_Monster3;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else
							{
								cout << "这里安全\n\n\n";
							}
							break;
						case 2:
							place_sign = place.map4;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster4;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								Monster = Monster5;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else
							{
								cout << "这里安全\n\n\n";
							}
							break;
						case 4:
							place_sign = place.map5;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster5;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								Monster = Monster6;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else
							{
								cout << "这里安全\n\n\n";
							}
							break;
						case 6:
							place_sign = place.map6;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster6;
								cout << Monster.name << "扑了过来!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								if (KEY)
								{
									cout << "神秘的兔子:\n\n\n 哈哈,年轻人,胡萝卜我要了！想要考试答案就跟我走吧!\n\n\n";
									Monster = BOSS;
									cout << Monster.name << "扑了过来!\n\n\n";
									BattleAct();
								}
								else cout << "神秘老人:\n\n\n 年轻人,你好啊.如果你有胡萝卜,我可以告诉你考试答案哦~\n\n\n";
							}
							else
							{
								cout << "这里安全\n\n\n";
							}
							break;
							if (task!= 0)
							{
								cout << "该区域为未知区域，无法进入。\n\n\n";
								break;
							}
						}
						if (task == 0)
						{
							break;
							cout << "已离开荒野。";
						}
					}
				}
				break;
			case 2:
				Chooseitem();
				break; //显示道具,并可以使用.
			case 3: //对话选项
				if (place_sign == place.ground)
				{
					cout << "和谁交谈呢?\n\n\n1,小姐姐  2,小哥哥  3,小兔子  4,小兔崽子\n\n\n"; //显示对话人物
					switch (choose_number = getNum(1,4), choose_number)
					{
					case 1:
						cout << "小姐姐:\n\n\n Super idol 的笑容，都没你的甜！\n\n\n八月正午的阳光，都没你耀眼!\n\n\n";
						break;
					case 2:
						if (fang1n < 1 && gong1n < 1)
						{
							cout << "小哥哥:\n\n\n 你要答案啊!好胆量!\n\n\n 不过外面的世界很险恶,这是胡萝卜根和胡萝卜叶,对你会有帮助的,拿去吧!\n\n\n";
							gong1n++;
							fang1n++;
						}
						else cout << "小哥哥:\n\n\n 加油吧,兔叽万岁!\n\n\n 不要被外面世界所吓倒!\n\n\n";
						break;
					case 3:
						cout << "要吃点什么嘛（……可爱……）?\n\n\n 1,红萝卜50金币 HP+20  2,紫萝卜100金币 HP+50  3,花心大萝卜200金币 HP+100  0,返回\n\n\n";
						choose_number = 1;
						while (choose_number)
						{
							switch (choose_number = getNum(0, 3), choose_number)
							{
							case 1:
								if (money < 50)
								{
									cout << "钱不够!";
								}
								else
								{
									if (player.hp + 20 <= player.max_hp)
									{
										cout << "HP+20.";
										money -= 50;
										player.hp += 20;
									}
									else
									{
										cout << "HP满了";
										player.hp = player.max_hp;
									}
								}
								break;
							case 2:
								if (money < 100)
								{
									cout << "钱不够!";
								}
								else
								{
									if (player.hp + 50 <= player.max_hp)
									{
										cout << "HP+50.";
										money -= 100;
										player.hp += 50;
									}
									else
									{
										cout << "HP满了";
										player.hp = player.max_hp;
									}
								}
								break;
							case 3:
								if (money < 200)
								{
									cout << "钱不够!";
								}
								else
								{
									if (player.hp + 100 <= player.max_hp)
									{
										cout << "HP+100.";
										money -= 200;
										player.hp += 100;
									}
									else
									{
										cout << "HP满了";
										player.hp = player.max_hp;
									}
								}
								break;
							case 0:
								cout << "下次再来!\n";
								break;
							default:
								cout << "输入错误\n\n\n";
								break;
							}
							break;
						}
						break;
					case 4:
						cout << "您要干什么呢？\n\n\n 1，buying  2，chatting \n\n\n";
						int p;
						p = getNum(1, 2);
						if (p == 1)
						{
							cout << "您要买什么呢？\n 1, 小药瓶￥100 HP+60\n 2，中药瓶￥150 HP+80\n 3，大药瓶￥250 HP+120\n 4，圣药￥400 HP+200 \n 5，小经验石￥150 经验+300 \n 6，中经验石￥600 经验+600\n 7，大经验石￥500 经验+1000 \n 0,欢迎您下次光临\n";
							int q;
							q = getNum(0, 7);
							switch (q)
							{
							case 1:
								if (money >= 100 && smedicine < 6)
								{
									smedicine++;
									money = money - 100;
									cout << "小药瓶+1\n";
								}
								else
								{
									cout << "钱不够!\n";
								}
								break;
							case 2:
								if (money >= 150 && mmedicine < 5)
								{
									mmedicine++;
									money = money - 150;
									cout << "中药瓶+1\n";
								}
								else
								{
									cout << "钱不够!\n";
								}
								break;
							case 3:
								if (money >= 250 && lmedicine < 4)
								{
									lmedicine++;
									money = money - 250;
									cout << "大药瓶+1\n";
								}
								else
								{
									cout << "钱不够!\n";
								}
								break;
							case 4:
								if (money >= 400 && Xlmedicine < 3)
								{
									Xlmedicine++;
									money = money - 400;
									cout << "圣药+1\n";
								}
								else
								{
									cout << "钱不够!\n";
								}
								break;
							case 5:
								if (money >= 150)
								{
									sstone++;
									money = money - 150;
									cout << "小经验石+1\n";
								}
								else
								{
									cout << "钱不够!\n";
								}
								break;
							case 6:
								if (money >= 300)
								{
									mstone++;
									money = money - 300;
									cout << "中经验石+1\n";
								}
								else
								{
									cout << "钱不够!\n";
								}
								break;
							case 7:
								if (money >= 500)
								{
									lstone++;
									money = money + 500;
									cout << "大经验石+1\n";
								}
								else
								{
									cout << "钱不够!\n";
								}
								break;
							}
					case 0:
						cout << "金币：" << money << "\n";
						cout << "再见，欢迎下次再来！\n";
						break;

						}
						if (p == 2)
						{
							cout << "小兔崽子：哼唧……哼唧……哼唧……。\n";
						}
					}
				}
				else if (place_sign == place.house)
					cout << "“老板!我...”\n\n\n“嘘~别说话！兔宝宝睡着啦！”\n\n\n";
				else cout << "这里好像没人可以聊天\n\n\n";
				break;
			case 4:
				DisplayState();
				break; //显示状态
			case 5: //装备
				cout << "攻击装备: 1,胡萝卜根:" << gong1n << "个 " << "2,名刀司命:" << gong2n << "个 " << "3,名刀月隐:" << gong3n << "个 " << "4,名剑轩辕:" << gong4n << "个\n\n\n";
				cout << "防御装备: 5,胡萝卜叶:" << fang1n << "个 " << "6,藕丝步云履:" << fang2n << "个 " << "7,凤翅紫金冠:" << fang3n << "个 "<< "8,锁子黄金甲:" << fang4n << "个\t\t0,返回\n\n\n";
				cout << "选择要装备的武器或防具:\n\n\n";
				switch (choose_number = getNum(0,8), choose_number)
				{
				case 1:
					if (gong1n >= 1)
					{
						cout << "拿起了胡萝卜根\n\n\n";
						gong = gong1;
						strcpy(gongname, "胡萝卜根");
					}
					else cout << "你没有胡萝卜根可以装备\n\n\n";
					break;
				case 2:
					if (gong2n >= 1)
					{
						cout << "拿起了名刀司命\n\n\n";
						gong = gong2;
						strcpy(gongname, "名刀司命");
					}
					else cout << "你没有名刀司命可以装备\n\n\n";
					break;
				case 3:
					if (gong3n >= 1)
					{
						cout << "拿起了名刀月隐\n\n\n";
						gong = gong3;
						strcpy(gongname, "名刀月隐");
					}
					else cout << "你没有名刀月隐可以装备\n\n\n";
					break;
				case 4:
					if (gong4n >= 1)
					{
						cout << "拿起了名剑轩辕\n\n\n";
						gong = gong4;
						strcpy(gongname, "名剑轩辕");
					}
					else cout << "你没有名剑轩辕可以装备\n\n\n";
					break;
				case 5:
					if (fang1n >= 1)
					{
						cout << "穿上了胡萝卜叶\n\n\n";
						fang = fang1;
						strcpy(fangname, "胡萝卜叶");
					}
					else cout << "你没有胡萝卜叶可以装备\n\n\n";
					break;
				case 6:
					if (fang2 >= 1)
					{
						cout << "穿上了藕丝步云履\n\n\n";
						fang = fang2;
						strcpy(fangname, "藕丝步云履");
					}
					else cout << "你没有藕丝步云履可以装备\n\n\n";
					break;
				case 7:
					if (fang3n >= 1)
					{
						cout << "穿上了凤翅紫金冠\n\n\n";
						fang = fang3;
						strcpy(fangname, "凤翅紫金冠");
					}
					else cout << "你没有凤翅紫金冠可以装备\n\n\n";
					break;
				case 8:
					if (fang4n >= 1)
					{
						cout << "穿上了锁子黄金甲\n\n\n";
						fang = fang4;
						strcpy(fangname, "锁子黄金甲");
					}
					else cout << "你没有锁子黄金甲可以装备\n\n\n";
					break;
				case 0:
					cout << "未更换装备\n\n\n";
					break;
				default:
					cout << "change error!";
				}
				break;
			case 6:
				cout << " 想知道外挂怎么开嘛，开启外挂的方式是设定勇者姓名时，输入 “包叽 ”或者 “兔叽 ”（不包括双引号）。\n";
				break;
			case 7:
				txt.open("C:\\Users\\qzx\\Desktop\\txt.txt",ios::in);
				if(!txt.is_open())
				{
					cout<<"文件打开失败"<<endl;
					return;
					}	
				while(txt>>out)
				{
					cout<<out<<endl;
					}
				txt.close();		
			case 0:
				cout << "确定退出游戏?[Y(y)/N(n)]\n\n\n";
				getchar();
				proof = getchar();
				if (proof == 'y' || proof == 'Y')
				{
					cout << "数据存储中...";
					getchar();
					cout << "按回车退出";
					getchar();
					return;
				}
				else if (proof == 'n' || proof == 'N')cout << "继续游戏!\n\n\n";
				else cout << "继续!\n\n\n";
				break;
			default:
				cout << "输入错误!\n\n\n";
			}
		}
	}
	void DisplayState()
	{
		cout << player.name << "攻击力: " << player.attack << " + " << gong << " = " << player.attack + gong
			<< " 防御力 : " << player.defense << " + " << fang << " = " << player.defense + fang
			<< " HP : " << player.hp << " / " << player.max_hp << " \n\n\n";
		cout << "武器: " << gongname << " 防具: " << fangname << " \n\n\n";
		cout << "等级:" << player.level << "经验: " << player.exp << " / " << player.max_exp << " 还需要 " << player.max_exp - player.exp << "经验升级 金币 : " << money << " \n\n\n";
	}
	void BattleAct()
	{
		while (1)
		{
			cout << "=============================================================================\n";
			cout << "此时你要?\n\n\n 1,普通攻击  2,使用物品  3,查看状态  4,逃跑\n\n\n";
			switch (choose_number = getNum(1,4), choose_number)
			{
			case 1:
				s = SuiJi();
				cout << player.name << "攻击! " << Monster.name << "HP减少" << player.attack + s + gong - Monster.defense / 3 << "\n\n\n";
				Monster.hp -= player.attack + s + gong - Monster.defense / 3;
				if (AttackResult())return; //如果攻击有结果(敌人或玩家战死)退出函数
				else continue;
			case 2:
				Chooseitem();
				break; //选择物品,可以使用,战斗中允许使用攻击性物品
			case 3:
				DisplayState();
				break; //显示状态
			case 4:
				s = SuiJi();
				if (s < 4) //40%的概率可以逃跑
				{
					cout << player.name << "逃跑了~\n\n\n";
					battle = 0;
					return;
				}
				else cout << player.name << "逃跑失败!\n\n\n";
				break;
			default:
				cout << "输入错误,重新输入!\n\n\n";
			}
		}
	}
	
};

int Game::fang4n = 0;
int Game::fang3n = 0;
int Game::fang2n = 0;
int Game::gong4n = 0;
int Game::gong3n = 0;
int Game::gong2n = 0;
int Game::fang1n = 0;
int Game::gong1n = 0;

