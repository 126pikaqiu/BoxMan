//
// Created by asus on 2019/6/5.
//

#include "Session.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include "console/ConsoleBoardUtil.h"
using namespace std;
/**
 * ------------------> y
 * |
 * |
 * |
 * |
 * x
 * constructor function
 * initialize the board
 * @param maxx the max x of the board
 * @param maxy the max y of the board
 */
Session::Session(int maxx, int maxy) {
    checkerboard = Checkerboard(maxx, maxy);
}

/**
 * load the target map and initialize the
 * board and the player
 * @param mapName the name of the target map file
 */
void Session::loadMap(const string & mapName) {
    ifstream file;
    file.open(mapName, ios::in);
    if (file.fail()) {
        cout << "The file " << mapName << " not found."<< endl;
        assert(0);
    }
    string line;
    getline(file, line);
    int start = line.find(' ');
    int maxy = atoi(line.substr(0, start).c_str());
    int maxx = atoi(line.substr(start).c_str());
    checkerboard = Checkerboard(maxx, maxy);
    for (int i = 0; i < maxx; i++) {
        getline(file, line);
        while (line.find('2') != string::npos) {
            line.replace(line.find('2'), 1, "0");
        }
        for (int j = 0; j < maxy; j++) {
            checkerboard.put(Position(i, j), line.at(j) - '0');
            if (line.at(j) - '0' == 5) {
                player = Player(i, j);
            }
        }
    }
}
/**
 *
 * @return the board
 */
Checkerboard Session::getBoard() {
    return checkerboard;
}
/**
 * before the session
 */
void Session::start() {

}
/**
 * after the session
 */
void Session::finish() {

}
/**
 * to check the session is finished
 * @return true or false
 */
bool Session::finished() {
    return checkerboard.finished();
}
/**
 *
 * @return the player
 */
Player Session::getPlayer() {
    return player;
}
/**
 * update the player
 * @param x the x of the position
 * @param y the y of the position
 */
void Session::updatePlayer(int x, int y) {
    player.setX(x);
    player.setY(y);
}
/**
 * update the board
 * @param checkerboard1 the new board
 */
void Session::setBoard(Checkerboard checkerboard1) {
    checkerboard.setCheese(checkerboard1.getCheese());
}
/**
 * update the board and the player
 * @param c pair of board and position of the player.
 */
void Session::update(pair<Checkerboard, pair<int, int>> c) {
    setBoard(c.first);
    updatePlayer(c.second.first, c.second.second);
}