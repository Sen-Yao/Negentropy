// 这是一个武器库文件，用于将设计好的武器存放于此并进行调用
#include <iostream>
#include <string>
#include "struct.h"

weapon weapon_choosing(string weapon_name)
{
	weapon ans_weapon;
	weapon iron_dagger =
	{
		"铁质匕首",
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
		"铁剑",
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
		"狼爪",
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