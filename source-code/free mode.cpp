// ������һ��1v1ս���Ĳ��ԣ����ܻ�������c++��ѧϰ��������
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

    // ��ɫѡ��
    cout << "ѡ����Ľ�ɫ��\n1.ʿ��\n2.ǿ��\n";
    entity_selection = _getch();
    if (entity_selection == 49)
        player = entity_choosing("ʿ��");
    if (entity_selection == 50)
        player = entity_choosing("ǿ��");

    cout << "�㽫����" << player.name << endl;
    Sleep(500);

    cout << "\nѡ����ĵ��ˣ�\n1.ʿ��\n2.ǿ��\n";
    entity_selection = _getch();
    if (entity_selection == 49)
        enemy = entity_choosing("ʿ��");
    if (entity_selection == 50)
        enemy = entity_choosing("ǿ��");
    cout << "�㽫Ҫ���" << enemy.name << endl;

    Sleep(500);
    cout << "�����������ǳƣ�";
    cin >> player.name;
    cout << player.name << "����ӭ����ս����" << endl;

    batte_player(player, enemy);

    return 0;
}