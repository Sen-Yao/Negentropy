#include <string>
#include <iostream>
#include "struct.h"
using namespace std;

entity entity_choosing(string entity_name)
{
	entity ans_entity;
	entity bandit =
	{
		"ǿ��",
		120, 100, 120,
		120, 100, 120,
		30, 20, 20, 30,
		"����ذ��",
		"",
		"",
		"Ƥ���ؼ�",
		"",
		"",
	};
	if (entity_name == bandit.name)
	{
		ans_entity = bandit;
	}
	entity soilder =
	{
		"ʿ��",
		120, 100, 120,
		120, 100, 120,
		40, 30, 40, 20,
		"����",
		"",
		"",
		"�����ؼ�",
		"",
		"",
	};
	if (entity_name == soilder.name)
	{
		ans_entity = soilder;
	}
	
	entity wolf =
	{
		"Ұ��",
		60, 0, 100,
		60, 0, 100,
		30, 0, 20, 30,
		"��צ",
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