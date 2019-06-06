//
// Created by asus on 2019/6/5.
//

#ifndef OOP_PJ_SESSION_H
#define OOP_PJ_SESSION_H

#include "Checkerboard.h"
#include "Player.h"
class Session {
private:
    Checkerboard checkerboard;
    Player player;
    void updatePlayer(int x, int y);
    void setBoard(Checkerboard checkerboard1);
public:
    Session(int maxx, int maxy);
    Session(){}
    Checkerboard getBoard();
    void start();
    void finish();
    bool finished();
    Player getPlayer();
    void loadMap(const string&);

    void update(pair<Checkerboard, pair<int, int>> c);
};

#endif //OOP_PJ_SESSION_H
