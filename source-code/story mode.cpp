#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include "struct.h"
using namespace std;

int batte_player(entity player, entity enemy);

bool story1(entity player);

int save(entity player, int savepoint);
entity load();

int story_mode(int savepoint)
{
	bool quit_story_mode = false;
	while (quit_story_mode == false)
	{
		if (savepoint == 0)
		{
			entity player =
			{
				"player",
				100, 100, 100,
				100, 100, 100,
				20, 20, 20, 20,
				"����",
				"",
				"",
				"Ƥ���ؼ�",
				"",
				"",
			};
			
			cout << "��������ǡ���" << endl;
			cin >> player.name;
			cout << "�����" << player.name << endl;
			Sleep(1000);
			savepoint = 1;
			save(player, savepoint);
		}
		if (savepoint == 1)
		{
			cout << "\n������˵�һ��\n";
			entity player = load();
			bool story_ans = story1(player);
			if (story_ans == false)
			{
				player.MP -= 1;
				cout << "\n����1ʧ�ܡ�����ȡ�浵��\n";
				player = load();
				savepoint = 1;
			}
		}
		cout << "��ͨ���ˣ�";
		quit_story_mode = true;
		cin.get();
	}
	return 0;
}