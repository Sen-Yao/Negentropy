// 仅仅是一个1v1战斗的测试，功能还得随着c++的学习慢慢完善
#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "struct.h"
using namespace std;

entity entity_choosing(string entity_name);
weapon weapon_choosing(string weapon_name);
armor armor_choosing(string armor_name);
bool player_attack(entity* p_player, entity* p_enemy, bool gameover);
bool AI_attack(entity* p_red, entity* p_blue, bool gameover);
bool batte_player(entity player, entity enemy);

int freefight()
{
    int entity_selection;
    entity player, enemy;

    // 角色选择
    cout << "选择你的角色！\n1.士兵\n2.强盗\n";
    entity_selection = _getch();
    if (entity_selection == 49)
        player = entity_choosing("士兵");
    if (entity_selection == 50)
        player = entity_choosing("强盗");

    cout << "你将扮演" << player.name << endl;
    Sleep(500);

    cout << "\n选择你的敌人！\n1.士兵\n2.强盗\n";
    entity_selection = _getch();
    if (entity_selection == 49)
        enemy = entity_choosing("士兵");
    if (entity_selection == 50)
        enemy = entity_choosing("强盗");
    cout << "你将要面对" << enemy.name << endl;

    Sleep(500);
    cout << "请输入您的昵称：";
    cin >> player.name;
    cout << player.name << "，欢迎来到战斗！" << endl;

    batte_player(player, enemy);

    return 0;
}