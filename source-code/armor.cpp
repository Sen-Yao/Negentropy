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

	armor iron_armor =
	{
		"ÌúÖÊÐØ¼×",
		"Çû¸É",
		20,
		20,
		50,
		"",
	};
	if (armor_name == iron_armor.name)
	{
		ans_armor = iron_armor;
	}

	armor fur_armor =
	{
		"Æ¤ÖÊÐØ¼×",
		"Çû¸É",
		10,
		5,
		20,
		"",
	};
	if (armor_name == fur_armor.name)
	{
		ans_armor = fur_armor;
	}
	return ans_armor;
}