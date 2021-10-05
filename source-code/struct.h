// 这里是头文件，储存了一些必要的结构体，以供调用
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
    int courage; // 衡量一个实体的战斗欲望，决定它的AI
    bool defending; // 是否正在格挡
    bool dodging;  // 是否正在自动闪避
};

struct weapon
{
    string name;
    string description;
    string type;
    bool human;  // 是否是人型生物持有的武器
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
