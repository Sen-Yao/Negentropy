#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include "struct.h"


int save(entity player, int savepoint)
{
	cout << "\n�Զ��浵�С���\n";
	ofstream out("./saves\\save.txt");
	out << savepoint
		<< player.name << endl
		<< player.HP << " " << player.MP << " " << player.SP << endl
		<< player.max_HP << " " << player.max_MP << " " << player.max_SP << endl
		<< player.one_hand_level << " " << player.two_hand_level << " " << player.block_level << " " << player.dodge_level << endl
		<< player.weapon << endl
		<< player.helmet << endl
		<< player.armor << endl
		<< player.gauntlet <<endl
		<< player.boot << endl;
	out.close();
	Sleep(500);
	cout << "�浵�ɹ���\n";
	return 0;
}

entity load()
{
	entity player =
	{
		"player1",
		120, 100, 120,
		120, 100, 120,
		20, 20, 20, 20,
		"ȭͷ",
		"",
		"",
		"",
		"",
		"",
	};

	cout << "\n���ڶ�������\n";
	int savepoint = 0;
	ifstream in("./saves\\save.txt");
	in >> savepoint
		>>player.name
		>> player.HP >> player.MP >> player.SP
		>> player.max_HP >> player.max_MP >> player.max_SP
		>> player.one_hand_level >> player.two_hand_level >> player.block_level >> player.dodge_level
		>> player.weapon
		>> player.helmet
		>> player.armor
		>> player.gauntlet
		>> player.boot;
	in.close();
	cout << "��ȡ�ɹ�!\n" << endl;
	return player;


}