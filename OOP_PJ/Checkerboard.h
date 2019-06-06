//
// Created by asus on 2019/6/5.
//

#ifndef OOP_PJ_CHECKERBOARD_H
#define OOP_PJ_CHECKERBOARD_H

#include "Position.h"
#include "Icon.h"
#include <map>
using namespace std;
class Checkerboard {
private:
    map<Position,char> chesses;
    int maxy;
    int maxx;
public:
    char get(const Position & position);
    Checkerboard(int maxx, int maxy);
    Checkerboard():maxx(0),maxy(0){}
    int getMaxx();
    int getMaxy();
    bool finished();
    void put(const Position& position, char icon);
    void setCheese(map<Position, char> ma);
    map<Position, char> getCheese();
};
#endif //OOP_PJ_CHECKERBOARD_H
