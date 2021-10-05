// ���ļ�Ŀǰ������������
// ����ǰ�������ڼ��������ʺ͸񵲼�����
// ��������AI�����ߺ�������������ʵ���״̬�����һ������������AI�����Ľ��
// �ٺ��������ֱ��ʾ��ҵ�һ���غϣ���AI�ٿص�һ���غ�
// ���һ������������Һ�AI��ս�ĺ���
// �Ժ�ս����صĺ�������������ļ������Ƕ��˳������
// Լ�������µĶ��������У�red����������/������/���ж�Ȩ����blue��������/���ط�/���ж���
// ������Һ�AI��ս���У���player��enemy�������ʷ�������⣩�����Կ���ͳһ��

#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <conio.h>
#include "struct.h"
using namespace std;

entity entity_choosing(string entity_name);
weapon weapon_choosing(string weapon_name);
armor armor_choosing(string armor_name);
int printlogo();

float calculate_dodge_chance(entity red, entity blue)
{
    int blue_weight = armor_choosing(blue.helmet).weight + armor_choosing(blue.armor).weight
        + armor_choosing(blue.gauntlet).weight + armor_choosing(blue.boot).weight;

    float dodge_chance = 1.0;

    if (weapon_choosing(red.weapon).type == "ذ��"
        || weapon_choosing(red.weapon).type == "���ֽ�"
        || weapon_choosing(red.weapon).type == "���ָ�"
        || weapon_choosing(red.weapon).type == "���ִ�"
        || weapon_choosing(red.weapon).type == "����")
    {
        dodge_chance = ((100 + float(blue.dodge_level - 2 * blue_weight)) / 100) * float(blue.SP) / float(blue.max_SP)
            - 2 * ((100 + float(0.8 * red.one_hand_level - 4.0 * float(weapon_choosing(red.weapon).weight))) / 100) * float(red.SP) / float(red.max_SP)
            + 0.8;
    }
    if (weapon_choosing(red.weapon).type == "˫�ֽ�"
        || weapon_choosing(red.weapon).type == "˫�ָ�"
        || weapon_choosing(red.weapon).type == "˫�ִ�")
    {
        dodge_chance = ((100 + float(blue.dodge_level - 2 * blue_weight)) / 100) * float(blue.SP) / float(blue.max_SP)
            - 2 * ((100 + float(0.8 * red.two_hand_level - 4.0 * float(weapon_choosing(red.weapon).weight))) / 100) * float(red.SP) / float(red.max_SP)
            + 0.8;
    }

    if (dodge_chance < 0)
        dodge_chance = 0;
    if (dodge_chance > 1)
        dodge_chance = 1;

    return dodge_chance;
    
}
float calculate_block_percentage(entity red, entity blue)
{
    float block_percentage = 0.0;

    if (weapon_choosing(red.weapon).type == "ذ��"
        || weapon_choosing(red.weapon).type == "���ֽ�"
        || weapon_choosing(red.weapon).type == "���ָ�"
        || weapon_choosing(red.weapon).type == "���ִ�"
        || weapon_choosing(red.weapon).type == "����")
    {
        block_percentage = 0.5 * ((float(100 + 4 * blue.block_level + 10) * float(blue.SP / blue.max_SP) / 100)
            - (float(100 + 5 * weapon_choosing(red.weapon).weight + 4 * red.one_hand_level) * float(red.SP / red.max_SP) / 100)
            + 1);
    }
    if (weapon_choosing(red.weapon).type == "˫�ֽ�"
        || weapon_choosing(red.weapon).type == "˫�ָ�"
        || weapon_choosing(red.weapon).type == "˫�ִ�")
    {
        block_percentage = 0.5 * (((100 + 4 * blue.block_level + 10) * (blue.SP / blue.max_SP) / 100)
            - ((100 + 5 * weapon_choosing(red.weapon).weight + 4 * red.two_hand_level) * (red.SP / red.max_SP) / 100)
            + 1);
    }

    if (block_percentage < 0)
        block_percentage = 0;
    if (block_percentage > 1)
        block_percentage = 1;

    return block_percentage;
}

