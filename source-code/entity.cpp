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
		120, 100, 120,
		120, 100, 120,
		30, 20, 20, 30,
		"ÌúÖÊØ°Ê×",
		"",
		"",
		"Æ¤ÖÊĞØ¼×",
		"",
		"",
	};
	if (entity_name == bandit.name)
	{
		ans_entity = bandit;
	}
	entity soilder =
	{
		"Ê¿±ø",
		120, 100, 120,
		120, 100, 120,
		40, 30, 40, 20,
		"Ìú½£",
		"",
		"",
		"ÌúÖÊĞØ¼×",
		"",
		"",
	};
	if (entity_name == soilder.name)
	{
		ans_entity = soilder;
	}
	
	entity wolf =
	{
		"Ò°ÀÇ",
		60, 0, 100,
		60, 0, 100,
		30, 0, 20, 30,
		"ÀÇ×¦",
		"",
		"",
		"",
		"",
		"",
	};
	if (entity_name == wolf.name)
		ans_entity = wolf;


	return ans_entity;
};