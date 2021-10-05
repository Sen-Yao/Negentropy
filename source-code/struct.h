// ������ͷ�ļ���������һЩ��Ҫ�Ľṹ�壬�Թ�����
#pragma once
#include <string>
using namespace std;

struct entity
{
    string name;
    bool human;
    float HP, MP, SP;
    float max_HP, max_MP, max_SP;
    float one_hand_level, two_hand_level, block_level, dodge_level;
    string weapon;
    string left_hand;
    string helmet;
    string armor;
    string gauntlet;
    string boot;
    int courage; // ����һ��ʵ���ս����������������AI
    bool defending; // �Ƿ����ڸ�
    bool dodging;  // �Ƿ������Զ�����
};

struct weapon
{
    string name;
    string description;
    string type;
    bool human;  // �Ƿ�������������е�����
    int damage;
    int weight;
    int value;
    bool sharp;
    string buff;
};

struct armor
{
    string name;
    string part;
    int protection;
    int weight;
    int value;
    string buff;
};
