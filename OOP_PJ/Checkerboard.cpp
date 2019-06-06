#include <utility>

//
// Created by asus on 2019/6/5.
//

#include "Checkerboard.h"
using namespace std;
/**
 * get the icon of the position in
 * this board
 * @param position the target position
 * @return icon
 */
char Checkerboard::get(const Position &position){
    map<Position, char>::iterator it;
    it = chesses.begin();
    while (it != chesses.end()) {
        if (it->first.getX() == position.getX() && it->first.getY() == position.getY()) {
            return it->second;
        }
        it++;
    }
    return 0;
}
/**
 * constructor function
 * @param maxx the max x
 * @param maxy the max y
 */
Checkerboard::Checkerboard(int maxx, int maxy) {
    this->maxx = maxx;
    this->maxy = maxy;
}

int Checkerboard::getMaxx() {
    return maxx;
}
int Checkerboard::getMaxy() {
    return maxy;
}
/**
 * put an icon in target position
 * first check if the position is
 * added. If so, modify it. If not,
 * add a new pair
 * @param position
 * @param icon
 */
void Checkerboard::put(const Position &position, char icon) {
    map<Position, char>::iterator it;
    it = chesses.begin();
    bool flag = true;
    while (it != chesses.end()) {
        if (it->first.getX() == position.getX() && it->first.getY() == position.getY()) {
            it->second = icon;
            flag = false;
            break;
        }
        it++;
    }
    if (flag) {
        chesses.insert(pair<Position, char>(position, icon));
    }
}
/**
 * check the board is finished
 * search the board and if find a
 * ICON_W_TARGET, then the board
 * is not finished.
 * @return
 */
bool Checkerboard::finished() {
    map<Position, char>::iterator it;
    it = chesses.begin();
    while (it != chesses.end()) {
        if (it->second == ICON_W_TARGET) {
            return false;
        }
        it++;
    }
    return true;
}
void Checkerboard::setCheese(map<Position, char> ma) {
    chesses = std::move(ma);
}
map<Position, char> Checkerboard::getCheese() {
    return chesses;
}