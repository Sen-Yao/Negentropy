// ��Ϸ���岿��
#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "struct.h"
using namespace std;

int story_mode(int storypoint);  //���á�story mode.cpp"���storymode����
int freefight();  //����"free mode.cpp"���freefight����
int printlogo()  //��ӡlogo�Ͱ汾��
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
    cout << "\n\n\n\n\n\n                                                      ��ǰ�汾��beta1006\n\n\n";
    return 0;
}


int main()
{
    bool quit_game = false;  //�ж��Ƿ��˳���Ϸ
    while (quit_game == false)
    {
        printlogo();
        cout << "1.����ģʽ\n2.����ģʽ\n3.�˳���Ϸ\n";
        int game_choice1_1 = _getch();
        while (game_choice1_1 != 49 && game_choice1_1 != 50 && game_choice1_1 != 51)
            game_choice1_1 = _getch();
        if (game_choice1_1 == 49)
        {
            int game_choice2_1 = 0;
            system("cls");
            printlogo();
            cout << "\n1.������Ϸ\n2.����Ϸ\n3.���أ�����δʵ�֣�\n";
            while (game_choice2_1 != 49 && game_choice2_1 != 50 && game_choice2_1 != 51)
                game_choice2_1 = _getch();
            if (game_choice2_1 == 49)  // ѡ�������Ϸ
            {
                system("cls");
                int savepoint = 0; // ��Ĭ�϶�ȡ��Ϊ0
                ifstream in("./saves\\save.txt");  // �ٶ�ȡ�ļ��еĴ浵
                in >> savepoint;
                story_mode(savepoint); //�������ģʽ
            }
            if (game_choice2_1 == 50)  //����Ϸ
            {
                system("cls");
                story_mode(0);
            }
            return 0;
        }
        if (game_choice1_1 == 50)  //����ģʽ
        {
            system("cls");
            freefight();
        }
        if (game_choice1_1 == 51)  // �˳���Ϸ
            break;
    }
    
}