int AI_decision(entity* p_red, entity* p_blue)
{
    int action = 0;
    entity red = *p_red;
    entity blue = *p_blue;

    float dodge_chance = calculate_dodge_chance(red, blue);
    // �췽��ͬ�������ȼ�����������������ͬ��Ӧ��
    if (red.courage == 0)
        action = 53;
    if (red.courage == 1)
    {
        if (red.HP <= 0.5 * red.max_HP)
            action = 53;
        else if ((1 - dodge_chance) > 0.8 || red.SP == red.max_SP)
            action = 49;
        else
            action = 51;
    }

    if (red.courage == 2)
    {
        if (red.HP <= 0.3 * red.max_HP)
            action = 53;
        else if ((1 - dodge_chance) > 0.5 || red.SP > 0.8 * red.max_SP)
            action = 49;
        else
            action = 51;
    }

    if (red.courage == 3)
    {
        if (red.HP <= 0.2 * red.max_HP)
        {
            action = 53;
            if (blue.HP - weapon_choosing(red.weapon).damage <= 0)
                action = 49;
        }
        else if ((1 - dodge_chance) > 0.3 || red.SP > 0.5 * red.max_SP)
            action = 49;
        else
            action = 51;
    }

    if (red.courage == 4)
    {
        if ((1 - dodge_chance) > 0.3 || red.SP > 0.5 * red.max_SP)
            action = 49;
        else
            action = 51;
        
    }
    return action;
}

