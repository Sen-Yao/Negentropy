// 游戏主体部分
#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "struct.h"
using namespace std;

int story_mode(int storypoint);  //调用”story mode.cpp"里的storymode函数
int freefight();  //调用"free mode.cpp"里的freefight函数
int printlogo()  //打印logo和版本号
{
    cout << "    ######################        ####            ####  ####  \n";
    cout << "    ######################        ####            ####    ##  \n";
    cout << "    ####              ####        ####    ####################\n";
    cout << "    ####              ####        ####    ####################\n";
    cout << "    ######################      ########          ####        \n";
    cout << "    ##                    ####  ########  ######  ####        \n";
    cout << "    ##########################    ####    ######  ####  ####  \n";
    cout << "      ######################      ####    ##  ##  ####  ####  \n";
    cout << "        ####        ####          ####    ######  ####  ##    \n";
    cout << "##############################    ####    ######    ##  ##    \n";
    cout << "##############################    ######            ######    \n";
    cout << "        ####        ####        ########      ####  ####    ##\n";
    cout << "      ####          ####        ####    ##########  ######  ##\n";
    cout << "  ######            ####                ####      ####  ######\n";
    cout << "  ####              ####                        ####      ####\n";
    cout << "\n\n\n\n\n\n                                                      当前版本：beta1006\n\n\n";
    return 0;
}


int main()
{
    bool quit_game = false;  //判定是否退出游戏
    while (quit_game == false)
    {
        printlogo();
        cout << "1.故事模式\n2.自由模式\n3.退出游戏\n";
        int game_choice1_1 = _getch();
        while (game_choice1_1 != 49 && game_choice1_1 != 50 && game_choice1_1 != 51)
            game_choice1_1 = _getch();
        if (game_choice1_1 == 49)
        {
            int game_choice2_1 = 0;
            system("cls");
            printlogo();
            cout << "\n1.继续游戏\n2.新游戏\n3.返回（功能未实现）\n";
            while (game_choice2_1 != 49 && game_choice2_1 != 50 && game_choice2_1 != 51)
                game_choice2_1 = _getch();
            if (game_choice2_1 == 49)  // 选择继续游戏
            {
                system("cls");
                int savepoint = 0; // 先默认读取点为0
                ifstream in("./saves\\save.txt");  // 再读取文件中的存档
                in >> savepoint;
                story_mode(savepoint); //进入故事模式
            }
            if (game_choice2_1 == 50)  //新游戏
            {
                system("cls");
                story_mode(0);
            }
            return 0;
        }
        if (game_choice1_1 == 50)  //自由模式
        {
            system("cls");
            freefight();
        }
        if (game_choice1_1 == 51)  // 退出游戏
            break;
    }
    
}
