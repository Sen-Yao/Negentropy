// ������һ��1v1ս���Ĳ��ԣ����ܻ�������c++��ѧϰ��������
#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "struct.h"
using namespace std;

int story_mode(int storypoint);
int freefight();

int main()
{
    cout << "��ӭ����������" << endl << endl;
    cout << "1.����ģʽ\n2.����ģʽ\n3.�˳���Ϸ\n";
    int game_choice1_1 = _getch();
    while (game_choice1_1 != 49 && game_choice1_1 != 50 && game_choice1_1 != 51)
        game_choice1_1 = _getch();
    if (game_choice1_1 == 49)
    {
        int game_choice2_1 = 0;
        cout << "\n1.������Ϸ\n2.����Ϸ\n3.���أ�����δʵ�֣�\n";
        while (game_choice2_1 != 49 && game_choice2_1 != 50 && game_choice2_1 != 51)
            game_choice2_1 = _getch();
        if (game_choice2_1 == 49)
        {
            int savepoint = 0;
            ifstream in("./saves\\save.txt");
            in >> savepoint;
            story_mode(savepoint);
        }
        if (game_choice2_1 == 50)
            story_mode(0);
        return 0;
    }
    if (game_choice1_1 == 50)
        freefight();
}