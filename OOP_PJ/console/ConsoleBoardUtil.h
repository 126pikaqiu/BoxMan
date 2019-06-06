//
// Created by asus on 2019/6/5.
//

#ifndef OOP_PJ_CONSOLEBOARDUTIL_H
#define OOP_PJ_CONSOLEBOARDUTIL_H

#include "../Checkerboard.h"
#include "../Icon.h"
#include <cassert>
#include <iostream>
class ConsoleBoardUtil {
private:
    string getSymbol(char icon) const;
    bool check_input_response(const char *input);
public:
    void display(Checkerboard checkerboard) const ;
    char waitForInput();
    char pickLevel();
    void welcome();
    void win();
    void giveUp();
};
#endif //OOP_PJ_CONSOLEBOARDUTIL_H
