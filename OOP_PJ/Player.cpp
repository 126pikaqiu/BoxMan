//
// Created by asus on 2019/6/5.
//

#include "Player.h"
/**
 * constructor function
 * initialize the position and
 * the move map.
 * @param x the x of the player
 * @param y the y of the player
 */
Player::Player(int x, int y) {
    position = Position(x, y);
    movePos.insert(pair<char, Position>('A', Position(0, -1)));
    movePos.insert(pair<char, Position>('W', Position(-1, 0)));
    movePos.insert(pair<char, Position>('D', Position(0, 1)));
    movePos.insert(pair<char, Position>('S', Position(1, 0)));
}

/**
 * accept an checkerboard and an order
 * the player would move and return
 * the new checkerboard and the new position
 * @param checkerboard
 * @param order
 * @return
 */
pair<Checkerboard, pair<int, int>> Player::action(Checkerboard checkerboard, char order) {
    if (order == 'N'){
        pair<Checkerboard, pair<int, int>> result = make_pair(checkerboard,make_pair(position.getX(),position.getY()));
        return result;
    }
    Position move = movePos.find(order)->second;
    Position newPos = position + move;
    if (checkerboard.get(newPos) == ICON_BLANK) {
        checkerboard.put(newPos, ICON_PERSON);
    } else if (checkerboard.get(newPos) == ICON_BOX && checkerboard.get(newPos + move) == ICON_BLANK) {
        checkerboard.put(newPos + move, ICON_BOX);
        checkerboard.put(newPos, ICON_PERSON);
    } else if (checkerboard.get(newPos) == ICON_BOX && checkerboard.get(newPos + move) == ICON_W_TARGET) {
        checkerboard.put(newPos + move, ICON_B_TARGET);
        checkerboard.put(newPos, ICON_PERSON);
    } else if (checkerboard.get(newPos) == ICON_W_TARGET) {

    } else if (checkerboard.get(newPos) == ICON_B_TARGET && checkerboard.get(newPos + move) == ICON_BLANK) {
        checkerboard.put(newPos + move, ICON_BOX);
        checkerboard.put(newPos, ICON_W_TARGET);
    } else if (checkerboard.get(newPos) == ICON_B_TARGET && checkerboard.get(newPos + move) == ICON_W_TARGET) {
        checkerboard.put(newPos + move, ICON_B_TARGET);
        checkerboard.put(newPos, ICON_W_TARGET);
    } else {
        pair<Checkerboard, pair<int, int>> result = make_pair(checkerboard,make_pair(position.getX(),position.getY()));
        return result;
    }
    if (checkerboard.get(position) == ICON_PERSON)
        checkerboard.put(position, ICON_BLANK);
    position.setX(newPos.getX());
    position.setY(newPos.getY());
    pair<Checkerboard, pair<int, int>> result = make_pair(checkerboard,make_pair(newPos.getX(),newPos.getY()));
    return result;
}
/**
 * update the x of the position
 * @param ux
 */
void Player::setX(int ux) {
    position.setX(ux);
}
/**
 * update the y of the position
 * @param uy
 */
void Player::setY(int uy) {
    position.setY(uy);
}