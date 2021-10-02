#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "struct.h"
using namespace std;

entity entity_choosing(string entity_name);
bool batte_player(entity player, entity enemy);

bool story1(entity player)
{
	bool battle_ans = batte_player(player, entity_choosing("野狼"));
	if (battle_ans == true)
	{
		cout << "\n任务结束。" << endl;
		return true;
	}
	else
	{
		cout << "战斗失败……" << endl;
		return false;
	}

}