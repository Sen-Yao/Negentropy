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
		true,
		120, 100, 120,
		120, 100, 120,
		30, 20, 20, 30,
		"����ذ��",
		"",
		"",
		"Ƥ���ؼ�",
		"",
		"Ƥѥ",
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
		"ʿ��",
		true,
		120, 100, 120,
		120, 100, 120,
		40, 30, 40, 20,
		"����",
		"",
		"",
		"�����ؼ�",
		"",
		"��ѥ",
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
		"Ұ��",
		false,
		60, 0, 100,
		60, 0, 100,
		30, 0, 20, 30,
		"��צ",
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