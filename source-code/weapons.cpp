// ����һ���������ļ������ڽ���ƺõ���������ڴ˲����е���
#include <iostream>
#include <string>
#include "struct.h"

weapon weapon_choosing(string weapon_name)
{
	weapon ans_weapon;
	weapon iron_dagger =
	{
		"����ذ��",
		15,
		4,
		20,
		true,
		"",
	};
	if (weapon_name == iron_dagger.name)
		ans_weapon = iron_dagger;

	weapon iron_sword =
	{
		"����",
		50,
		7,
		50,
		true,
		"",
	};
	if (weapon_name == iron_sword.name)
		ans_weapon = iron_sword;

	weapon wolf_claw =
	{
		"��צ",
		10,
		4,
		10,
		true,
		""
	};
	if (weapon_name == wolf_claw.name)
		ans_weapon = wolf_claw;
	return ans_weapon;
}