int player_attack(entity* p_player, entity* p_enemy)
{
    int result = 0;  // resultָ������غϽ�����ս���Ľ����0�������ս����1����Է�������2����������
    entity player = *p_player;
    entity enemy = *p_enemy;

    int enemy_weight = armor_choosing(enemy.helmet).weight + armor_choosing(enemy.armor).weight
        + armor_choosing(enemy.gauntlet).weight + armor_choosing(enemy.boot).weight;

    int enemy_protection = armor_choosing(enemy.helmet).protection + armor_choosing(enemy.armor).protection
        + armor_choosing(enemy.gauntlet).protection + armor_choosing(enemy.boot).protection;

    float dodge_chance = calculate_dodge_chance(player, enemy);
    
    player.defending = false;

    cout << "\n\n��Ļغϣ�\n"
        << "��ǰ�������ֵΪ" << player.HP << "�� ����ֵΪ" << player.SP << endl
        <<"\n��ѡ�������Ϊ\n";

    if (player.dodging == true)
        cout << "��ǰ����Զ�����״̬�ǣ�����\n";
    else
        cout << "��ǰ����Զ�����״̬�ǣ��ر�\n";

    cout << "\n1.������\n2.����񵲣�\n3.������Ϣ\n4.����Ʒ������������δʵ�֣�\n5.�����Զ�����\n5.����\n" << endl;
    cout << "���������ڹ�����������Ϊ" << (1 - dodge_chance) * 100 << "%��\n" << endl;

    int action;
    action = _getch();
    while (action != 49 && action != 50 && action != 51 && action != 52 && action != 54)
    {
        if (action == 53)
        {
            if (player.dodging == true)
            {
                cout << "\n�Զ������ѹر�\n";
                player.dodging = false;
            }
            else
            {
                cout << "\n�Զ������ѿ���\n";
                player.dodging = true;
            }
        }
        action = _getch();
    }
    if (action == 49)
    {
        if (enemy.defending == true)  // �����˴�ʱ���ڸ�
        {
            bool attacking = true;
            while (attacking == true)
            {
                cout << player.name << "�ֳ�" << player.weapon << "����" << enemy.name << "����\n\n";
                Sleep(500);
                player.SP -= 10 * weapon_choosing(player.weapon).weight;  // ��������������
                if (player.SP < 0)
                    player.SP = 0;

                    // �������������
                    if (weapon_choosing(player.weapon).type == "ذ��"
                        || weapon_choosing(player.weapon).type == "���ֽ�"
                        || weapon_choosing(player.weapon).type == "���ָ�"
                        || weapon_choosing(player.weapon).type == "���ִ�"
                        || weapon_choosing(player.weapon).type == "����")
                    {
                        player.one_hand_level += 0.1 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                    }
                    if (weapon_choosing(player.weapon).type == "˫�ֽ�"
                        || weapon_choosing(player.weapon).type == "˫�ָ�"
                        || weapon_choosing(player.weapon).type == "˫�ִ�")
                    {
                        player.one_hand_level += 0.3 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                    }

                    float block_percetage = calculate_block_percentage(player, enemy);
                    cout << "\ndebug:������Ϊ��" << block_percetage << endl;
                    float damage = (weapon_choosing(player.weapon).damage + float((rand() % 100)) / 10) * (float(100 - enemy_protection) / 100.0) * float(1 - block_percetage);
                    enemy.HP -= int(damage);
                    if (enemy.HP > 0)
                    {
                        // �������������ԣ���˼�����һ�ν������������ṩ����ң�������Ҿ���Ȩ
                        dodge_chance = ((100 + float(enemy.dodge_level - 2 * enemy_weight)) / 100) * (float(enemy.SP) / float(enemy.max_SP))
                            - ((100 + float(player.one_hand_level - 3 * weapon_choosing(player.weapon).weight)) / 100) * (float(player.SP) / float(enemy.max_SP))
                            + 0.4;
                        // �Գ���ȡֵ��Χ�ļ��ʽ�������
                        if (dodge_chance < 0)
                            dodge_chance = 0;
                        if (dodge_chance > 1)
                            dodge_chance = 1;
                        cout << "�����ɹ���";
                        cout << player.name << "�����" << int(damage) << "���˺���" << enemy.name << "ʣ��Ѫ��Ϊ" << enemy.HP << endl;
                        cout << player.name << "ʣ������Ϊ" << player.SP << endl;
                        Sleep(1000);
                        if (player.SP == 0)
                        {
                            cout << "\n�������ˡ�����������\n";
                            attacking = false;
                            result = 0;
                            break;
                        }
                        cout
                            << "\n������������������Ϊ" << (1 - dodge_chance) * 100 << "%" << endl
                            << "\n�Ƿ�������\n1.��\n2.��\n3.�鿴���״̬" << endl;

                        int attacking_choice;
                        attacking_choice = _getch();
                        while (attacking_choice != 49 && attacking_choice != 50)
                        {
                            if (attacking_choice == 51)
                                cout << "��ǰ�������ֵΪ" << player.HP << "����ǰ�������ֵΪ" << player.SP << endl;
                            attacking_choice = _getch();
                        }
                        if (attacking_choice == 50)
                        {
                            attacking = false;
                            cout << "��ѡ�������֡�" << endl;
                            result = 0;

                        }
                    }
                    if (enemy.HP <= 0)
                    {
                        result = 1;
                        attacking = false;
                        cout << player.name << "�����" << damage << "���˺���ɱ����" << enemy.name << "��";
                    }
                    
                }
            }
        if (enemy.defending == false && enemy.dodging == true)
        {
            // �����ж�
            bool attacking = true;
            while (attacking == true)
            {
                cout << player.name << "�ֳ�" << player.weapon << "����" << enemy.name << "����\n\n";
                Sleep(500);
                player.SP -= 10 * weapon_choosing(player.weapon).weight;  // ��������������
                enemy.SP -= enemy_weight;  // ��������������
                if (enemy.SP < 0)
                    enemy.SP = 0;
                if (player.SP < 0)
                    player.SP = 0;

                // �Ƿ����У�    
                float hitting_random;
                hitting_random = float((rand() % 100)) / 100;
                Sleep(1000);
                if (hitting_random < dodge_chance) // ������
                {
                    cout << "�����������ˣ�\n";
                    attacking = false;
                    result = 0;
                }
                else // ����
                {
                    // ����������������
                    if (weapon_choosing(player.weapon).type == "ذ��"
                        || weapon_choosing(player.weapon).type == "���ֽ�"
                        || weapon_choosing(player.weapon).type == "���ָ�"
                        || weapon_choosing(player.weapon).type == "���ִ�"
                        || weapon_choosing(player.weapon).type == "����")
                    {
                        player.one_hand_level += 0.1 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                    }
                    if (weapon_choosing(player.weapon).type == "˫�ֽ�"
                        || weapon_choosing(player.weapon).type == "˫�ָ�"
                        || weapon_choosing(player.weapon).type == "˫�ִ�")
                    {
                        player.one_hand_level += 0.3 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                    }
                    float damage;
                    damage = (weapon_choosing(player.weapon).damage + float((rand() % 100)) / 10) * (float(100 - enemy_protection) / 100.0);
                    enemy.HP -= int(damage);
                    if (enemy.HP > 0)
                    {
                        // �������������ԣ���˼�����һ�ν������������ṩ����ң�������Ҿ���Ȩ
                        dodge_chance = ((100 + float(enemy.dodge_level - 2 * enemy_weight)) / 100) * (float(enemy.SP) / float(enemy.max_SP))
                            - ((100 + float(player.one_hand_level - 3 * weapon_choosing(player.weapon).weight)) / 100) * (float(player.SP) / float(enemy.max_SP))
                            + 0.4;
                        // �Գ���ȡֵ��Χ�ļ��ʽ�������
                        if (dodge_chance < 0)
                            dodge_chance = 0;
                        if (dodge_chance > 1)
                            dodge_chance = 1;
                        cout << "�����ɹ���";
                        cout << player.name << "�����" << int(damage) << "���˺���" << enemy.name << "ʣ��Ѫ��Ϊ" << enemy.HP << endl;
                        cout << "�з�ʣ������Ϊ" << enemy.SP << endl;
                        cout << player.name << "ʣ������Ϊ" << player.SP << endl;
                        Sleep(1000);
                        if (player.SP == 0)
                        {
                            cout << "\n�������ˡ�����������\n";
                            attacking = false;
                            result = 0;
                            break;
                        }
                        cout
                            << "\n������������������Ϊ" << (1 - dodge_chance) * 100 << "%" << endl
                            << "\n�Ƿ�������\n1.��\n2.��\n3.�鿴���״̬" << endl;

                        int attacking_choice;
                        attacking_choice = _getch();
                        while (attacking_choice != 49 && attacking_choice != 50)
                        {
                            if (attacking_choice == 51)
                                cout << "��ǰ�������ֵΪ" << player.HP << "����ǰ�������ֵΪ" << player.SP << endl;
                            attacking_choice = _getch();
                        }
                        if (attacking_choice == 50)
                        {
                            attacking = false;
                            cout << "��ѡ�������֡�" << endl;
                            result = 0;

                        }
                    }
                    if (enemy.HP <= 0)
                    {
                        result = 1;
                        attacking = false;
                        cout << player.name << "�����" << damage << "���˺���ɱ����" << enemy.name << "��";
                    }
                }
            }
        }
        if (enemy.defending == false && enemy.dodging == false)
        {
            bool attacking = true;
            while (attacking == true)
            {
                cout << player.name << "�ֳ�" << player.weapon << "����" << enemy.name << "����\n\n";
                Sleep(500);
                player.SP -= 10 * weapon_choosing(player.weapon).weight;  // ��������������
                if (player.SP < 0)
                    player.SP = 0;

                // �������������
                if (weapon_choosing(player.weapon).type == "ذ��"
                    || weapon_choosing(player.weapon).type == "���ֽ�"
                    || weapon_choosing(player.weapon).type == "���ָ�"
                    || weapon_choosing(player.weapon).type == "���ִ�"
                    || weapon_choosing(player.weapon).type == "����")
                {
                    player.one_hand_level += 0.1 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                }
                if (weapon_choosing(player.weapon).type == "˫�ֽ�"
                    || weapon_choosing(player.weapon).type == "˫�ָ�"
                    || weapon_choosing(player.weapon).type == "˫�ִ�")
                {
                    player.one_hand_level += 0.3 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                }

                float damage = (weapon_choosing(player.weapon).damage + float((rand() % 100)) / 10) * (float(100 - enemy_protection) / 100.0);
                enemy.HP -= int(damage);
                if (enemy.HP > 0)
                {
                    // �������������ԣ���˼�����һ�ν������������ṩ����ң�������Ҿ���Ȩ
                    dodge_chance = ((100 + float(enemy.dodge_level - 2 * enemy_weight)) / 100) * (float(enemy.SP) / float(enemy.max_SP))
                        - ((100 + float(player.one_hand_level - 3 * weapon_choosing(player.weapon).weight)) / 100) * (float(player.SP) / float(enemy.max_SP))
                        + 0.4;
                    // �Գ���ȡֵ��Χ�ļ��ʽ�������
                    if (dodge_chance < 0)
                        dodge_chance = 0;
                    if (dodge_chance > 1)
                        dodge_chance = 1;
                    cout << "�����ɹ���";
                    cout << player.name << "�����" << int(damage) << "���˺���" << enemy.name << "ʣ��Ѫ��Ϊ" << enemy.HP << endl;
                    cout << player.name << "ʣ������Ϊ" << player.SP << endl;
                    Sleep(1000);
                    if (player.SP == 0)
                    {
                        cout << "\n�������ˡ�����������\n";
                        attacking = false;
                        result = 0;
                        break;
                    }
                    cout
                        << "\n������������������Ϊ" << (1 - dodge_chance) * 100 << "%" << endl
                        << "\n�Ƿ�������\n1.��\n2.��\n3.�鿴���״̬" << endl;

                    int attacking_choice;
                    attacking_choice = _getch();
                    while (attacking_choice != 49 && attacking_choice != 50)
                    {
                        if (attacking_choice == 51)
                            cout << "��ǰ�������ֵΪ" << player.HP << "����ǰ�������ֵΪ" << player.SP << endl;
                        attacking_choice = _getch();
                    }
                    if (attacking_choice == 50)
                    {
                        attacking = false;
                        cout << "��ѡ�������֡�" << endl;
                        result = 0;

                    }
                }
                if (enemy.HP <= 0)
                {
                    result = 1;
                    attacking = false;
                    cout << player.name << "�����" << damage << "���˺���ɱ����" << enemy.name << "��";
                }
            }
        }
    }
    if (action == 50)
    {
        player.defending = true;
        cout << "������˸񵲣�" << endl;
        if (player.SP + 30 > player.max_SP)
        {
            if (player.SP == player.max_SP)
                cout << player.name << "������ά��������" << player.max_SP << endl;
            else
            {
                player.SP = player.max_SP;
                cout << player.name << "�ڸ��У������ָ���������" << player.max_SP << endl;
            }
        }
        else
        {
            cout << player.name << "�ڸ��У����������ָ�������+30��" << endl;
            player.SP += 30;
            cout << player.name << "�������ָ���" << player.SP << endl;
        }
    }
    if (action == 51)
    {
        if (player.SP + 50 > player.max_SP)
        {
            if (player.SP == player.max_SP)
                cout << player.name << "������ά��������" << player.max_SP << endl;
            else
            {
                player.SP = player.max_SP;
                cout << player.name << "���˿����������ָ���������" << player.max_SP << endl;
            }
        }
        else
        {
            cout << player.name << "���˿��������������ָ�������+50��" << endl;
            player.SP += 50;
            cout << player.name << "�������ָ���" << player.SP << endl;
        }
    }
    if (action == 54)
    {
        cout << "�������ˣ�\nս��������";
        result = 2;
    }

    *p_player = player;
    *p_enemy = enemy;
    return result;
}
int AI_attack(entity* p_red, entity* p_blue)
{
    int result = 0;

    entity red = *p_red;
    entity blue = *p_blue;
    
    int blue_weight = armor_choosing(blue.helmet).weight + armor_choosing(blue.armor).weight
        + armor_choosing(blue.gauntlet).weight + armor_choosing(blue.boot).weight;

    int blue_protection = armor_choosing(blue.helmet).protection + armor_choosing(blue.armor).protection
        + armor_choosing(blue.gauntlet).protection + armor_choosing(blue.boot).protection;

    float dodge_chance = calculate_dodge_chance(red, blue);

    cout << red.name << "�ĻغϿ�ʼ��" << endl;
    Sleep(1500);
    cout << red.name << " ����˼��Ӧ�� " << blue.name << " ��ս�ԡ���" << endl << endl;
    Sleep(1500);
    // AI�������
    int action = AI_decision(p_red, p_blue);

    // ���ݾ���ִ��ָ��ִ��ָ��
    if (action == 49)
    {
        if (blue.defending == true)
        {
            bool attacking = true;
            while (attacking == true)
            {
                cout << red.name << "ʹ��" << red.weapon << "����" << blue.name << "����\n";
                Sleep(2000);
                red.SP -= 10 * weapon_choosing(red.weapon).weight;  // ��������������
                if (red.SP < 0)
                    red.SP = 0;
                float block_percetage = calculate_block_percentage(red, blue);
                cout << "\ndebug:����Ч��������Ϊ��" << block_percetage << endl;
                float damage;
                damage = (weapon_choosing(red.weapon).damage + float((rand() % 100)) / 10) * (float(100 - blue_protection) / 100.0) * float(1 - block_percetage);
                blue.HP -= int(damage);
                if (blue.HP > 0)
                {
                    float dodge_chance = calculate_dodge_chance(red, blue);
                    cout << red.name << "�����" << int(damage) << "���˺���" << blue.name << "ʣ��Ѫ��Ϊ" << blue.HP << endl;
                    cout << red.name << "ʣ������Ϊ" << red.SP << endl << endl;
                    if (red.SP == 0)
                    {
                        cout << red.name << "�����ˡ�������������\n";
                        attacking = false;
                        result = 0;
                        break;
                    }
                    // AI���������ʺܵ��ҶԷ���������������
                    if (dodge_chance > 0.8 and blue.HP > 0.2 * blue.max_HP)
                    {
                        attacking = false;
                        cout << red.name << "ѡ�������֡�" << endl << endl;
                        result = 0;
                    }
                    Sleep(1000);
                }
                if (blue.HP <= 0)
                {
                    result = 1;
                    attacking = false;
                    cout << red.name << "�����" << damage << "���˺���ɱ����" << blue.name << "����";
                }
            }
        }
        if (blue.defending == false && blue.dodging == true)
        {
            bool attacking = true;
            while (attacking == true)
            {
                cout << red.name << "ʹ��" << red.weapon << "����" << blue.name << "����\n";
                Sleep(2000);
                red.SP -= 10 * weapon_choosing(red.weapon).weight;  // ��������������
                blue.SP -= blue_weight;  // ��������������
                if (blue.SP < 0)
                    blue.SP = 0;
                if (red.SP < 0)
                    red.SP = 0;
                // �Ƿ����У�
                if ((float((rand() % 100)) / 100) < dodge_chance) // ������
                {
                    cout << "�����������ˣ�\n";
                    attacking = false;
                    result = 0;
                }
                else // ����
                {
                    cout << "���У�" << endl;

                    float damage;
                    damage = (weapon_choosing(red.weapon).damage + float((rand() % 100)) / 10) * (float(100 - blue_protection) / 100.0);
                    blue.HP -= int(damage);
                    if (blue.HP > 0)
                    {
                        float dodge_chance = calculate_dodge_chance(red, blue);
                        cout << red.name << "�����" << int(damage) << "���˺���" << blue.name << "ʣ��Ѫ��Ϊ" << blue.HP << endl;
                        cout << red.name << "ʣ������Ϊ" << red.SP << endl << endl;
                        if (red.SP == 0)
                        {
                            cout << red.name << "�����ˡ�������������\n";
                            attacking = false;
                            result = 0;
                            break;
                        }
                        // AI���������ʺܵ��ҶԷ���������������
                        if (dodge_chance > 0.8 and blue.HP > 0.2 * blue.max_HP)
                        {
                            attacking = false;
                            cout << red.name << "ѡ�������֡�" << endl << endl;
                            result = 0;
                        }
                        Sleep(1000);
                    }
                    if (blue.HP <= 0)
                    {
                        result = 1;
                        attacking = false;
                        cout << red.name << "�����" << damage << "���˺���ɱ����" << blue.name << "����";
                    }
                }
            }
        }
        if (blue.defending == false && blue.dodging == false)
        {
            bool attacking = true;
            while (attacking == true)
            {
                cout << red.name << "ʹ��" << red.weapon << "����" << blue.name << "����\n";
                Sleep(2000);
                red.SP -= 10 * weapon_choosing(red.weapon).weight;  // ��������������
                if (red.SP < 0)
                    red.SP = 0;
                float damage;
                damage = (weapon_choosing(red.weapon).damage + float((rand() % 100)) / 10) * (float(100 - blue_protection) / 100.0);
                blue.HP -= int(damage);
                if (blue.HP > 0)
                {
                    float dodge_chance = calculate_dodge_chance(red, blue);
                    cout << red.name << "�����" << int(damage) << "���˺���" << blue.name << "ʣ��Ѫ��Ϊ" << blue.HP << endl;
                    cout << red.name << "ʣ������Ϊ" << red.SP << endl << endl;
                    if (red.SP == 0)
                    {
                        cout << red.name << "�����ˡ�������������\n";
                        attacking = false;
                        result = 0;
                        break;
                    }
                    // AI���������ʺܵ��ҶԷ���������������
                    if (dodge_chance > 0.8 and blue.HP > 0.2 * blue.max_HP)
                    {
                        attacking = false;
                        cout << red.name << "ѡ�������֡�" << endl << endl;
                        result = 0;
                    }
                    Sleep(1000);
                }
                if (blue.HP <= 0)
                {
                    result = 1;
                    attacking = false;
                    cout << red.name << "�����" << damage << "���˺���ɱ����" << blue.name << "����";
                }

            }
        }


    }
    if (action == 50)
    {
        red.defending = true;
        cout << red.name << "�����˸񵲣�" << endl;
        if (red.SP + 30 > red.max_SP)
        {
            if (red.SP == red.max_SP)
                cout << red.name << "������ά��������" << red.max_SP << endl;
            else
            {
                red.SP = red.max_SP;
                cout << red.name << "�ڸ��У������ָ���������" << red.max_SP << endl;
            }
        }
        else
        {
            cout << red.name << "�ڸ��У����������ָ�������+30��" << endl;
            red.SP += 30;
            cout << red.name << "�������ָ���" << red.SP << endl;
        }
    }
    if (action == 51)
    {
        if (red.SP + 50 > red.max_SP)
        {
            if (red.SP == red.max_SP)
                cout << red.name << "������ά��������" << red.max_SP << endl;
            else
            {
                red.SP = red.max_SP;
                cout << red.name << "���˿����������ָ���������" << red.max_SP << endl;
            }
        }
        else
        {
            cout << red.name << "���˿��������������ָ�������+50��";
            red.SP += 50;
            cout << red.name << "�������ָ���" << red.SP << endl;
        }
    }
    if (action == 53)
    {
        cout << red.name << " ���������ͼ���ܣ�" << endl;
        if (blue.courage >= 2)
        {
            cout << blue.name << "��ͼ׷������" << endl;
            float dodge_chance = calculate_dodge_chance(blue, red);
            cout << "������Ϊ" << (1 - dodge_chance) * 100 << "%\n" << endl;
        }
        else
        {
            cout << blue.name << "��������" << red.name << endl;
        }


        Sleep(1000);
        // �Ƿ����У�
        if ((float((rand() % 100)) / 100) < dodge_chance)
        {
            // ������
            cout << "�����������ˣ�\n" << red.name << "���ܳɹ���\n";
        }
        else // ����
        {
            cout << "�������У�" << endl;
            float damage;
            damage = weapon_choosing(red.weapon).damage + float((rand() % 100)) / 10;
            red.HP -= int(damage);
            if (blue.HP > 0)
            {
                cout << blue.name << "�����" << int(damage) << "���˺���" << red.name << "ʣ��Ѫ��Ϊ" << red.HP << endl;
                cout << blue.name << "û��ɱ��" << red.name << "�����ܳɹ��ˣ�" << endl;
            }
            if (blue.HP <= 0)
            {
                cout << blue.name << "�����" << damage << "���˺���ɱ����" << red.name << "��\n�Ͼ�ɱ����ս��ʤ����";
            }
        }
        result = 2;

    }
    
    *p_blue = blue;
    *p_red = red;
    return result;
}

