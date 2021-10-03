#pragma once
#include <string>
using namespace std;

struct entity
{
    string name;
    bool human;
    int HP, MP, SP;
    int max_HP, max_MP, max_SP;
    int one_hand_level, two_hand_level, block_level, dodge_level;
    string weapon;
    string left_hand;
    string helmet;
    string armor;
    string gauntlet;
    string boot;
    int courage;
};

struct weapon
{
    string name;
    string description;
    string type;
    bool human;
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
