#include <iostream>
#include "struct.h"
using namespace std;

armor armor_choosing(string armor_name)
{
	armor ans_armor;
	armor nothing =
	{
		"",
		"",
		0,
		0,
		0,
		"",
	};
	if (armor_name == nothing.name)
	{
		ans_armor = nothing;
	}
	armor fur_helmet =
	{
		"Ƥ��ͷ��",
		"ͷ��",
		10,
		10,
		20,
		"",
	};
	if (armor_name == fur_helmet.name)
	{
		ans_armor = fur_helmet;
	}

	armor iron_helmet =
	{
		"����ͷ��",
		"ͷ��",
		10,
		10,
		20,
		"",
	};
	if (armor_name == iron_helmet.name)
	{
		ans_armor = iron_helmet;
	}


	armor fur_armor =
	{
		"Ƥ���ؼ�",
		"����",
		10,
		5,
		20,
		"",
	};
	if (armor_name == fur_armor.name)
	{
		ans_armor = fur_armor;
	}
	armor iron_armor =
	{
		"�����ؼ�",
		"����",
		20,
		20,
		50,
		"",
	};
	if (armor_name == iron_armor.name)
	{
		ans_armor = iron_armor;
	}

	armor fur_gauntlet
	{
		"Ƥ�ʻ���",
		"�ֱ�",
		5,
		5,
		10,
		"",
	};
	if (armor_name == fur_gauntlet.name)
	{
		ans_armor = fur_gauntlet;
	}

	armor iron_gauntlet
	{
		"���ʻ���",
		"�ֱ�",
		10,
		10,
		20,
		"",
	};
	if (armor_name == iron_gauntlet.name)
	{
		ans_armor = iron_gauntlet;
	}

	armor fur_boot
	{
		"Ƥѥ",
		"�Ȳ�",
		5,
		5,
		10,
		"",
	};
	if (armor_name == fur_boot.name)
	{
		ans_armor = fur_boot;
	}

	armor iron_boot
	{
		"��ѥ",
		"�Ȳ�",
		10,
		10,
		20,
		"",
	};
	if (armor_name == iron_boot.name)
	{
		ans_armor = iron_boot;
	}
	return ans_armor;
}