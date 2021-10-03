// ����һ���������ļ������ڽ���ƺõ���������ڴ˲����е���
#include <iostream>
#include <string>
#include "struct.h"

weapon weapon_choosing(string weapon_name)
{
	weapon ans_weapon;
	// ------------------------------ذ��------------------------------
	weapon iron_dagger =
	{
		"����ذ��",
		"ԭ�������������������Ƥ�Ĺ���С��������ǿ��������������÷����������������ܺ����ǵ�ͷ­��",
		"ذ��",
		true,
		15,
		4,
		20,
		true,
		"",
	};
	if (weapon_name == iron_dagger.name)
		ans_weapon = iron_dagger;

	weapon steel_dagger =
	{
		"����ذ��",
		"�������õ�һ��ذ�ף�����ÿ����˹�������ߵ��������湤�ߣ�Ҳ��սʿ��ƴ��һ���ľ��ѱ�������",
		"ذ��",
		true,
		25,
		4,
		50,
		true,
		"",
	};
	if (weapon_name == steel_dagger.name)
		ans_weapon = steel_dagger;

	weapon shadow_dagger =
	{
		"��Ӱذ��",
		"��һ���Ӵ̿����½����ӳ��Ĺ���ƣ���Ѽ�����������ں�ذ��һ���ͳ�����������Ӱ�ͽ���������һ�е���",
		"ذ��",
		true,
		40,
		4,
		200,
		true,
		"",
	};
	if (weapon_name == shadow_dagger.name)
		ans_weapon = shadow_dagger;
	// ------------------------------���ֽ�------------------------------
	weapon iron_sword =
	{
		"����",
		"�ഫ����һ�ѽ��Ƿ����ʵı�׼����ָ�ⶥס�������ģ���������ȵ�ָ���ϱ������Ǻý�������ѽ���Ȼ�޷��������⣬��Ϊ���������ƺ��ڽ���֮�⡭",
		"���ֽ�",
		true,
		50,
		7,
		50,
		true,
		"",
	};
	if (weapon_name == iron_sword.name)
		ans_weapon = iron_sword;

	weapon steel_sword =
	{
		"�ֽ�",
		"�ø��ߴ��ȵĸ��������ֱ������Ϊ�����ƽ���Ժͷ����ȶ����㷺ʹ�ã���ʹ��ʩչ���з籩�����Ľ���Ҳ����ʧ��",
		"���ֽ�",
		true,
		80,
		8,
		100,
		true,
		"",
	};
	if (weapon_name == steel_sword.name)
		ans_weapon = steel_sword;

	weapon refined_legion_sword =
	{
		"���ƾ��Ž�",
		"�о����еľ�Ӣ����ʹ�õĽ�����������ʱ����������ħ���󣬽�����ħ�������Ժܺã����Խ��м򵥵ظ�ħ����ΪӲ�ȹ��ߣ�ÿ����ĥʱ��������������ʯ��һ��������������޷�������һ�α���",
		"���ֽ�",
		true,
		100,
		8,
		300,
		true,
		"",
	};
	if (weapon_name == refined_legion_sword.name)
		ans_weapon = refined_legion_sword;

	// ------------------------------���ָ�------------------------------

	weapon iron_axe =
	{
		"����",
		"�������������ĸ�ͷ���������ս���Ļ������㵱������ľͷ�𣿲�������������֦�Ļ�������������ס�",
		"���ָ�",
		true,
		70,
		9,
		50,
		true,
		"",
	};
	if (weapon_name == iron_axe.name)
		ans_weapon = iron_axe;

	weapon double_head_axe =
	{
		"˫ͷ��",
		"��ȷʵ������ս���ĸ�ͷ����˫����ƿ���ʹ�ӿ�������ʹ��ʱ��С�Ĳ�Ҫ�˵��Լ�",
		"���ָ�",
		true,
		100,
		10,
		100,
		true,
		"",
	};
	if (weapon_name == double_head_axe.name)
		ans_weapon = double_head_axe;

	// ------------------------------���ִ�------------------------------

	weapon iron_hammer =
	{
		"����",
		"�����ļӹ���ľ������������ٸߺ����ң��ܴ�������ٶܷ������˵���������Դ����ؼ׵ĵ��ˣ�����һ���������𵴲�Ҳ�ܶԿ�����ĵ���������ˣ������������������¾޴��Ӳֱ",
		"���ִ�",
		true,
		120,
		12,
		100,
		false,
		"",
	};
	if (weapon_name == iron_hammer.name)
		ans_weapon = iron_hammer;

	// ------------------------------˫�ֽ�------------------------------

	weapon iron_greatsword =
	{
		"���ʴ�",
		"����˫�ֳ��ղ����ƿص����ͽ�����Ȼ�ӿ�������ʮ�ֲֿ�����Ҳ�������κη����Ŀ��ܣ�����λǿ׳��ʿ��Ϊ����ҫ�Լ���������ֻ�����ֻ���󽣣�ȴ��Ϊ���ԶԿ����ԣ��������Լ������",
		"˫�ֽ�",
		true,
		80,
		10,
		100,
		true,
		"",
	};
	if (weapon_name == iron_greatsword.name)
		ans_weapon = iron_greatsword;

	// ------------------------------˫�ָ�------------------------------

	weapon execution_axe =
	{
		"ն�׸�",
		"�̻ᴦ�����ͽʱʹ�õĸ��ӣ������Ƴɸ�ͷ�Ͱ���ľ������Ϊ���ô���ʱ������Ѫ�������ۣ���ʱ��ѪҺ�ս���ľͷ�����ϴ���������ֻ�ֱ����ȥ����͸�Ĳ��֣��ö���֮����Խ��Խ�������ƺ���ʱ�ͻ��۶�",
		"˫�ָ�",
		true,
		150,
		14,
		200,
		true,
		"",
	};
	if (weapon_name == execution_axe.name)
		ans_weapon = execution_axe;

	weapon chop_axe =
	{
		"ն��",
		"ֻ����˫�ֲ�����ǿ����ľ޸�������������е��ˣ����л���Ѫ������߮�������������Ľ����͹�������ն�ϣ�ĳλʿ�����о�;��δ�̶ܹ��ñ����ն������ͷ����������п��������İ������",
		"˫�ָ�",
		true,
		200,
		14,
		500,
		true,
		"",
	};
	if (weapon_name == chop_axe.name)
		ans_weapon = chop_axe;

	weapon slaying_axe =
	{
		"ɱ¾�޸�",
		"�ഫ��Ѿ޸��ھ�ס��һλħ�񣬴�����Ѿ޸��޾�����������Ȼ��ħ���ף�����������д��۵ġ�������Ҫ�޾�����Ѫ���׼�����",
		"˫�ָ�",
		true,
		300,
		16,
		2000,
		true,
		"",
	};
	if (weapon_name == slaying_axe.name)
		ans_weapon = slaying_axe;

	// ------------------------------˫�ִ�------------------------------

	weapon imperial_hammer =
	{
		"�۹��ش�",
		"�����ɵ۹���������ǿ׳����ʿ�����˫��ս�����޴���������Գ�ɢһ�г�����ӵķ������͡���Ȼ��˵���ǳ�����ӡ���",
		"˫�ִ�",
		true,
		200,
		18,
		300,
		false,
		"",
	};
	if (weapon_name == imperial_hammer.name)
		ans_weapon = imperial_hammer;

	// ------------------------------����------------------------------
	weapon human_fist =
	{
		"ȭͷ",
		"",
		"����",
		true,
		5,
		3,
		10,
		false,
		""
	};
	if (weapon_name == human_fist.name)
		ans_weapon = human_fist;
	weapon wolf_claw =
	{
		"��צ",
		"",
		"����",
		false,
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