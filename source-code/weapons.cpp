// 这是一个武器库文件，用于将设计好的武器存放于此并进行调用
#include <iostream>
#include <string>
#include "struct.h"

weapon weapon_choosing(string weapon_name)
{
	weapon ans_weapon;
	// ------------------------------匕首------------------------------
	weapon iron_dagger =
	{
		"铁质匕首",
		"原本是猎人用来给猎物剥皮的工具小刀。但在强盗们眼里，它最经典的用法，还是用来割下受害者们的头颅。",
		"匕首",
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
		"钢制匕首",
		"质量良好的一把匕首，既是每个加斯兰旅行者的理想生存工具，也是战士们拼死一搏的绝佳备用武器",
		"匕首",
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
		"暗影匕首",
		"据一名从刺客手下侥幸逃出的贵族称，这把几乎不反光的乌黑匕首一旦掏出，死亡的阴影就将无声吞噬一切敌人",
		"匕首",
		40,
		4,
		200,
		true,
		"",
	};
	if (weapon_name == shadow_dagger.name)
		ans_weapon = shadow_dagger;
	// ------------------------------单手剑------------------------------
	weapon iron_sword =
	{
		"铁剑",
		"相传衡量一把剑是否优质的标准是用指尖顶住剑的重心，如果能稳稳地指向南北，就是好剑。但这把剑显然无法令人满意，因为它的重心似乎在剑身之外…",
		"单手剑",
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
		"钢剑",
		"用更高纯度的钢铁打造的直剑。因为优异的平衡性和锋利度而被广泛使用，即使是施展剑刃风暴这样的剑技也不会失衡",
		"单手剑",
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
		"精制军团剑",
		"有军团中的精英才配使用的剑。由于煅烧时加入了少许魔晶矿，剑身与魔法的相性很好，可以进行简单地附魔。因为硬度过高，每次研磨时都会消耗数个砥石，一般的铁匠铺甚至无法承受起一次保养",
		"单手剑",
		100,
		8,
		300,
		true,
		"",
	};
	if (weapon_name == refined_legion_sword.name)
		ans_weapon = refined_legion_sword;

	// ------------------------------单手斧------------------------------

	weapon iron_axe =
	{
		"铁斧",
		"这是用来砍树的斧头，如果拿来战斗的话……你当敌人是木头吗？不过用来砍断树枝的话倒是意外地容易…",
		"单手斧",
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
		"双头斧",
		"这确实是用来战斗的斧头……双刃设计可以使挥砍更加灵活，使用时请小心不要伤到自己",
		"单手斧",
		100,
		10,
		100,
		true,
		"",
	};
	if (weapon_name == double_head_axe.name)
		ans_weapon = double_head_axe;

	// ------------------------------单手锤------------------------------

	weapon iron_hammer =
	{
		"铁锤",
		"常见的加工用木柄铁锤，如果举高后下砸，能大幅削减举盾防御敌人的耐力，面对穿着重甲的敌人，沉重一击产生的震荡波也能对盔甲里的敌人造成损伤，但是用力挥舞后会留下巨大的硬直",
		"单手锤",
		120,
		12,
		100,
		false,
		"",
	};
	if (weapon_name == iron_hammer.name)
		ans_weapon = iron_hammer;

	// ------------------------------双手剑------------------------------

	weapon iron_greatsword =
	{
		"铁质大剑",
		"必须双手持握才能掌控的重型剑，虽然挥砍的力道十分恐怖，但也放弃了任何防御的可能，曾有位强壮的士兵为了炫耀自己的力量，只用右手挥舞大剑，却因为难以对抗惯性，砍断了自己的左臂",
		"双手剑",
		80,
		10,
		100,
		true,
		"",
	};
	if (weapon_name == iron_greatsword.name)
		ans_weapon = iron_greatsword;

	// ------------------------------双手斧------------------------------

	weapon execution_axe =
	{
		"斩首斧",
		"教会处决异教徒时使用的斧子，铂金制成斧头和白桦木斧柄是为了让处决时溅出的血更加显眼，有时候血液渍进了木头里，难以洗净，刽子手会直接削去被渗透的部分，久而久之斧柄越来越脆弱，似乎随时就会折断",
		"双手斧",
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
		"斩斧",
		"只有用双手才能勉强举起的巨斧，如果用它砍中敌人，斧刃会在血肉中游弋，不管是怎样的筋脉和骨骼都能斩断，某位士兵在行军途中未能固定好背后的斩斧，斧头在下落过程中砍断了他的半个脚踝",
		"双手斧",
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
		"杀戮巨斧",
		"相传这把巨斧内居住着一位魔神，赐予这把巨斧无尽的力量。当然，魔神的祝福从来都是有代价的……它需要无尽的鲜血来献祭……",
		"双手斧",
		300,
		16,
		2000,
		true,
		"",
	};
	if (weapon_name == slaying_axe.name)
		ans_weapon = slaying_axe;

	// ------------------------------双手锤------------------------------

	weapon imperial_hammer =
	{
		"帝国重锤",
		"往往由帝国军团中最强壮的勇士挥舞的双手战锤，巨大的重量足以冲散一切常规军队的防守阵型。当然，说的是常规军队……",
		"双手锤",
		200,
		18,
		300,
		false,
		"",
	};
	if (weapon_name == imperial_hammer.name)
		ans_weapon = imperial_hammer;

	weapon wolf_claw =
	{
		"狼爪",
		"",
		"其他",
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