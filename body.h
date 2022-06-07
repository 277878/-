//��Ϸ����Ҫ����ѡ�� 
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
					throw "���ݳ�����Ϸ��������";
					return -1;
				}
				else
				{
					cout<<"���������롣"<<endl;
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
	Game():Monster3("������", "���ӻƽ��", 40, 50, 350, 200, 100, 1, 2, 1, 0),
		   Monster2("С����", "����Ͻ��", 25, 15, 100, 50, 50, 2, 2, 1, 1),
		   Monster1("СҰ��", "ź˿������", 18, 10, 50, 30, 35, 3, 3, 2, 2),
		   big_Monster3("��������", "���ܲ�", 40 * 5, 50 * 5, 200 * 5, 200 * 5, 100 * 5, 4, 4, 2, 0),
		   Monster6("������", "������ԯ", 60, 30, 280, 200, 100, 5, 2, 1, 0),
		   Monster5("С����", "��������", 28, 12, 90, 50, 50, 6, 2, 1, 1),
		   Monster4("С����", "����˾��", 17, 11, 60, 30, 35, 7, 3, 2, 2),
		   BOSS("�������ɵ�Ц��������", "\0", 50 * 8, 50 * 8, 300 * 8, 300 * 8, 300 * 8, 9, 1, 1, 0),
		   Monster("\0", "\0", 0, 0, 0, 0, 0, 0, 0, 0, 0), //��ʼ�� 
		   player("���", 40, 40, 100, 100, 1, 0, 0, 100),
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
		cout << "--------------------------��ӭ�����������ˣ����Ʒ���Ա���ߴ�Ƭ���ˡ�����������-----------------------\n\n\n";
		//�����ʹ����ң����������룺����ߴ ����
		//����������Ѿ������������룺����ߴ ���� 
		Sleep(1000);
		cout << "��ǰ����ɽ��ɽ���и��ã�����˵��������˵��лл�㡭����\n\n\nΰ�����Ұ�~�������ǵ�����,�ɵ�ͳ������������������ķ�������Ц�������Ӱɣ�\n\n\n�������������: (20���ַ�)\n\n\n";
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
				throw "�ַ����������";
				break;
			}
			player_name[i++] = ch;
		}
		strncpy(player.name, player_name, 20);
		if (strcmp(player.name, "��ߴ") == 0)
		{
			cout << "\n\n\n��ӡ����İ�ߴѪͳ��!\n\n\n�����ھ�����!\n\n\n��ߴ�����Ϊ����ѡ֮���������ҵ��𰸰ɣ�\n\n\n";
			player.attack = 9999;
			player.defense = 9999;
			player.hp = 9999;
			player.max_hp = 99999;
		}
		if (strcmp(player.name, "��ߴ") == 0)
		{
			cout << "\n\n\n��ӡ�������ߴѪͳ��!\n\n\n�����ھ�����!\n\n\n��ߴ�����Ϊ�˴�ɵ֮�ã������ҵ��𰸰ɣ�\n\n\n";
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
		cout << "��Ʒ: 1,Сҩƿ" << smedicine << "�� " << "2, ��ҩƿ" << mmedicine << "��" << "3, ��ҩƿ" << lmedicine << "�� " << "4, ʥҩ" << Xlmedicine << "�� " << "5, ����" << sboom << "�� " << "6, ����" << mboom << "�� " << "7, �˱�" << lboom << "�� " << "8, С����ʯ" << sstone << "�� "<< "9, �о���ʯ" << mstone << "�� " << "10, ����ʯ" << lstone << "�� " << "11, ���ܲ�" << KEY << "�� " << "0, ����\n\n\n";
		switch (choose_number = getNum(0,11), choose_number)
		{
		case 1:
			if (smedicine > 0)
			{
				cout << "ʹ��Сҩƿ,HP����60\n\n\n";
				smedicine--;
				if (player.hp + 60 > player.max_hp)player.hp = player.max_hp;
				else player.hp += 60;
			}
			else cout << "û��Сҩƿ��\n\n\n";
			break;
		case 2:
			if (mmedicine > 0)
			{
				cout << "ʹ����ҩƿ,HP����80\n\n\n";
				mmedicine--;
				if (player.hp + 80 > player.max_hp)player.hp = player.max_hp;
				else player.hp += 80;
			}
			else cout << "û����ҩƿ��\n\n\n";
			break;
		case 3:
			if (lmedicine > 0)
			{
				cout << "ʹ�ô�ҩƿ,HP����120\nz\n\n";
				lmedicine--;
				if (player.hp + 120 > player.max_hp)player.hp = player.max_hp;
				else player.hp += 120;
			}
			else cout << "û�д�ҩƿ��\n\n\n";
			break;
		case 4:
			if (Xlmedicine > 0)
			{
				cout << "ʹ��ʥҩ,HP����200\n\n\n";
				Xlmedicine--;
				if (player.hp + 200 > player.max_hp)player.hp = player.max_hp;
				else player.hp += 200;
			}
			else cout << "û��ʥҩ��\n\n\n";
			break;
		case 5:
			if (battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
			{
				if (sboom > 0)
				{
					cout << "ʹ������,����HP����100\n\n\n";
					sboom--;
					Monster.hp -= 100;
					AttackResult();
				}
			}
			else cout << "��ս��״̬,����ʹ������!\n\n\n";
			break;
		case 6:
			if (battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
			{
				if (mboom > 0)
				{
					cout << "ʹ�õ���,����HP����200\n\n\n";
					mboom--;
					Monster.hp -= 200;
					AttackResult();
				}
			}
			else cout << "��ս��״̬,����ʹ�õ���!\n\n\n";
			break;
		case 7:
			if (battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
			{
				if (lboom > 0)
				{
					cout << "ʹ�ú˱�,����HP����666666666\n\n\n";
					lboom--;
					Monster.hp -= 666666666;
					AttackResult();
				}
			}
			else cout << "��ս��״̬,����ʹ�ú˱�!\n\n\n";
			break;
		case 8:
			if (sstone > 0 && player.level < 1000)
			{

				cout << "ʹ��С����ʯ,�ȼ�����10��\n\n\n";
				sstone--;
				player.level += 10;
				cout << "�ȼ���" << player.level << "\n";
			}
			else    if (sstone < 1)
			{
				cout << "û��С����ʯ��\n\n\n";
			}
			else cout << "�ȼ�����45��,��Ϊ̫�ߣ��޷�ʹ�á�\n\n\n";
			break;
		case 9:
			if (mstone > 0 && player.level < 1000)
			{
				if (player.level > 44 && player.level < 1000)
				{
					int sheng;
					sheng = 45 - player.level;
					player.level += sheng;
					cout << "ʹ���о���ʯ,�ȼ�����" << sheng << "��";
					cout << "�ȼ���" << player.level << "\n";
				}
				else
				{

					cout << "ʹ���о���ʯ,�ȼ�����2��\n\n\n";
					mstone--;
					player.level += 2;
					cout << "�ȼ���" << player.level << "\n";
				}
			}
			else if (mstone < 1)
			{
				cout << "û���о���ʯ��";
			}
			else cout << "�ȼ�����45��,��Ϊ̫�ߣ��޷�ʹ�á�\n\n\n";
			break;
		case 10:
			if (lstone > 0 && player.level < 1000)
			{
				if (player.level > 42 && player.level < 1000)
				{
					int sheng;
					sheng = 45 - player.level;
					player.level += sheng;
					cout << "ʹ�ô���ʯ,�ȼ�����" << sheng << "��\n";
					cout << "�ȼ���" << player.level << "\n";
				}
				else
				{
					cout << "ʹ�ô���ʯ,�ȼ�����10��\n";
					lstone--;
					player.level += 10;
				}
			}
			else if (lstone < 1)
			{
				cout << "û�д���ʯ��\n\n\n";
			}
			else cout << "�ȼ�����45��,��Ϊ̫�ߣ��޷�ʹ�á�\n\n\n";
			break;
		case 11:
			if (KEY > 0 && player.level < 10000)
			{
				if (player.level > 29 && player.level < 10000)
				{
					int sheng;
					sheng = 45 - player.level;
					player.level += sheng;
					cout << "ʹ�ú��ܲ�,�ȼ�����" << sheng << "��";
					cout << "�ȼ���" << player.level << "\n";
				}
				else
				{
					cout << "ʹ�ú��ܲ�,�ȼ�����16��\n\n\n";
					KEY--;
					player.level += 16;
					cout << "�ȼ���" << player.level << "\n";
				}
			}
			else if (KEY < 1)
			{
				cout << "û�к��ܲ��ˡ�\n\n\n";
			}
			else cout << "�ȼ�����45��,��Ϊ̫�ߣ��޷�ʹ�á�\n\n\n";
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
			cout << "ս��ʤ��!��ý��" << Monster.money << ",����" << Monster.exp << "\n\n\n";
			player.exp += Monster.exp;
			player.range_exp += Monster.exp;
			money += Monster.money;
			*s = SuiJi();
			if (*s < Monster.itempro)
			{
				cout << "�ӵ���ʬ���з���";
				cout << Monster.item << "\n\n\n";
				Additem(Monster.item_sign);
			}
			WhetherLevelUp();
			if (strcmp(Monster.name, "�������ɵ�Ц��������") == 0)
			{
				cout << "ս��ʤ�����ҵ��𰸣�����";
				getchar();
				getchar();
				exit(0);
			}
			delete s;
			return 1; //�����н���˷���1,���򷵻�0,�����ж��Ƿ������ս����Ϊ
		}
		else 
		{
			int s = SuiJi();

			if ((Monster.attack + s - player.defense / 3) < 0)
			{
				player.hp -= 1;
				cout << Monster.name << "����,���HP������ 1\n\n";
			}
			else
			{
				player.hp -= Monster.attack + s - player.defense / 3;
				cout << Monster.name << "����,���HP������" << Monster.attack + s - player.defense / 3 << "\n\n";
			}
			if (player.hp < 0)
			{
				battle = 0;
				cout << player.name << "ս��!��ҵ���" << player.level * 2000 << "  ��Ѫ����!" << "\n\n\n";
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
		if (player.level <= 15 && l1 > 0) //15������,�����㹻 ������������
		{
			if (l1 == 1)
			{
				cout << player.name;
				cout << " ����!\n\n\n������+3, ������+2, HP����+20\n\n\n";
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
				cout << "������!����11��!";
				cout << "������+" << 3 * l1 << ", ������ + " << 2 * l1 << ", HP���� + " << 20 * l1 << "\n\n\n";
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
				cout << " ����!\n\n\n������+3, ������+2, HP����+20\n\n\n";
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
				cout << "������!����l1��!";
				cout << "������+36, ������+24, HP����+240\n\n\n";
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
				cout << " ����!\n\n\n������+3, ������+2, HP����+20\n\n\n";
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
				cout << "������!����l1��!";
				cout << "������+" << 3 * l3 << ", ������+" << 2 * l3 << ", HP����+" << 20 * l3 << "\n\n\n";
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
			cout << " Ҫ��ʲô?\n\n\n 1,�ƶ�  2,����  3,�Ի�  4,�鿴״̬  5,װ��  6,������Ϸ  7,�鿴˵�� 0,�˳���Ϸ\n\n\n";
			cout << "===================================================================================================================" << endl;
			switch (choose_number = getNum(0, 7), choose_number)
			{
			case 1: //��ʾ�ƶ��˵�
				cout << "Ҫȥ����?\n\n\n";
				cout << " 1,�ܲ��㳡  2,�ܲ�С��  3,�ܲ��̵�  4���ܲ�����  5������ð�� \n\n\n";
				switch (choose_number = getNum(1, 5), choose_number)
				{
				case 1:
					place_sign = place.ground; //��¼Ŀǰλ��-�ư�
					// OrdinaryAct();
					break;
				case 2:
					place_sign = place.house; //�����õ�
					cout << "��ң�" << money;
					cout << "Ҫ��Ϣ��? 200����� 1,�� 0,��\n\n\n";
					choose_number = 1;
					switch (choose_number = getNum(0, 1), choose_number)
					{
					case 1:
						if (money - 200 < 0) //�ж�Ǯ�Ƿ�
						{
							cout << "Sorry,���Ǯ����~\n\n\n";
							cout << "��ң�" << money;
						}
						else
						{
							cout << "�ú���Ϣ\n���HP����\n���ڶ�����\n\n";
							cout << "���: " << money << "\n";
							money -= 200; //����200ס���
							player.hp = player.max_hp; //������
						}
						break;
					case 0:
						cout << "�´�����!\n\n\n";
						break;
					default:
						cout << "house talk error!\n\n\n";
					}
					place_sign = 0;
					break;
				case 3:
					int yongju;
					cout << "��Ҫ����ʲô��Ʒ��\n\n\n 1,����װ��  2������װ��  3,һ��������\n\n\n";
					yongju = getNum(1, 3);
					switch (yongju)
					{
					case 1:
						int gong; 
						cout << "��Ҫ����ʲô����?\n\n\n 1,���ܲ�����500  2������˾����1000  3������������2000\n\n\n";
						gong = getNum(1, 3);
						switch (gong)
						{
						case 1:
							if (money >= 500)
							{
								gong1n++;
								money = money - 500;
								cout << "���ܲ���+1\n";
								cout << "���ܲ���:" << gong1n << "��\n";
								cout << "��ң�" << money << "\n";
								break;
							}
							else
							{
								cout << "Ǯ����!\n";
								cout << "��ң�" << money << "\n";
								break;
							}
						case 2:
							if (money >= 1000)
							{
								gong2n++;
								money = money - 1000;
								cout << "����˾��+1\n";
								cout << "����˾��:" << gong2n << "��\n";
								cout << "��ң�" << money << "\n";
								break;
							}
							else
							{
								cout << "Ǯ����!\n";
								cout << "��ң�" << money << "\n";
								break;
							}
						case 3:
							if (money >= 2000)
							{
								gong3n++;
								money = money - 2000;
								cout << "��������+1\n";
								cout << "��������:" << gong3n << "��\n";
								cout << "��ң�" << money << "\n";
								break;
							}
							else
							{
								cout << "Ǯ����!\n";
								cout << "��ң�" << money << "\n";
								break;
							}
						default:
							cout << "�Բ�������ֻ���������������";
							break;
						}
						break;
					case 2:
						int fang;
						cout << "������Ҫ����ʲô����?\n\n\n 1,���ܲ�Ҷ��500  2��ź˿�����ģ�1000  3������Ͻ�ڣ�2000\n\n\n";
						fang = getNum(1, 3);
						switch (fang)
						{
						case 1:
							if (money >= 500)
							{
								fang1n++;
								money = money - 500;
								cout << "���ܲ�Ҷ+1\n";
								cout << "���ܲ�Ҷ:" << fang1n << "��\n";
								cout << "��ң�" << money << "\n";
							}
							else
							{
								cout << "Ǯ����!\n";
								cout << "��ң�" << money << "\n";
							}

							break;
						case 2:
							if (money >= 1000)
							{
								fang2n++;
								money = money - 1000;
								cout << "ź˿������+1\n";
								cout << "ź˿������:" << fang2n << "��\n";
								cout << "��ң�" << money << "\n";
							}
							else
							{
								cout << "Ǯ����!\n";
								cout << "��ң�" << money << "\n";
							}
							break;
						case 3:
							if (money >= 2000)
							{
								fang3n++;
								money = money - 2000;
								cout << "����Ͻ��+1\n";
								cout << "����Ͻ��:" << fang3n << "��\n";
								cout << "��ң�" << money << "\n";
							}
							else
							{
								cout << "Ǯ����!\n";
								cout << "��ң�" << money << "\n";
							}
						default:
							cout << "�Բ�������ֻ��������Ϸ��ߡ�";
							break;
						}
						cout << "��ң�" << money << "\n";
						break;
					case 3:
						cout << "������Ҫ����ʲôһ�����˺�������\n 1,���ף�1000  2��������2000  3���˱���5000\n\n\n";
						int o;
						o = getNum(1, 3);
						switch (o)
						{
						case 1:
							if (money >= 1000 && sboom < 5)
							{
								sboom++;
								money = money - 1000;
								cout << "���� +1\n";
								cout << "���ף�" << sboom << "\n";
								cout << "��ң�" << money << "\n";
							}
							else
							{
								cout << "Ǯ����!\n";
								cout << "��ң�" << money << "\n";
							}
							break;
						case 2:
							if (money >= 2000 && mboom < 4)
							{
								mboom++;
								money = money - 2000;
								cout << "���� +1\n";
								cout << "������" << mboom << "\n";
								cout << "��ң�" << money << "\n";
							}
							else
							{
								cout << "Ǯ����!\n";
								cout << "��ң�" << money << "\n";
							}
							break;
						case 3:
							if (money >= 5000 && lboom < 2)
							{
								lboom = lboom + 1;
								money = money - 5000;
								cout << "�˱� +2\n";
								cout << "�˱���" << lboom << "\n";
								cout << "��ң�" << money << "\n";
							}
							else
							{
								cout << "Ǯ����!\n\n\n";
								cout << "��ң�" << money << "\n";
							}
							break;
						}
					}
					break;
				case 4:
					cout << "��ӭ�����ٱ����У�������Ҫ��ʲô������\n\n";
					cout << "����װ��: 1,���ܲ���:" << gong1n << "�� " << "2,����˾����" << gong2n << "�� " << "3,��������:" << gong3n << "�� " << "4,������ԯ:" << gong4n << "��\n";
					cout << "����װ��: 5,���ܲ�Ҷ:" << fang1n << "�� " << "6,ź˿������:" << fang2n << "�� " << "7,����Ͻ��:" << fang3n << "�� " << "8,���ӻƽ��:" << fang4n << "��\n" << "9�����ܲ�:" << KEY << "�� " << "0,����\n\n\n";
					int m, n, i;
					m = getNum(0, 9);
					switch (m)
					{
					case 1:
						cout << "������Ҫ���ۼ�����";
						scanf("%d", &n);
						if (gong1n >= n)
						{
							gong1n = gong1n - n;
							money = money + n * 240;
							cout << "���ܲ�����" << gong1n << "\n";
							cout << "��ң�" << money << "\n";
							break;
						}
						else
						{
							cout << "װ�����������޷����ۣ�\n";
							break;
						}
						break;
					case 2:
						cout << "������Ҫ���ۼ�����\n";
						scanf("%d", &n);
						if (gong2n >= n)
						{
							gong2n = gong2n - n;
							money = money + n * 400;
							cout << "����˾����" << gong2n << "\n";
							cout << "��ң�" << money << "\n";
							break;
						}
						else
						{
							cout << "װ�����������޷����ۣ�\n";
							break;
						}
					case 3:
						cout << "������Ҫ���ۼ�����\n";
						scanf("%d", &n);
						if (gong3n >= n)
						{
							gong3n = gong3n - n;
							money = money + n * 800;
							cout << "����������" << gong3n << "\n";
							cout << "��ң�" << money << "\n";
							break;
						}
						else
						{
							cout << "װ�����������޷����ۣ�\n";
							break;
						}
					case 4:
						cout << "������Ҫ���ۼ�����\n";
						scanf("%d", &n);
						if (gong4n >= n)
						{
							gong4n = gong4n - n;
							money = money + n * 1500;
							cout << "������ԯ��" << gong4n << "\n";
							cout << "��ң�" << money << "\n";
							break;
						}
						else
						{
							cout << "װ�����������޷����ۣ�\n";
							break;
						}
					case 5:
						cout << "������Ҫ���ۼ�����\n";
						scanf("%d", &n);
						if (fang1n >= n)
						{
							fang1n = fang1n - n;
							money = money + n * 240;
							cout << "���ܲ�Ҷ��" << fang1n << "\n";
							cout << "��ң�" << money << "\n";
							break;
						}
						else
						{
							cout << "װ�����������޷����ۣ�\n";
							break;
						}
					case 6:
						cout << "������Ҫ���ۼ�����\n";
						scanf("%d", &n);
						if (fang2n >= n)
						{
							fang2n = fang2n - n;
							money = money + n * 500;
							cout << "ź˿�����ģ�" << fang2n << "\n";
							cout << "��ң�" << money << "\n";
							break;
						}
						else
						{
							cout << "װ�����������޷����ۣ�\n";
							break;
						}
					case 7:
						cout << "������Ҫ���ۼ�����\n";
						scanf("%d", &n);
						if (fang3n >= n)
						{
							fang3n = fang3n - n;
							money = money + n * 800;
							cout << "����Ͻ�ڣ�" << fang3n << "\n";
							cout << "��ң�" << money << "\n";
							break;
						}
						else
						{
							cout << "װ�����������޷����ۣ�\n";
							break;
						}
						break;
					case 8:
						cout << "������Ҫ���ۼ�����\n";
						scanf("%d", &n);
						if (fang1n >= n)
						{
							fang4n = fang4n - n;
							money = money + n * 1500;
							cout << "���ӻƽ�ף�" << fang4n << "\n";
							cout << "��ң�" << money << "\n";
							break;
						}
						else
						{
							cout << "װ�����������޷����ۣ�\n";
							break;
						}
					case 9:
						cout << "������Ҫ���ۼ��ţ�";
						scanf("%d", &n);
						if (KEY >= n)
						{
							KEY = KEY - n;
							money = money + n * 2000;
							cout << "���ܲ���" << KEY << "\n";
							cout << "��ң�" << money << "\n";
						}
						else
						{
							cout << "���ܲ������������޷����ۣ�\n";
							break;
						}
						break;
					case 0:
						break;
						break;
					default:
						cout << "û�и�װ�����޷����ۣ�\n";
						break;
					}

					break;
				case 5:
					int task;
					while (1)
					{
						cout << "=============================================================================\n";
						cout << "Ҫȥ��ð���أ�";
						cout << "\n\n 1,����ɳ̲ Σ�ճ̶ȣ���\n\n 2,������ɽ Σ�ճ̶ȣ����\n\n 3,����֮ɭ  Σ�ճ̶ȣ�����\n\n 4,������Դ Σ�ճ̶ȣ������\n\n 5,���ɹų� Σ�ճ̶ȣ�������\n\n 6,���ý��� Σ�ճ̶ȣ��������\n\n 0,�뿪\n";
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
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								Monster = Monster2;
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else
							{
								cout << "���ﰲȫ\n\n\n";	//���õ���OAct����,���Զ�ִ��OAct����;
							}
							break;
						case 3:
							place_sign = place.map2;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster2;
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								Monster = Monster4;
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else
							{
								cout << "���ﰲȫ\n\n\n";
							}
							break;
						case 5:
							place_sign = place.map3;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster3;
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								Monster = big_Monster3;
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else
							{
								cout << "���ﰲȫ\n\n\n";
							}
							break;
						case 2:
							place_sign = place.map4;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster4;
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								Monster = Monster5;
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else
							{
								cout << "���ﰲȫ\n\n\n";
							}
							break;
						case 4:
							place_sign = place.map5;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster5;
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								Monster = Monster6;
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else
							{
								cout << "���ﰲȫ\n\n\n";
							}
							break;
						case 6:
							place_sign = place.map6;
							s = SuiJi();
							if (s < 7)
							{
								battle = 1;
								Monster = Monster6;
								cout << Monster.name << "���˹���!\n\n\n";
								BattleAct();
							}
							else if (s < 9)
							{
								battle = 1;
								if (KEY)
								{
									cout << "���ص�����:\n\n\n ����,������,���ܲ���Ҫ�ˣ���Ҫ���Դ𰸾͸����߰�!\n\n\n";
									Monster = BOSS;
									cout << Monster.name << "���˹���!\n\n\n";
									BattleAct();
								}
								else cout << "��������:\n\n\n ������,��ð�.������к��ܲ�,�ҿ��Ը����㿼�Դ�Ŷ~\n\n\n";
							}
							else
							{
								cout << "���ﰲȫ\n\n\n";
							}
							break;
							if (task!= 0)
							{
								cout << "������Ϊδ֪�����޷����롣\n\n\n";
								break;
							}
						}
						if (task == 0)
						{
							break;
							cout << "���뿪��Ұ��";
						}
					}
				}
				break;
			case 2:
				Chooseitem();
				break; //��ʾ����,������ʹ��.
			case 3: //�Ի�ѡ��
				if (place_sign == place.ground)
				{
					cout << "��˭��̸��?\n\n\n1,С���  2,С���  3,С����  4,С������\n\n\n"; //��ʾ�Ի�����
					switch (choose_number = getNum(1,4), choose_number)
					{
					case 1:
						cout << "С���:\n\n\n Super idol ��Ц�ݣ���û�����\n\n\n������������⣬��û��ҫ��!\n\n\n";
						break;
					case 2:
						if (fang1n < 1 && gong1n < 1)
						{
							cout << "С���:\n\n\n ��Ҫ�𰸰�!�õ���!\n\n\n ���������������ն�,���Ǻ��ܲ����ͺ��ܲ�Ҷ,������а�����,��ȥ��!\n\n\n";
							gong1n++;
							fang1n++;
						}
						else cout << "С���:\n\n\n ���Ͱ�,��ߴ����!\n\n\n ��Ҫ�������������ŵ�!\n\n\n";
						break;
					case 3:
						cout << "Ҫ�Ե�ʲô������ɰ�������?\n\n\n 1,���ܲ�50��� HP+20  2,���ܲ�100��� HP+50  3,���Ĵ��ܲ�200��� HP+100  0,����\n\n\n";
						choose_number = 1;
						while (choose_number)
						{
							switch (choose_number = getNum(0, 3), choose_number)
							{
							case 1:
								if (money < 50)
								{
									cout << "Ǯ����!";
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
										cout << "HP����";
										player.hp = player.max_hp;
									}
								}
								break;
							case 2:
								if (money < 100)
								{
									cout << "Ǯ����!";
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
										cout << "HP����";
										player.hp = player.max_hp;
									}
								}
								break;
							case 3:
								if (money < 200)
								{
									cout << "Ǯ����!";
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
										cout << "HP����";
										player.hp = player.max_hp;
									}
								}
								break;
							case 0:
								cout << "�´�����!\n";
								break;
							default:
								cout << "�������\n\n\n";
								break;
							}
							break;
						}
						break;
					case 4:
						cout << "��Ҫ��ʲô�أ�\n\n\n 1��buying  2��chatting \n\n\n";
						int p;
						p = getNum(1, 2);
						if (p == 1)
						{
							cout << "��Ҫ��ʲô�أ�\n 1, Сҩƿ��100 HP+60\n 2����ҩƿ��150 HP+80\n 3����ҩƿ��250 HP+120\n 4��ʥҩ��400 HP+200 \n 5��С����ʯ��150 ����+300 \n 6���о���ʯ��600 ����+600\n 7������ʯ��500 ����+1000 \n 0,��ӭ���´ι���\n";
							int q;
							q = getNum(0, 7);
							switch (q)
							{
							case 1:
								if (money >= 100 && smedicine < 6)
								{
									smedicine++;
									money = money - 100;
									cout << "Сҩƿ+1\n";
								}
								else
								{
									cout << "Ǯ����!\n";
								}
								break;
							case 2:
								if (money >= 150 && mmedicine < 5)
								{
									mmedicine++;
									money = money - 150;
									cout << "��ҩƿ+1\n";
								}
								else
								{
									cout << "Ǯ����!\n";
								}
								break;
							case 3:
								if (money >= 250 && lmedicine < 4)
								{
									lmedicine++;
									money = money - 250;
									cout << "��ҩƿ+1\n";
								}
								else
								{
									cout << "Ǯ����!\n";
								}
								break;
							case 4:
								if (money >= 400 && Xlmedicine < 3)
								{
									Xlmedicine++;
									money = money - 400;
									cout << "ʥҩ+1\n";
								}
								else
								{
									cout << "Ǯ����!\n";
								}
								break;
							case 5:
								if (money >= 150)
								{
									sstone++;
									money = money - 150;
									cout << "С����ʯ+1\n";
								}
								else
								{
									cout << "Ǯ����!\n";
								}
								break;
							case 6:
								if (money >= 300)
								{
									mstone++;
									money = money - 300;
									cout << "�о���ʯ+1\n";
								}
								else
								{
									cout << "Ǯ����!\n";
								}
								break;
							case 7:
								if (money >= 500)
								{
									lstone++;
									money = money + 500;
									cout << "����ʯ+1\n";
								}
								else
								{
									cout << "Ǯ����!\n";
								}
								break;
							}
					case 0:
						cout << "��ң�" << money << "\n";
						cout << "�ټ�����ӭ�´�������\n";
						break;

						}
						if (p == 2)
						{
							cout << "С�����ӣ����󡭡����󡭡����󡭡���\n";
						}
					}
				}
				else if (place_sign == place.house)
					cout << "���ϰ�!��...��\n\n\n����~��˵�����ñ���˯��������\n\n\n";
				else cout << "�������û�˿�������\n\n\n";
				break;
			case 4:
				DisplayState();
				break; //��ʾ״̬
			case 5: //װ��
				cout << "����װ��: 1,���ܲ���:" << gong1n << "�� " << "2,����˾��:" << gong2n << "�� " << "3,��������:" << gong3n << "�� " << "4,������ԯ:" << gong4n << "��\n\n\n";
				cout << "����װ��: 5,���ܲ�Ҷ:" << fang1n << "�� " << "6,ź˿������:" << fang2n << "�� " << "7,����Ͻ��:" << fang3n << "�� "<< "8,���ӻƽ��:" << fang4n << "��\t\t0,����\n\n\n";
				cout << "ѡ��Ҫװ�������������:\n\n\n";
				switch (choose_number = getNum(0,8), choose_number)
				{
				case 1:
					if (gong1n >= 1)
					{
						cout << "�����˺��ܲ���\n\n\n";
						gong = gong1;
						strcpy(gongname, "���ܲ���");
					}
					else cout << "��û�к��ܲ�������װ��\n\n\n";
					break;
				case 2:
					if (gong2n >= 1)
					{
						cout << "����������˾��\n\n\n";
						gong = gong2;
						strcpy(gongname, "����˾��");
					}
					else cout << "��û������˾������װ��\n\n\n";
					break;
				case 3:
					if (gong3n >= 1)
					{
						cout << "��������������\n\n\n";
						gong = gong3;
						strcpy(gongname, "��������");
					}
					else cout << "��û��������������װ��\n\n\n";
					break;
				case 4:
					if (gong4n >= 1)
					{
						cout << "������������ԯ\n\n\n";
						gong = gong4;
						strcpy(gongname, "������ԯ");
					}
					else cout << "��û��������ԯ����װ��\n\n\n";
					break;
				case 5:
					if (fang1n >= 1)
					{
						cout << "�����˺��ܲ�Ҷ\n\n\n";
						fang = fang1;
						strcpy(fangname, "���ܲ�Ҷ");
					}
					else cout << "��û�к��ܲ�Ҷ����װ��\n\n\n";
					break;
				case 6:
					if (fang2 >= 1)
					{
						cout << "������ź˿������\n\n\n";
						fang = fang2;
						strcpy(fangname, "ź˿������");
					}
					else cout << "��û��ź˿�����Ŀ���װ��\n\n\n";
					break;
				case 7:
					if (fang3n >= 1)
					{
						cout << "�����˷���Ͻ��\n\n\n";
						fang = fang3;
						strcpy(fangname, "����Ͻ��");
					}
					else cout << "��û�з���Ͻ�ڿ���װ��\n\n\n";
					break;
				case 8:
					if (fang4n >= 1)
					{
						cout << "���������ӻƽ��\n\n\n";
						fang = fang4;
						strcpy(fangname, "���ӻƽ��");
					}
					else cout << "��û�����ӻƽ�׿���װ��\n\n\n";
					break;
				case 0:
					cout << "δ����װ��\n\n\n";
					break;
				default:
					cout << "change error!";
				}
				break;
			case 6:
				cout << " ��֪�������ô���������ҵķ�ʽ���趨��������ʱ������ ����ߴ ������ ����ߴ ����������˫���ţ���\n";
				break;
			case 7:
				txt.open("C:\\Users\\qzx\\Desktop\\txt.txt",ios::in);
				if(!txt.is_open())
				{
					cout<<"�ļ���ʧ��"<<endl;
					return;
					}	
				while(txt>>out)
				{
					cout<<out<<endl;
					}
				txt.close();		
			case 0:
				cout << "ȷ���˳���Ϸ?[Y(y)/N(n)]\n\n\n";
				getchar();
				proof = getchar();
				if (proof == 'y' || proof == 'Y')
				{
					cout << "���ݴ洢��...";
					getchar();
					cout << "���س��˳�";
					getchar();
					return;
				}
				else if (proof == 'n' || proof == 'N')cout << "������Ϸ!\n\n\n";
				else cout << "����!\n\n\n";
				break;
			default:
				cout << "�������!\n\n\n";
			}
		}
	}
	void DisplayState()
	{
		cout << player.name << "������: " << player.attack << " + " << gong << " = " << player.attack + gong
			<< " ������ : " << player.defense << " + " << fang << " = " << player.defense + fang
			<< " HP : " << player.hp << " / " << player.max_hp << " \n\n\n";
		cout << "����: " << gongname << " ����: " << fangname << " \n\n\n";
		cout << "�ȼ�:" << player.level << "����: " << player.exp << " / " << player.max_exp << " ����Ҫ " << player.max_exp - player.exp << "�������� ��� : " << money << " \n\n\n";
	}
	void BattleAct()
	{
		while (1)
		{
			cout << "=============================================================================\n";
			cout << "��ʱ��Ҫ?\n\n\n 1,��ͨ����  2,ʹ����Ʒ  3,�鿴״̬  4,����\n\n\n";
			switch (choose_number = getNum(1,4), choose_number)
			{
			case 1:
				s = SuiJi();
				cout << player.name << "����! " << Monster.name << "HP����" << player.attack + s + gong - Monster.defense / 3 << "\n\n\n";
				Monster.hp -= player.attack + s + gong - Monster.defense / 3;
				if (AttackResult())return; //��������н��(���˻����ս��)�˳�����
				else continue;
			case 2:
				Chooseitem();
				break; //ѡ����Ʒ,����ʹ��,ս��������ʹ�ù�������Ʒ
			case 3:
				DisplayState();
				break; //��ʾ״̬
			case 4:
				s = SuiJi();
				if (s < 4) //40%�ĸ��ʿ�������
				{
					cout << player.name << "������~\n\n\n";
					battle = 0;
					return;
				}
				else cout << player.name << "����ʧ��!\n\n\n";
				break;
			default:
				cout << "�������,��������!\n\n\n";
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

