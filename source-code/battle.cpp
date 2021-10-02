// 此文件内置三个函数，用于进行战斗
// 其中，player_attack是玩家攻击敌人的过程，AI_attack是敌人攻击玩家/其他AI的过程
// 最终用player_vs_AI和AI_vs_AI进行封装，提供给主程序
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

entity player_attack(entity player, entity enemy)
{
    bool gameover = false;
    int enemy_weight = armor_choosing(enemy.helmet).weight + armor_choosing(enemy.armor).weight
        + armor_choosing(enemy.gauntlet).weight + armor_choosing(enemy.boot).weight;
    cout << "\n你先攻击。\n请选择你的行为";
    cout << "\n1.进攻！\n2.架起格挡！(功能未实现）\n3.稍作休息\n4.打开物品栏……（功能未实现）\n5.逃跑\n" << endl;
    float dodge_chance;
    dodge_chance = ((100 + float(enemy.dodge_level - 2 * enemy_weight)) / 100) * (enemy.SP / enemy.max_SP)
        - ((100 + float(player.one_hand_level - 4 * weapon_choosing(player.weapon).weight)) / 100) * (player.SP / enemy.max_SP)
        + 0.4;
    // 对超出取值范围的几率进行修正
    if (dodge_chance < 0)
    {
        dodge_chance = 0;
    }
    if (dodge_chance > 1)
    {
        dodge_chance = 1;
    }
    cout << "（若你现在攻击，命中率为" << (1 - dodge_chance) * 100 << "%）" << endl;

    int action;
    action = _getch();

    if (action == 49)
    {
        // 连击判定
        bool attacking = true;
        while (attacking == true)
        {
            cout << player.name << "手持" << player.weapon << "挥向" << enemy.name << "……\n\n";
            Sleep(1000);
            player.SP -= 6 * weapon_choosing(player.weapon).weight;  // 进攻者耐力减少
            enemy.SP -= enemy_weight;  // 躲闪者耐力减少


            // 是否命中？    
            float hitting_random;
            hitting_random = float((rand() % 100)) / 100;
            cout << "Debug: 上一次进攻的随机数为： " << hitting_random
                << "，闪避率为" << dodge_chance << endl
                << hitting_random << ">" << dodge_chance << "才能进入连击" << endl;
            Sleep(2000);
            if (hitting_random < dodge_chance) // 不命中
            {
                cout << "攻击被闪避了！\n";
                attacking = false;
            }
            else // 命中
            {
                // 计算伤害并扣血
                float damage;
                damage = weapon_choosing(player.weapon).damage + float((rand() % 100)) / 10;
                enemy.HP -= int(damage);
                if (enemy.HP > 0)
                {
                    // 存在连击可能性，因此计算下一次进攻的命中率提供给玩家，交给玩家决定权
                    dodge_chance = ((100 + float(enemy.dodge_level - 2 * enemy_weight)) / 100) * (float(enemy.SP) / float(enemy.max_SP))
                        - ((100 + float(player.one_hand_level - 3 * weapon_choosing(player.weapon).weight)) / 100) * (float(player.SP) / float(enemy.max_SP))
                        + 0.4;
                    // 对超出取值范围的几率进行修正
                    if (dodge_chance < 0)
                    {
                        dodge_chance = 0;
                    }
                    if (dodge_chance > 1)
                    {
                        dodge_chance = 1;
                    }
                    cout << player.name << "造成了" << int(damage) << "点伤害！" << enemy.name << "剩余血量为" << enemy.HP << endl;
                    cout << "敌方剩余耐力为" << enemy.SP << endl;
                    cout << player.name << "剩余耐力为" << player.SP << endl
                        << "\n若进行连击，命中率为" << (1 - dodge_chance) * 100 << "%" << endl
                        << "\n是否连击？\n1.是\n2.否\n" << endl;

                    int attacking_choice;
                    attacking_choice = _getch();
                    if (attacking_choice == 50)
                    {
                        attacking = false;
                        cout << "你选择了收手。" << endl;
                    }
                    cout << "Debug:连击，命中率为" << (1 - dodge_chance) * 100 << "%" << endl;
                }
                cout << "Debug:连击，命中率为" << (1 - dodge_chance) * 100 << "%" << endl;
                if (enemy.HP <= 0)
                {
                    gameover = true;
                    attacking = false;
                    cout << player.name << "造成了" << damage << "点伤害！杀死了" << enemy.name << "！战斗胜利！";
                }

            }
        }
    }
    if (action == 51)
    {
        if (player.SP + 50 > player.max_SP)
        {
            player.SP = player.max_SP;
            cout << player.name << "喘了口气，耐力恢复到了上限" << player.SP;
        }
        else
        {
            cout << player.name << "喘了口气，耐力有所恢复（耐力+50）";
            player.SP += 50;
            cout << player.name << "的耐力恢复到" << player.SP << endl;
        }
    }
    if (action == 53)
    {
        cout << "你逃跑了！\n战斗结束！";
        gameover = true;
    }
    Sleep(1000);
    // 一次玩家进攻结束，组装数组导出
    return player;

}