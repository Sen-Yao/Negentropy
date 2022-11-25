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
    entity player, enemy;

    // 角色选择
    cout << "???????\n1.??\n2.??\n3.??\n";
    int entity_selection = _getch();
    while (entity_selection != 49 && entity_selection != 50 && entity_selection != 51)
    {
        entity_selection = _getch();
    }
    system("cls");
    if (entity_selection == 49)
        player = entity_choosing("??");
    if (entity_selection == 50)
        player = entity_choosing("??");
    if (entity_selection == 51)
        player = entity_choosing("??");

    cout << "????" << player.name << endl;

    if (player.human == true)
    {
        bool player_weapon_choosing = false;
        while (player_weapon_choosing == false)
        {
            system("cls");
            cout << "?????????" << player.weapon
                << "?????? " << weapon_choosing(player.weapon).damage
                << "???? " << weapon_choosing(player.weapon).weight
                << "\n???????\n1.?\n2.?\n";
            int player_weapon_change_1 = _getch();
            while (player_weapon_change_1 != 49 && player_weapon_change_1 != 50)
                player_weapon_change_1 = _getch();
            if (player_weapon_change_1 == 49)
                break;
            system("cls");

            cout << "???????\n1.?\n2.?\n";
            player_weapon_change_1 = _getch();
            while (player_weapon_change_1 != 49 && player_weapon_change_1 != 50)
                player_weapon_change_1 = _getch();
            if (player_weapon_change_1 == 49)
            {
                system("cls");
                cout << "??????\n1.????\n2.????\n";
                int player_weapon_change_2 = _getch();
                while (player_weapon_change_2 != 49 && player_weapon_change_2 != 50)
                {
                    player_weapon_change_2 = _getch();
                }
                system("cls");
                if (player_weapon_change_2 == 49)
                {
                    cout << "1.???\n2.???\n3.???\n4.??\n";
                    int player_weapon_change_3 = _getch();
                    while (player_weapon_change_3 != 49 && player_weapon_change_3 != 50 && player_weapon_change_3 != 51 && player_weapon_change_3 != 52)
                    {
                        player_weapon_change_3 = _getch();
                    }
                    system("cls");
                    if (player_weapon_change_3 == 49)
                    {
                        cout << "1.??\n2.??\n3.?????";
                        int player_weapon_change_3 = _getch();
                        while (player_weapon_change_3 != 49 && player_weapon_change_3 != 50 && player_weapon_change_3 != 51)
                        {
                            player_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (player_weapon_change_3 == 49)
                            player.weapon = "??";
                        if (player_weapon_change_3 == 50)
                            player.weapon = "??";
                        if (player_weapon_change_3 == 51)
                            player.weapon = "?????";
                    }
                    if (player_weapon_change_3 == 50)
                    {
                        cout << "1.??\n2.???\n";
                        int player_weapon_change_3 = _getch();
                        while (player_weapon_change_3 != 49 && player_weapon_change_3 != 50 && player_weapon_change_3 != 51)
                        {
                            player_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (player_weapon_change_3 == 49)
                            player.weapon = "??";
                        if (player_weapon_change_3 == 50)
                            player.weapon = "???";
                    }
                    if (player_weapon_change_3 == 51)
                    {
                        cout << "1.??\n";
                        int player_weapon_change_3 = _getch();
                        while (player_weapon_change_3 != 49 && player_weapon_change_3 != 50 && player_weapon_change_3 != 51)
                        {
                            player_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (player_weapon_change_3 == 49)
                            player.weapon = "??";


                    }
                    if (player_weapon_change_3 == 52)
                    {
                        cout << "1.????\n2.????\n3.????";
                        int player_weapon_change_3 = _getch();
                        while (player_weapon_change_3 != 49 && player_weapon_change_3 != 50 && player_weapon_change_3 != 51)
                        {
                            player_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (player_weapon_change_3 == 49)
                            player.weapon = "????";
                        if (player_weapon_change_3 == 50)
                            player.weapon = "????";
                        if (player_weapon_change_3 == 51)
                            player.weapon = "????";
                    }
                }
                if (player_weapon_change_2 == 50)
                {
                    cout << "1.???\n2.???\n3.???\n";
                    int player_weapon_change_3 = _getch();
                    while (player_weapon_change_3 != 49 && player_weapon_change_3 != 50 && player_weapon_change_3 != 51)
                    {
                        player_weapon_change_3 = _getch();
                    }
                    system("cls");
                    if (player_weapon_change_3 == 49)
                    {
                        cout << "1.????\n";
                        int player_weapon_change_3 = _getch();
                        while (player_weapon_change_3 != 49)
                        {
                            player_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (player_weapon_change_3 == 49)
                            player.weapon = "????";
                    }
                    if (player_weapon_change_3 == 50)
                    {
                        cout << "1.???\n2.??\n3.????\n";
                        int player_weapon_change_3 = _getch();
                        while (player_weapon_change_3 != 49 && player_weapon_change_3 != 50 && player_weapon_change_3 != 51)
                        {
                            player_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (player_weapon_change_3 == 49)
                            player.weapon = "???";
                        if (player_weapon_change_3 == 50)
                            player.weapon = "??";
                        if (player_weapon_change_3 == 51)
                            player.weapon = "????";
                    }
                    if (player_weapon_change_3 == 51)
                    {
                        cout << "1.????\n";
                        int player_weapon_change_3 = _getch();
                        while (player_weapon_change_3 != 49)
                        {
                            player_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (player_weapon_change_3 == 49)
                            player.weapon = "????";


                    }
                }
            }
            if (player_weapon_change_1 == 50)
                break;
        }
        
    }

    system("cls");
    cout << "选择你的敌人！\n1.士兵\n2.强盗\n3.野狼";
    entity_selection = _getch();
    if (entity_selection == 49)
        enemy = entity_choosing("士兵");
    if (entity_selection == 50)
        enemy = entity_choosing("强盗");
    if (entity_selection == 51)
        enemy = entity_choosing("野狼");

    if (enemy.human == true)
    {
        bool enemy_weapon_choosing = false;
        while (enemy_weapon_choosing == false)
        {
            system("cls");
            cout << "敌人当前选择的武器是" << enemy.weapon
                << "，它的伤害为 " << weapon_choosing(enemy.weapon).damage
                << "，重量为 " << weapon_choosing(enemy.weapon).weight
                << "\n让敌人使用这把武器？\n1.是\n2.否\n";
            int enemy_weapon_change_1 = _getch();
            while (enemy_weapon_change_1 != 49 && enemy_weapon_change_1 != 50)
                enemy_weapon_change_1 = _getch();
            if (enemy_weapon_change_1 == 49)
                break;
            system("cls");
            cout << "是否更换武器？\n1.是\n2.否\n";
            enemy_weapon_change_1 = _getch();
            while (enemy_weapon_change_1 != 49 && enemy_weapon_change_1 != 50)
                enemy_weapon_change_1 = _getch();
            if (enemy_weapon_change_1 == 49)
            {
                system("cls");
                cout << "武器类型检索\n1.单手武器\n2.双手武器\n";
                int enemy_weapon_change_2 = _getch();
                while (enemy_weapon_change_2 != 49 && enemy_weapon_change_2 != 50)
                {
                    enemy_weapon_change_2 = _getch();
                }
                system("cls");
                if (enemy_weapon_change_2 == 49)
                {
                    cout << "1.单手剑\n2.单手斧\n3.单手锤\n4.匕首\n";
                    int enemy_weapon_change_3 = _getch();
                    while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51 && enemy_weapon_change_3 != 52)
                    {
                        enemy_weapon_change_3 = _getch();
                    }
                    system("cls");
                    if (enemy_weapon_change_3 == 49)
                    {
                        cout << "1.铁剑\n2.钢剑\n3.精制军团剑";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "铁剑";
                        if (enemy_weapon_change_3 == 50)
                            enemy.weapon = "钢剑";
                        if (enemy_weapon_change_3 == 51)
                            enemy.weapon = "精制军团剑";
                    }
                    if (enemy_weapon_change_3 == 50)
                    {
                        cout << "1.铁斧\n2.双头斧\n";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "铁斧";
                        if (enemy_weapon_change_3 == 50)
                            enemy.weapon = "双头斧";
                    }
                    if (enemy_weapon_change_3 == 51)
                    {
                        cout << "1.铁锤\n";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "铁锤";


                    }
                    if (enemy_weapon_change_3 == 52)
                    {
                        cout << "1.铁质匕首\n2.钢制匕首\n3.暗影匕首";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "铁质匕首";
                        if (enemy_weapon_change_3 == 50)
                            enemy.weapon = "钢制匕首";
                        if (enemy_weapon_change_3 == 51)
                            enemy.weapon = "暗影匕首";
                    }
                }
                if (enemy_weapon_change_2 == 50)
                {
                    cout << "1.双手剑\n2.双手斧\n3.双手锤\n";
                    int enemy_weapon_change_3 = _getch();
                    while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                    {
                        enemy_weapon_change_3 = _getch();
                    }
                    system("cls");
                    if (enemy_weapon_change_3 == 49)
                    {
                        cout << "1.铁质大剑\n";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "铁质大剑";
                    }
                    if (enemy_weapon_change_3 == 50)
                    {
                        cout << "1.斩首斧\n2.斩斧\n3.杀戮巨斧\n";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "斩首斧";
                        if (enemy_weapon_change_3 == 50)
                            enemy.weapon = "斩斧";
                        if (enemy_weapon_change_3 == 51)
                            enemy.weapon = "杀戮巨斧";
                    }
                    if (enemy_weapon_change_3 == 51)
                    {
                        cout << "1.帝国重锤\n";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "帝国重锤";


                    }
                }
            }
            if (enemy_weapon_change_1 == 50)
                break;
        }

    }
    system("cls");
    cout << "你将要面对" << enemy.name << endl;
    Sleep(2000);

    batte_player(player, enemy);

    return 0;
}