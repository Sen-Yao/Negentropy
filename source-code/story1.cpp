#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "struct.h"
using namespace std;

entity entity_choosing(string entity_name);
bool batte_player(entity player, entity enemy);
weapon weapon_choosing(string weapon_name);

bool story1(entity player)
{
	// -----叙事开始------
	cout << "序章……" << endl;
	Sleep(1000);
	cin.get();
	cout << "(使用回车继续剧情）" << endl;
	cin.get();
	cout << "帝国历1328年，你出生于东部地区加斯兰的一个边境村庄，布勒村。" << endl;
	cin.get();
	cout << "你的母亲擅长手工编织，你身上的衣物都由她一针一线缝制而成。" << endl;
	cin.get();
	cout << "而你的父亲，是一名退伍老兵，凭借着在战场上磨练出来战斗技巧，时不时能从附近的山上猎到几头野兽。" << endl;
	cin.get();
	cout << "或许是见识过战场的残酷，你的父亲从小就教导你剑技。" << endl;
	cin.get();
	cout << "得益于此，你一直是村里最强壮的小孩，在17岁那年，你第一次拿起开刃的剑，和入侵村庄的游牧民们战斗。" << endl;
	cin.get();
	cout << "但你并不是一个冷酷嗜血的人，挥砍时总是避开要害，也不追击逃跑的敌人。" << endl;
	cin.get();
	cout << "在击退了游牧民之后，你回头看向父亲，发现他的剑上没有一滴血。" << endl;
	cin.get();
	cout << "虽然战斗时有发生，但你们的生活依旧平和简朴。" << endl;
	cin.get();
	cout << "直到最近几个月，你发现父亲的精神状态有些不稳定。" << endl;
	cin.get();
	cout << "“我漫步在一条林间小径上，抬头看到的却是密密麻麻的太阳和月亮，填满了天空。时间就像铁水一样粘稠，我的每一次挣扎都会产生椭圆形的气泡，我看着它被挤压得越来越小，散成无数细碎的泡沫…”" << endl;
	cin.get();
	cout << "在神志相对清楚的时候，他总是在书房里，焦躁地写画着什么。" << endl;
	cin.get();
	cout << "你认为这是压力太大导致的，最近游牧民的进攻越来越频繁，父亲的剑上开始沾染血迹，虽然不知道是谁的血。" << endl;
	cin.get();
	cout << "终于有一天早上，你最担心的事还是发生了。" << endl;
	cin.get();
	cout << "父亲失踪了。" << endl;
	cin.get();
	cout << "你破开被锁住的书房门，却差点被满地的书绊倒。" << endl;
	cin.get();
	cout << "原先整齐排列在书架上的书如今散落一地，许多打开的书上都留有潦草的字迹。" << endl;
	cin.get();
	cout << "你一边艰难地在书堆中寻找落脚点，一边浏览着书中的内容。" << endl;
	cin.get();
	cout << "有几本书的内容由晦涩难懂的文法写就，似乎是在描绘一种神秘的仪式，以你的知识判断，这属于恶魔学的研究范畴。" << endl;
	cin.get();
	cout << "你不知道一生习武的父亲为何会痴迷于研究这些东西，但仍然隐隐感到担心。" << endl;
	cin.get();
	cout << "脚边一本翻开的书引起了你的注意，即使字迹十分潦草随意，但你还是认出，这就是父亲的手笔。" << endl;
	cin.get();
	cout << "这是父亲的日记，最后一条记录于昨天：" << endl;
	cin.get();
	cout << "“我想我已经接近了真相……神的旨意…只要杀死…不！我到底在说什么！我的心智已经走到了尽头，但我还有未了之事，是时候完成这场跨越数十年的复仇了…”" << endl;
	cin.get();
	cout << "你大受震撼，没想到一向温和宽厚的父亲竟还有如此沉重的过往。" << endl;
	cin.get();
	cout << "复仇…剑刃上的鲜血…" << endl;
	cin.get();
	cout << "你往下看去，发现了一张手绘的地图，与记忆中的地点相比对，你意识到这就是家附近的地图。" << endl;
	cin.get();
	cout << "家的位置标记着一颗五角星，而不远处的山区上则有一个血红色的叉。" << endl;
	cin.get();
	cout << "不安与担忧在你心中不断膨胀。" << endl;
	cin.get();
	cout << "以父亲最近的精神状态，如果贸然战斗，后果不堪设想。" << endl;
	cin.get();
	cout << "来不及多想，你抄起日记塞入怀中，扭头就要冲出家门。" << endl;
	cin.get();
	cout << "稍加思考后，你回到自己的房间，从箱子里抽出自己的铁剑。" << endl;
	cin.get();
	cout << weapon_choosing(player.weapon).description << endl;
	cin.get();
	cout << "为了格挡游牧民的铁斧，你的剑刃上已经出现了几个小缺口。" << endl;
	cin.get();
	cout << "父亲的剑刃一定十分完整锋利吧。" << endl;
	cin.get();
	cout << "一想到父亲，你的心中再次略过一阵焦急。" << endl;
	cin.get();
	cout << "“我要找到父亲，把他带回来。”" << endl;
	cin.get();
	cout << "母亲对你的突然出行有些惊讶，但还是默许了，父亲的失踪对她的打击很大。" << endl;
	cin.get();
	cout << "离开家后，你径直朝着山里跑去。" << endl;
	cin.get();
	cout << "山中的路你大致清楚，只是没过脚踝的积雪严重拖慢了你的进度。" << endl;
	cin.get();
	cout << "你心急如焚地朝着山里行进，全然没有注意到路边草丛的响动。" << endl;
	cin.get();
	cout << "视野边缘闪过一道黑影，你敏锐地转身，握住了剑柄。" << endl;
	cin.get();
	cout << "一匹野狼正幽幽地盯着你，它一动不动地挺立在雪地中，全身的狼毫根根倒竖，四肢微微弯曲，似乎正在积蓄力量，只有从锋利獠牙间溢出的丝丝白气才能证明这是个活物。" << endl;
	cin.get();
	cout << "你深吸一口气，拔出了铁剑。" << endl;
	cin.get();

	bool battle_ans = batte_player(player, entity_choosing("野狼"));
	if (battle_ans == false)
	{
		Sleep(1000);
		cout << "\n战斗失败……" << endl;
		return false;
	}
	cout << "\n\n\n(使用回车继续剧情）" << endl;
	cin.get();
	cout << "一番战斗后，野狼已经是强弓之末，但仍然挣扎着向你扑来。" << endl;
	cin.get();
	cout << "你压低身体，将剑尖挥出新月一般的弧度，划过它的咽喉。" << endl;
	cin.get();
	cout << "鲜血如喷泉般洒出，染红了一大片地面。" << endl;
	cin.get();
	cout << "野狼的身体在空中划过一道毫无生气的曲线，最后重重地砸在雪地上。" << endl;
	cin.get();
	cout << "几缕白色的烟气从它的口中和伤口处缓缓升起，仿佛是升天的灵魂。" << endl;
	cin.get();
	cout << "这就是斩杀生命的感觉吗？" << endl;
	cin.get();
	cout << "胜利带来的喜悦和得意瞬间烟消云散，你的呼吸变得粗重，用颤抖的手收起剑。" << endl;
	cin.get();
	cout << "为了生存，生命竟能爆发出如此强大的魄力。" << endl;
	cin.get();
	cout << "你抓起野狼的尸体，准备将其挪入路边的枯木丛。" << endl;
	cin.get();
	cout << "大雪封山数日，一般人根本不会想着进山。" << endl;
	cin.get();
	cout << "说不定会是父亲…" << endl;
	cin.get();
	cout << "简单埋葬完野狼的尸体，你顺着脚印继续前进。" << endl;
	cin.get();
	cout << "1003剧情结束" << endl;
	cin.get();
	return true;
}