bool batte_player(entity player, entity enemy)
{
    system("cls");
    printlogo();
    cout << "ս�������С���";
    Sleep(2000);
    system("cls");
    // �����������
    srand(long(time(0)));

    Sleep(1000);
    int round = 1;
    bool gameover = false;
    bool win;
    cout << player.name << " ���� " << enemy.name << endl;
    if (player.dodging == true)
        cout << "��ǰ����Զ�����״̬�ǣ�����\n";
    else
        cout << "��ǰ����Զ�����״̬�ǣ��ر�\n";
    if (enemy.dodging == true)
        cout << "��ǰ���˵��Զ�����״̬�ǣ�����\n";
    else
        cout << "��ǰ���˵��Զ�����״̬�ǣ��ر�\n\n\n";
    Sleep(1000);
    float temp_one_hand_level = player.one_hand_level;

    if (player.dodge_level >= enemy.dodge_level)
    {
        cout << player.name << "�����ݼ����ƺ���ʤһ�ȡ�������֣�\n";
        while (gameover == false)
        {
            Sleep(1000);
            
            entity* p_player = &player;
            entity* p_enemy = &enemy;
            int result = player_attack(p_player, p_enemy);
            if (result == 1)
            {
                gameover = true;
                win = true;
                break;
            }
            if (result == 2)
            {
                gameover = true;
                win = false;
                break;
            }

            entity* p_red = p_enemy;
            entity* p_blue = p_player;
            result = AI_attack(p_red, p_blue);
            if (result == 1)
            {
                gameover = true;
                win = false;
            }
            if (result == 2)
            {
                gameover = true;
                win = true;
            }
        }
    }
    else
    {
        cout << enemy.name << "�����ݼ����ƺ���ʤһ�ȡ�������֣�\n";
        while (gameover == false)
        {

            entity* p_red = &enemy;
            entity* p_blue = &player;
            int result = AI_attack(p_red, p_blue);

            if (result == 1)
            {
                win = false;
                break;
            }
            if (result == 2)
            {
                win = true;
                break;
            }

            Sleep(1000);
            entity* p_player = p_blue;
            entity* p_enemy = p_red;
            result = player_attack(p_player, p_enemy);

            if (result == 1)
            {
                gameover = true;
                win = true;
            }
            if (result == 2)
            {
                gameover = true;
                win = false;
            }
        }
    }
    if (win == true);
    {
        cout << "\n����Enter������";
        cin.get();
        Sleep(1000);
        system("cls");
    }
    return win;
}