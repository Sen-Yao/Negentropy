#include <string>
#include <iostream>
#include "struct.h"
using namespace std;

entity entity_choosing(string entity_name)
{
	entity ans_entity;
	entity bandit =
	{
		"Ç¿µÁ",
		true,
		120, 100, 120,
		120, 100, 120,
		30, 20, 20, 30,
		"ÌúÖÊØ°Ê×",
		"",
		"",
		"Æ¤ÖÊĞØ¼×",
		"",
		"Æ¤Ñ¥",
		3,
		false,
		true,
	};
	if (entity_name == bandit.name)
	{
		ans_entity = bandit;
	}
	entity soilder =
	{
		"Ê¿±ø",
		true,
		120, 100, 120,
		120, 100, 120,
		40, 30, 40, 20,
		"Ìú½£",
		"",
		"",
		"ÌúÖÊĞØ¼×",
		"",
		"ÌúÑ¥",
		2,
		false,
		false,
	};
	if (entity_name == soilder.name)
	{
		ans_entity = soilder;
	}
	
	entity wolf =
	{
		"Ò°ÀÇ",
		false,
		60, 0, 100,
		60, 0, 100,
		30, 0, 20, 30,
		"ÀÇ×¦",
		"",
		"",
		"",
		"",
		"",
		4,
		false,
		true,
	};
	if (entity_name == wolf.name)
		ans_entity = wolf;


	return ans_entity;
};