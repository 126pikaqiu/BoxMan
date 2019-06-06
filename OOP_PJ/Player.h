//
// Created by asus on 2019/6/5.
//

#ifndef OOP_PJ_PLAYER_H
#define OOP_PJ_PLAYER_H

#include "Position.h"
#include "Checkerboard.h"
class Player {
private:
    Position position;
    map<char, Position> movePos;
public:
    Player()= default;
    Player(int x, int y);
    pair<Checkerboard, pair<int, int>> action(Checkerboard checkerboard, char order);
    void setX(int ux);
    void setY(int uy);
};
#endif //OOP_PJ_PLAYER_H
