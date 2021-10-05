// 此文件目前共有六个函数
// 其中前两个用于计算闪避率和格挡减伤率
// 第三个是AI做决策函数，输入两个实体的状态，输出一个整数，代表AI做出的结果
// 再后面两个分别表示玩家的一个回合，和AI操控的一个回合
// 最后一个函数代表玩家和AI对战的函数
// 以后战斗相关的函数都放在这个文件里，按照嵌套顺序排序
// 约定：以下的对象命名中，red代表主动方/进攻方/有行动权方，blue代表被动方/防守方/无行动方
// 但是玩家和AI的战斗中，用player和enemy替代（历史遗留问题）（可以考虑统一）

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

    if (weapon_choosing(red.weapon).type == "匕首"
        || weapon_choosing(red.weapon).type == "单手剑"
        || weapon_choosing(red.weapon).type == "单手斧"
        || weapon_choosing(red.weapon).type == "单手锤"
        || weapon_choosing(red.weapon).type == "其他")
    {
        dodge_chance = ((100 + float(blue.dodge_level - 2 * blue_weight)) / 100) * float(blue.SP) / float(blue.max_SP)
            - 2 * ((100 + float(0.8 * red.one_hand_level - 4.0 * float(weapon_choosing(red.weapon).weight))) / 100) * float(red.SP) / float(red.max_SP)
            + 0.8;
    }
    if (weapon_choosing(red.weapon).type == "双手剑"
        || weapon_choosing(red.weapon).type == "双手斧"
        || weapon_choosing(red.weapon).type == "双手锤")
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

    if (weapon_choosing(red.weapon).type == "匕首"
        || weapon_choosing(red.weapon).type == "单手剑"
        || weapon_choosing(red.weapon).type == "单手斧"
        || weapon_choosing(red.weapon).type == "单手锤"
        || weapon_choosing(red.weapon).type == "其他")
    {
        block_percentage = 0.5 * ((float(100 + 4 * blue.block_level + 10) * float(blue.SP / blue.max_SP) / 100)
            - (float(100 + 5 * weapon_choosing(red.weapon).weight + 4 * red.one_hand_level) * float(red.SP / red.max_SP) / 100)
            + 1);
    }
    if (weapon_choosing(red.weapon).type == "双手剑"
        || weapon_choosing(red.weapon).type == "双手斧"
        || weapon_choosing(red.weapon).type == "双手锤")
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
    // 红方不同的勇气等级，会让他们做出不同反应。
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
    int result = 0;  // result指的是这回合结束后，战斗的结果。0代表继续战斗，1代表对方死亡，2代表己方逃跑
    entity player = *p_player;
    entity enemy = *p_enemy;

    int enemy_weight = armor_choosing(enemy.helmet).weight + armor_choosing(enemy.armor).weight
        + armor_choosing(enemy.gauntlet).weight + armor_choosing(enemy.boot).weight;

    int enemy_protection = armor_choosing(enemy.helmet).protection + armor_choosing(enemy.armor).protection
        + armor_choosing(enemy.gauntlet).protection + armor_choosing(enemy.boot).protection;

    float dodge_chance = calculate_dodge_chance(player, enemy);
    
    player.defending = false;

    cout << "\n\n你的回合！\n"
        << "当前你的生命值为" << player.HP << "， 耐力值为" << player.SP << endl
        <<"\n请选择你的行为\n";

    if (player.dodging == true)
        cout << "当前你的自动闪避状态是：开启\n";
    else
        cout << "当前你的自动闪避状态是：关闭\n";

    cout << "\n1.进攻！\n2.架起格挡！\n3.稍作休息\n4.打开物品栏……（功能未实现）\n5.开关自动闪避\n5.逃跑\n" << endl;
    cout << "（若你现在攻击，命中率为" << (1 - dodge_chance) * 100 << "%）\n" << endl;

    int action;
    action = _getch();
    while (action != 49 && action != 50 && action != 51 && action != 52 && action != 54)
    {
        if (action == 53)
        {
            if (player.dodging == true)
            {
                cout << "\n自动闪避已关闭\n";
                player.dodging = false;
            }
            else
            {
                cout << "\n自动闪避已开启\n";
                player.dodging = true;
            }
        }
        action = _getch();
    }
    if (action == 49)
    {
        if (enemy.defending == true)  // 若敌人此时正在格挡
        {
            bool attacking = true;
            while (attacking == true)
            {
                cout << player.name << "手持" << player.weapon << "挥向" << enemy.name << "……\n\n";
                Sleep(500);
                player.SP -= 10 * weapon_choosing(player.weapon).weight;  // 进攻者耐力减少
                if (player.SP < 0)
                    player.SP = 0;

                    // 玩家熟练度上升
                    if (weapon_choosing(player.weapon).type == "匕首"
                        || weapon_choosing(player.weapon).type == "单手剑"
                        || weapon_choosing(player.weapon).type == "单手斧"
                        || weapon_choosing(player.weapon).type == "单手锤"
                        || weapon_choosing(player.weapon).type == "其他")
                    {
                        player.one_hand_level += 0.1 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                    }
                    if (weapon_choosing(player.weapon).type == "双手剑"
                        || weapon_choosing(player.weapon).type == "双手斧"
                        || weapon_choosing(player.weapon).type == "双手锤")
                    {
                        player.one_hand_level += 0.3 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                    }

                    float block_percetage = calculate_block_percentage(player, enemy);
                    cout << "\ndebug:减伤率为：" << block_percetage << endl;
                    float damage = (weapon_choosing(player.weapon).damage + float((rand() % 100)) / 10) * (float(100 - enemy_protection) / 100.0) * float(1 - block_percetage);
                    enemy.HP -= int(damage);
                    if (enemy.HP > 0)
                    {
                        // 存在连击可能性，因此计算下一次进攻的命中率提供给玩家，交给玩家决定权
                        dodge_chance = ((100 + float(enemy.dodge_level - 2 * enemy_weight)) / 100) * (float(enemy.SP) / float(enemy.max_SP))
                            - ((100 + float(player.one_hand_level - 3 * weapon_choosing(player.weapon).weight)) / 100) * (float(player.SP) / float(enemy.max_SP))
                            + 0.4;
                        // 对超出取值范围的几率进行修正
                        if (dodge_chance < 0)
                            dodge_chance = 0;
                        if (dodge_chance > 1)
                            dodge_chance = 1;
                        cout << "连击成功！";
                        cout << player.name << "造成了" << int(damage) << "点伤害！" << enemy.name << "剩余血量为" << enemy.HP << endl;
                        cout << player.name << "剩余耐力为" << player.SP << endl;
                        Sleep(1000);
                        if (player.SP == 0)
                        {
                            cout << "\n你力竭了……连击结束\n";
                            attacking = false;
                            result = 0;
                            break;
                        }
                        cout
                            << "\n若进行连击，命中率为" << (1 - dodge_chance) * 100 << "%" << endl
                            << "\n是否连击？\n1.是\n2.否\n3.查看玩家状态" << endl;

                        int attacking_choice;
                        attacking_choice = _getch();
                        while (attacking_choice != 49 && attacking_choice != 50)
                        {
                            if (attacking_choice == 51)
                                cout << "当前玩家生命值为" << player.HP << "，当前玩家耐力值为" << player.SP << endl;
                            attacking_choice = _getch();
                        }
                        if (attacking_choice == 50)
                        {
                            attacking = false;
                            cout << "你选择了收手。" << endl;
                            result = 0;

                        }
                    }
                    if (enemy.HP <= 0)
                    {
                        result = 1;
                        attacking = false;
                        cout << player.name << "造成了" << damage << "点伤害！杀死了" << enemy.name << "！";
                    }
                    
                }
            }
        if (enemy.defending == false && enemy.dodging == true)
        {
            // 连击判定
            bool attacking = true;
            while (attacking == true)
            {
                cout << player.name << "手持" << player.weapon << "挥向" << enemy.name << "……\n\n";
                Sleep(500);
                player.SP -= 10 * weapon_choosing(player.weapon).weight;  // 进攻者耐力减少
                enemy.SP -= enemy_weight;  // 躲闪者耐力减少
                if (enemy.SP < 0)
                    enemy.SP = 0;
                if (player.SP < 0)
                    player.SP = 0;

                // 是否命中？    
                float hitting_random;
                hitting_random = float((rand() % 100)) / 100;
                Sleep(1000);
                if (hitting_random < dodge_chance) // 不命中
                {
                    cout << "攻击被闪避了！\n";
                    attacking = false;
                    result = 0;
                }
                else // 命中
                {
                    // 进攻方熟练度上升
                    if (weapon_choosing(player.weapon).type == "匕首"
                        || weapon_choosing(player.weapon).type == "单手剑"
                        || weapon_choosing(player.weapon).type == "单手斧"
                        || weapon_choosing(player.weapon).type == "单手锤"
                        || weapon_choosing(player.weapon).type == "其他")
                    {
                        player.one_hand_level += 0.1 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                    }
                    if (weapon_choosing(player.weapon).type == "双手剑"
                        || weapon_choosing(player.weapon).type == "双手斧"
                        || weapon_choosing(player.weapon).type == "双手锤")
                    {
                        player.one_hand_level += 0.3 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                    }
                    float damage;
                    damage = (weapon_choosing(player.weapon).damage + float((rand() % 100)) / 10) * (float(100 - enemy_protection) / 100.0);
                    enemy.HP -= int(damage);
                    if (enemy.HP > 0)
                    {
                        // 存在连击可能性，因此计算下一次进攻的命中率提供给玩家，交给玩家决定权
                        dodge_chance = ((100 + float(enemy.dodge_level - 2 * enemy_weight)) / 100) * (float(enemy.SP) / float(enemy.max_SP))
                            - ((100 + float(player.one_hand_level - 3 * weapon_choosing(player.weapon).weight)) / 100) * (float(player.SP) / float(enemy.max_SP))
                            + 0.4;
                        // 对超出取值范围的几率进行修正
                        if (dodge_chance < 0)
                            dodge_chance = 0;
                        if (dodge_chance > 1)
                            dodge_chance = 1;
                        cout << "连击成功！";
                        cout << player.name << "造成了" << int(damage) << "点伤害！" << enemy.name << "剩余血量为" << enemy.HP << endl;
                        cout << "敌方剩余耐力为" << enemy.SP << endl;
                        cout << player.name << "剩余耐力为" << player.SP << endl;
                        Sleep(1000);
                        if (player.SP == 0)
                        {
                            cout << "\n你力竭了……连击结束\n";
                            attacking = false;
                            result = 0;
                            break;
                        }
                        cout
                            << "\n若进行连击，命中率为" << (1 - dodge_chance) * 100 << "%" << endl
                            << "\n是否连击？\n1.是\n2.否\n3.查看玩家状态" << endl;

                        int attacking_choice;
                        attacking_choice = _getch();
                        while (attacking_choice != 49 && attacking_choice != 50)
                        {
                            if (attacking_choice == 51)
                                cout << "当前玩家生命值为" << player.HP << "，当前玩家耐力值为" << player.SP << endl;
                            attacking_choice = _getch();
                        }
                        if (attacking_choice == 50)
                        {
                            attacking = false;
                            cout << "你选择了收手。" << endl;
                            result = 0;

                        }
                    }
                    if (enemy.HP <= 0)
                    {
                        result = 1;
                        attacking = false;
                        cout << player.name << "造成了" << damage << "点伤害！杀死了" << enemy.name << "！";
                    }
                }
            }
        }
        if (enemy.defending == false && enemy.dodging == false)
        {
            bool attacking = true;
            while (attacking == true)
            {
                cout << player.name << "手持" << player.weapon << "挥向" << enemy.name << "……\n\n";
                Sleep(500);
                player.SP -= 10 * weapon_choosing(player.weapon).weight;  // 进攻者耐力减少
                if (player.SP < 0)
                    player.SP = 0;

                // 玩家熟练度上升
                if (weapon_choosing(player.weapon).type == "匕首"
                    || weapon_choosing(player.weapon).type == "单手剑"
                    || weapon_choosing(player.weapon).type == "单手斧"
                    || weapon_choosing(player.weapon).type == "单手锤"
                    || weapon_choosing(player.weapon).type == "其他")
                {
                    player.one_hand_level += 0.1 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                }
                if (weapon_choosing(player.weapon).type == "双手剑"
                    || weapon_choosing(player.weapon).type == "双手斧"
                    || weapon_choosing(player.weapon).type == "双手锤")
                {
                    player.one_hand_level += 0.3 * (dodge_chance + 0.3) * (100 / player.one_hand_level);
                }

                float damage = (weapon_choosing(player.weapon).damage + float((rand() % 100)) / 10) * (float(100 - enemy_protection) / 100.0);
                enemy.HP -= int(damage);
                if (enemy.HP > 0)
                {
                    // 存在连击可能性，因此计算下一次进攻的命中率提供给玩家，交给玩家决定权
                    dodge_chance = ((100 + float(enemy.dodge_level - 2 * enemy_weight)) / 100) * (float(enemy.SP) / float(enemy.max_SP))
                        - ((100 + float(player.one_hand_level - 3 * weapon_choosing(player.weapon).weight)) / 100) * (float(player.SP) / float(enemy.max_SP))
                        + 0.4;
                    // 对超出取值范围的几率进行修正
                    if (dodge_chance < 0)
                        dodge_chance = 0;
                    if (dodge_chance > 1)
                        dodge_chance = 1;
                    cout << "连击成功！";
                    cout << player.name << "造成了" << int(damage) << "点伤害！" << enemy.name << "剩余血量为" << enemy.HP << endl;
                    cout << player.name << "剩余耐力为" << player.SP << endl;
                    Sleep(1000);
                    if (player.SP == 0)
                    {
                        cout << "\n你力竭了……连击结束\n";
                        attacking = false;
                        result = 0;
                        break;
                    }
                    cout
                        << "\n若进行连击，命中率为" << (1 - dodge_chance) * 100 << "%" << endl
                        << "\n是否连击？\n1.是\n2.否\n3.查看玩家状态" << endl;

                    int attacking_choice;
                    attacking_choice = _getch();
                    while (attacking_choice != 49 && attacking_choice != 50)
                    {
                        if (attacking_choice == 51)
                            cout << "当前玩家生命值为" << player.HP << "，当前玩家耐力值为" << player.SP << endl;
                        attacking_choice = _getch();
                    }
                    if (attacking_choice == 50)
                    {
                        attacking = false;
                        cout << "你选择了收手。" << endl;
                        result = 0;

                    }
                }
                if (enemy.HP <= 0)
                {
                    result = 1;
                    attacking = false;
                    cout << player.name << "造成了" << damage << "点伤害！杀死了" << enemy.name << "！";
                }
            }
        }
    }
    if (action == 50)
    {
        player.defending = true;
        cout << "你架起了格挡！" << endl;
        if (player.SP + 30 > player.max_SP)
        {
            if (player.SP == player.max_SP)
                cout << player.name << "的耐力维持在上限" << player.max_SP << endl;
            else
            {
                player.SP = player.max_SP;
                cout << player.name << "在格挡中，耐力恢复到了上限" << player.max_SP << endl;
            }
        }
        else
        {
            cout << player.name << "在格挡中，耐力有所恢复（耐力+30）" << endl;
            player.SP += 30;
            cout << player.name << "的耐力恢复到" << player.SP << endl;
        }
    }
    if (action == 51)
    {
        if (player.SP + 50 > player.max_SP)
        {
            if (player.SP == player.max_SP)
                cout << player.name << "的耐力维持在上限" << player.max_SP << endl;
            else
            {
                player.SP = player.max_SP;
                cout << player.name << "喘了口气，耐力恢复到了上限" << player.max_SP << endl;
            }
        }
        else
        {
            cout << player.name << "喘了口气，耐力有所恢复（耐力+50）" << endl;
            player.SP += 50;
            cout << player.name << "的耐力恢复到" << player.SP << endl;
        }
    }
    if (action == 54)
    {
        cout << "你逃跑了！\n战斗结束！";
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

    cout << red.name << "的回合开始。" << endl;
    Sleep(1500);
    cout << red.name << " 正在思考应对 " << blue.name << " 的战略……" << endl << endl;
    Sleep(1500);
    // AI计算决策
    int action = AI_decision(p_red, p_blue);

    // 根据决策执行指令执行指令
    if (action == 49)
    {
        if (blue.defending == true)
        {
            bool attacking = true;
            while (attacking == true)
            {
                cout << red.name << "使用" << red.weapon << "挥向" << blue.name << "……\n";
                Sleep(2000);
                red.SP -= 10 * weapon_choosing(red.weapon).weight;  // 进攻者耐力减少
                if (red.SP < 0)
                    red.SP = 0;
                float block_percetage = calculate_block_percentage(red, blue);
                cout << "\ndebug:格挡生效！减伤率为：" << block_percetage << endl;
                float damage;
                damage = (weapon_choosing(red.weapon).damage + float((rand() % 100)) / 10) * (float(100 - blue_protection) / 100.0) * float(1 - block_percetage);
                blue.HP -= int(damage);
                if (blue.HP > 0)
                {
                    float dodge_chance = calculate_dodge_chance(red, blue);
                    cout << red.name << "造成了" << int(damage) << "点伤害！" << blue.name << "剩余血量为" << blue.HP << endl;
                    cout << red.name << "剩余耐力为" << red.SP << endl << endl;
                    if (red.SP == 0)
                    {
                        cout << red.name << "力竭了……连击结束。\n";
                        attacking = false;
                        result = 0;
                        break;
                    }
                    // AI：若命中率很低且对方健康，放弃连击
                    if (dodge_chance > 0.8 and blue.HP > 0.2 * blue.max_HP)
                    {
                        attacking = false;
                        cout << red.name << "选择了收手。" << endl << endl;
                        result = 0;
                    }
                    Sleep(1000);
                }
                if (blue.HP <= 0)
                {
                    result = 1;
                    attacking = false;
                    cout << red.name << "造成了" << damage << "点伤害！杀死了" << blue.name << "……";
                }
            }
        }
        if (blue.defending == false && blue.dodging == true)
        {
            bool attacking = true;
            while (attacking == true)
            {
                cout << red.name << "使用" << red.weapon << "挥向" << blue.name << "……\n";
                Sleep(2000);
                red.SP -= 10 * weapon_choosing(red.weapon).weight;  // 进攻者耐力减少
                blue.SP -= blue_weight;  // 躲闪者耐力减少
                if (blue.SP < 0)
                    blue.SP = 0;
                if (red.SP < 0)
                    red.SP = 0;
                // 是否命中？
                if ((float((rand() % 100)) / 100) < dodge_chance) // 不命中
                {
                    cout << "攻击被闪避了！\n";
                    attacking = false;
                    result = 0;
                }
                else // 命中
                {
                    cout << "命中！" << endl;

                    float damage;
                    damage = (weapon_choosing(red.weapon).damage + float((rand() % 100)) / 10) * (float(100 - blue_protection) / 100.0);
                    blue.HP -= int(damage);
                    if (blue.HP > 0)
                    {
                        float dodge_chance = calculate_dodge_chance(red, blue);
                        cout << red.name << "造成了" << int(damage) << "点伤害！" << blue.name << "剩余血量为" << blue.HP << endl;
                        cout << red.name << "剩余耐力为" << red.SP << endl << endl;
                        if (red.SP == 0)
                        {
                            cout << red.name << "力竭了……连击结束。\n";
                            attacking = false;
                            result = 0;
                            break;
                        }
                        // AI：若命中率很低且对方健康，放弃连击
                        if (dodge_chance > 0.8 and blue.HP > 0.2 * blue.max_HP)
                        {
                            attacking = false;
                            cout << red.name << "选择了收手。" << endl << endl;
                            result = 0;
                        }
                        Sleep(1000);
                    }
                    if (blue.HP <= 0)
                    {
                        result = 1;
                        attacking = false;
                        cout << red.name << "造成了" << damage << "点伤害！杀死了" << blue.name << "……";
                    }
                }
            }
        }
        if (blue.defending == false && blue.dodging == false)
        {
            bool attacking = true;
            while (attacking == true)
            {
                cout << red.name << "使用" << red.weapon << "挥向" << blue.name << "……\n";
                Sleep(2000);
                red.SP -= 10 * weapon_choosing(red.weapon).weight;  // 进攻者耐力减少
                if (red.SP < 0)
                    red.SP = 0;
                float damage;
                damage = (weapon_choosing(red.weapon).damage + float((rand() % 100)) / 10) * (float(100 - blue_protection) / 100.0);
                blue.HP -= int(damage);
                if (blue.HP > 0)
                {
                    float dodge_chance = calculate_dodge_chance(red, blue);
                    cout << red.name << "造成了" << int(damage) << "点伤害！" << blue.name << "剩余血量为" << blue.HP << endl;
                    cout << red.name << "剩余耐力为" << red.SP << endl << endl;
                    if (red.SP == 0)
                    {
                        cout << red.name << "力竭了……连击结束。\n";
                        attacking = false;
                        result = 0;
                        break;
                    }
                    // AI：若命中率很低且对方健康，放弃连击
                    if (dodge_chance > 0.8 and blue.HP > 0.2 * blue.max_HP)
                    {
                        attacking = false;
                        cout << red.name << "选择了收手。" << endl << endl;
                        result = 0;
                    }
                    Sleep(1000);
                }
                if (blue.HP <= 0)
                {
                    result = 1;
                    attacking = false;
                    cout << red.name << "造成了" << damage << "点伤害！杀死了" << blue.name << "……";
                }

            }
        }


    }
    if (action == 50)
    {
        red.defending = true;
        cout << red.name << "架起了格挡！" << endl;
        if (red.SP + 30 > red.max_SP)
        {
            if (red.SP == red.max_SP)
                cout << red.name << "的耐力维持在上限" << red.max_SP << endl;
            else
            {
                red.SP = red.max_SP;
                cout << red.name << "在格挡中，耐力恢复到了上限" << red.max_SP << endl;
            }
        }
        else
        {
            cout << red.name << "在格挡中，耐力有所恢复（耐力+30）" << endl;
            red.SP += 30;
            cout << red.name << "的耐力恢复到" << red.SP << endl;
        }
    }
    if (action == 51)
    {
        if (red.SP + 50 > red.max_SP)
        {
            if (red.SP == red.max_SP)
                cout << red.name << "的耐力维持在上限" << red.max_SP << endl;
            else
            {
                red.SP = red.max_SP;
                cout << red.name << "喘了口气，耐力恢复到了上限" << red.max_SP << endl;
            }
        }
        else
        {
            cout << red.name << "喘了口气，耐力有所恢复（耐力+50）";
            red.SP += 50;
            cout << red.name << "的耐力恢复到" << red.SP << endl;
        }
    }
    if (action == 53)
    {
        cout << red.name << " 见机不妙，试图逃跑！" << endl;
        if (blue.courage >= 2)
        {
            cout << blue.name << "试图追击……" << endl;
            float dodge_chance = calculate_dodge_chance(blue, red);
            cout << "命中率为" << (1 - dodge_chance) * 100 << "%\n" << endl;
        }
        else
        {
            cout << blue.name << "决定放走" << red.name << endl;
        }


        Sleep(1000);
        // 是否命中？
        if ((float((rand() % 100)) / 100) < dodge_chance)
        {
            // 不命中
            cout << "攻击被闪避了！\n" << red.name << "逃跑成功！\n";
        }
        else // 命中
        {
            cout << "攻击命中！" << endl;
            float damage;
            damage = weapon_choosing(red.weapon).damage + float((rand() % 100)) / 10;
            red.HP -= int(damage);
            if (blue.HP > 0)
            {
                cout << blue.name << "造成了" << int(damage) << "点伤害！" << red.name << "剩余血量为" << red.HP << endl;
                cout << blue.name << "没能杀死" << red.name << "，逃跑成功了！" << endl;
            }
            if (blue.HP <= 0)
            {
                cout << blue.name << "造成了" << damage << "点伤害！杀死了" << red.name << "！\n赶尽杀绝，战斗胜利！";
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
    cout << "战斗加载中……";
    Sleep(2000);
    system("cls");
    // 随机数生成器
    srand(long(time(0)));

    Sleep(1000);
    int round = 1;
    bool gameover = false;
    bool win;
    cout << player.name << " 对阵 " << enemy.name << endl;
    if (player.dodging == true)
        cout << "当前你的自动闪避状态是：开启\n";
    else
        cout << "当前你的自动闪避状态是：关闭\n";
    if (enemy.dodging == true)
        cout << "当前敌人的自动闪避状态是：开启\n";
    else
        cout << "当前敌人的自动闪避状态是：关闭\n\n\n";
    Sleep(1000);
    float temp_one_hand_level = player.one_hand_level;

    if (player.dodge_level >= enemy.dodge_level)
    {
        cout << player.name << "的敏捷技能似乎更胜一筹，取得了先手！\n";
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
        cout << enemy.name << "的敏捷技能似乎更胜一筹，取得了先手！\n";
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
        cout << "\n按下Enter继续！";
        cin.get();
        Sleep(1000);
        system("cls");
    }
    return win;
}