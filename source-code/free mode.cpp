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

    // ��ɫѡ��
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
    cout << "ѡ����ĵ��ˣ�\n1.ʿ��\n2.ǿ��\n3.Ұ��";
    entity_selection = _getch();
    if (entity_selection == 49)
        enemy = entity_choosing("ʿ��");
    if (entity_selection == 50)
        enemy = entity_choosing("ǿ��");
    if (entity_selection == 51)
        enemy = entity_choosing("Ұ��");

    if (enemy.human == true)
    {
        bool enemy_weapon_choosing = false;
        while (enemy_weapon_choosing == false)
        {
            system("cls");
            cout << "���˵�ǰѡ���������" << enemy.weapon
                << "�������˺�Ϊ " << weapon_choosing(enemy.weapon).damage
                << "������Ϊ " << weapon_choosing(enemy.weapon).weight
                << "\n�õ���ʹ�����������\n1.��\n2.��\n";
            int enemy_weapon_change_1 = _getch();
            while (enemy_weapon_change_1 != 49 && enemy_weapon_change_1 != 50)
                enemy_weapon_change_1 = _getch();
            if (enemy_weapon_change_1 == 49)
                break;
            system("cls");
            cout << "�Ƿ����������\n1.��\n2.��\n";
            enemy_weapon_change_1 = _getch();
            while (enemy_weapon_change_1 != 49 && enemy_weapon_change_1 != 50)
                enemy_weapon_change_1 = _getch();
            if (enemy_weapon_change_1 == 49)
            {
                system("cls");
                cout << "�������ͼ���\n1.��������\n2.˫������\n";
                int enemy_weapon_change_2 = _getch();
                while (enemy_weapon_change_2 != 49 && enemy_weapon_change_2 != 50)
                {
                    enemy_weapon_change_2 = _getch();
                }
                system("cls");
                if (enemy_weapon_change_2 == 49)
                {
                    cout << "1.���ֽ�\n2.���ָ�\n3.���ִ�\n4.ذ��\n";
                    int enemy_weapon_change_3 = _getch();
                    while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51 && enemy_weapon_change_3 != 52)
                    {
                        enemy_weapon_change_3 = _getch();
                    }
                    system("cls");
                    if (enemy_weapon_change_3 == 49)
                    {
                        cout << "1.����\n2.�ֽ�\n3.���ƾ��Ž�";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "����";
                        if (enemy_weapon_change_3 == 50)
                            enemy.weapon = "�ֽ�";
                        if (enemy_weapon_change_3 == 51)
                            enemy.weapon = "���ƾ��Ž�";
                    }
                    if (enemy_weapon_change_3 == 50)
                    {
                        cout << "1.����\n2.˫ͷ��\n";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "����";
                        if (enemy_weapon_change_3 == 50)
                            enemy.weapon = "˫ͷ��";
                    }
                    if (enemy_weapon_change_3 == 51)
                    {
                        cout << "1.����\n";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "����";


                    }
                    if (enemy_weapon_change_3 == 52)
                    {
                        cout << "1.����ذ��\n2.����ذ��\n3.��Ӱذ��";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "����ذ��";
                        if (enemy_weapon_change_3 == 50)
                            enemy.weapon = "����ذ��";
                        if (enemy_weapon_change_3 == 51)
                            enemy.weapon = "��Ӱذ��";
                    }
                }
                if (enemy_weapon_change_2 == 50)
                {
                    cout << "1.˫�ֽ�\n2.˫�ָ�\n3.˫�ִ�\n";
                    int enemy_weapon_change_3 = _getch();
                    while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                    {
                        enemy_weapon_change_3 = _getch();
                    }
                    system("cls");
                    if (enemy_weapon_change_3 == 49)
                    {
                        cout << "1.���ʴ�\n";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "���ʴ�";
                    }
                    if (enemy_weapon_change_3 == 50)
                    {
                        cout << "1.ն�׸�\n2.ն��\n3.ɱ¾�޸�\n";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49 && enemy_weapon_change_3 != 50 && enemy_weapon_change_3 != 51)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "ն�׸�";
                        if (enemy_weapon_change_3 == 50)
                            enemy.weapon = "ն��";
                        if (enemy_weapon_change_3 == 51)
                            enemy.weapon = "ɱ¾�޸�";
                    }
                    if (enemy_weapon_change_3 == 51)
                    {
                        cout << "1.�۹��ش�\n";
                        int enemy_weapon_change_3 = _getch();
                        while (enemy_weapon_change_3 != 49)
                        {
                            enemy_weapon_change_3 = _getch();
                        }
                        system("cls");
                        if (enemy_weapon_change_3 == 49)
                            enemy.weapon = "�۹��ش�";


                    }
                }
            }
            if (enemy_weapon_change_1 == 50)
                break;
        }

    }
    system("cls");
    cout << "�㽫Ҫ���" << enemy.name << endl;
    Sleep(2000);

    batte_player(player, enemy);

    return 0;
}