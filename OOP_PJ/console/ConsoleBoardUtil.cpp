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
            return "　";
        case ICON_BOX:
            return "□";
        case ICON_W_TARGET:
            return "○";
        case ICON_B_TARGET:
            return "●";
        case ICON_PERSON:
            return "※";
        case ICON_WALL:
            return "■";
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
            cout << "指令为空" << endl;
            return false;
        case 'H': // to get help
        case 'h':
            cout <<endl;
            cout << "图标说明：" << endl;
            cout << "○：没有放箱子的目标   ●：已经放置箱子的目标" << endl;
            cout << "※：玩家   ■：墙体   □：箱子" << endl;
            cout << "指令说明：" << endl;
            cout << "W：向上移动   A：向左移动   S：向下移动   D：向右移动" << endl;
            cout << "H：帮助   R：重新开始   Q：退出游戏" << endl;
            return false;
        default:
            cout << "指令错误" << endl;
            return false;
    }
}
/**
 * display some welcome words.
 */
void ConsoleBoardUtil::welcome() {
    cout << "===================================="<<endl;
    cout << "=====小霸王推箱子，大爷，来玩呀======="<<endl;
    cout << "===================================="<<endl;
    cout << "图标说明：" << endl;
    cout << "○：没有放箱子的目标   ●：已经放置箱子的目标" << endl;
    cout << "※：玩家   ■：墙体   □：箱子" << endl;
    cout << "指令说明：" << endl;
    cout << "W：向上移动   A：向左移动   S：向下移动   D：向右移动" << endl;
    cout << "H：帮助   R：重新开始   Q：退出游戏" << endl;
    cout << endl;
}
/**
 * display some words when winning
 */
void ConsoleBoardUtil::win() {
    cout << endl;
    cout << "===================================="<<endl;
    cout << "=====小霸王推箱子，大爷，来玩呀======="<<endl;
    cout << "===================================="<<endl;
    cout << "You are so good! And you just win!!!" << endl;
    cout << "游戏通关，胜利！！！";
    cout << endl;
}
/**
 * display some words when giving up.
 */
void ConsoleBoardUtil::giveUp() {
    cout << endl;
    cout << "===================================="<<endl;
    cout << "=====小霸王推箱子，大爷，来玩呀======="<<endl;
    cout << "===================================="<<endl;
    cout << "You give up it." << endl;
    cout << "再见";
    cout << endl;
}

/**
 * get the level
 * @return the level
 */
char ConsoleBoardUtil::pickLevel() {
    while (true) {
        cout << "请输入选择的关卡（0-9）:  ";
        char input[512];
        cin.getline(input, 512);
        if ((input[0] >= '0' && input[0] <= '9') && (input[1] < '0' || input[1] > '9')) {
            return input[0];
        } else {
            cout << "选择错误，请重新选择。" << endl;
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
    cout << "请输入你的指令： ";
    cin.getline(input,512);
    if (check_input_response(input)) {
        return input[0];
    } else {
        return 'N'; //do nothing
    }
}