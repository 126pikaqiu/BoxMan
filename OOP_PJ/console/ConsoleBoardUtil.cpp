//
// Created by asus on 2019/6/5.
//

#include "ConsoleBoardUtil.h"
using namespace std;
/**
 * char to ICON
 * @param ico the icon char
 * @return the icon
 */
string ConsoleBoardUtil::getSymbol(char ico) const {
    switch (ico) {
        case ICON_BLANK:
            return "��";
        case ICON_BOX:
            return "��";
        case ICON_W_TARGET:
            return "��";
        case ICON_B_TARGET:
            return "��";
        case ICON_PERSON:
            return "��";
        case ICON_WALL:
            return "��";
        default:
            cout << "ILLEGAL ICON";
            assert(0);
    }
    return std::__cxx11::string();
}

/**
 * display the board
 * @param checkerboard the board to be displayed
 */
void ConsoleBoardUtil::display(Checkerboard checkerboard) const{
    cout << endl;
    for (int i = 0; i < checkerboard.getMaxx(); i++) {
        for (int j = 0; j < checkerboard.getMaxy(); j++) {
            cout << getSymbol(checkerboard.get(Position(i,j)));
        }
        cout << endl;
    }
}
/**
 * get the input from the keyboard
 * if the input can be handled here then
 * it would give a response. If not, hand
 * in the input order.
 * @param input the input from the keyboard
 * @return can be handled here or not
 */
bool ConsoleBoardUtil::check_input_response(const char *input) {
    switch (input[0]) {
        case 'A':
        case 'W':
        case 'S':
        case 'D':
        case 'Q': // to quit
        case 'R': // to restart
            return true;
        case '\n': // nop
            cout << "ָ��Ϊ��" << endl;
            return false;
        case 'H': // to get help
        case 'h':
            cout <<endl;
            cout << "ͼ��˵����" << endl;
            cout << "��û�з����ӵ�Ŀ��   ���Ѿ��������ӵ�Ŀ��" << endl;
            cout << "�������   ����ǽ��   ��������" << endl;
            cout << "ָ��˵����" << endl;
            cout << "W�������ƶ�   A�������ƶ�   S�������ƶ�   D�������ƶ�" << endl;
            cout << "H������   R�����¿�ʼ   Q���˳���Ϸ" << endl;
            return false;
        default:
            cout << "ָ�����" << endl;
            return false;
    }
}
/**
 * display some welcome words.
 */
void ConsoleBoardUtil::welcome() {
    cout << "===================================="<<endl;
    cout << "=====С���������ӣ���ү������ѽ======="<<endl;
    cout << "===================================="<<endl;
    cout << "ͼ��˵����" << endl;
    cout << "��û�з����ӵ�Ŀ��   ���Ѿ��������ӵ�Ŀ��" << endl;
    cout << "�������   ����ǽ��   ��������" << endl;
    cout << "ָ��˵����" << endl;
    cout << "W�������ƶ�   A�������ƶ�   S�������ƶ�   D�������ƶ�" << endl;
    cout << "H������   R�����¿�ʼ   Q���˳���Ϸ" << endl;
    cout << endl;
}
/**
 * display some words when winning
 */
void ConsoleBoardUtil::win() {
    cout << endl;
    cout << "===================================="<<endl;
    cout << "=====С���������ӣ���ү������ѽ======="<<endl;
    cout << "===================================="<<endl;
    cout << "You are so good! And you just win!!!" << endl;
    cout << "��Ϸͨ�أ�ʤ��������";
    cout << endl;
}
/**
 * display some words when giving up.
 */
void ConsoleBoardUtil::giveUp() {
    cout << endl;
    cout << "===================================="<<endl;
    cout << "=====С���������ӣ���ү������ѽ======="<<endl;
    cout << "===================================="<<endl;
    cout << "You give up it." << endl;
    cout << "�ټ�";
    cout << endl;
}

/**
 * get the level
 * @return the level
 */
char ConsoleBoardUtil::pickLevel() {
    while (true) {
        cout << "������ѡ��Ĺؿ���0-9��:  ";
        char input[512];
        cin.getline(input, 512);
        if ((input[0] >= '0' && input[0] <= '9') && (input[1] < '0' || input[1] > '9')) {
            return input[0];
        } else {
            cout << "ѡ�����������ѡ��" << endl;
        }
    }
}
/**
 * wait for the player input some orders
 * N means do nothing
 * @return order
 */
char ConsoleBoardUtil::waitForInput() {
    char input[512];
    cout << "���������ָ� ";
    cin.getline(input,512);
    if (check_input_response(input)) {
        return input[0];
    } else {
        return 'N'; //do nothing
    }
}