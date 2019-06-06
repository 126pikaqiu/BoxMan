//
// Created by asus on 2019/6/5.
//

#include "Position.h"
/**
 *
 * @return the x of the position
 */
int Position::getX() const {
    return x;
}
/**
 *
 * @return the y of the position
 */
int Position::getY() const {
    return y;
}
/**
 *
 * constructor function and
 * initialize the position
 * @param x the x of the position
 * @param y the y of the position
 */
Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}
/**
 * overload the operator +
 * @param position the right position to be added
 * @return the new position
 */
Position Position::operator+(const Position &position) {
    return {x + position.x, y + position.y};
}
/**
 * overload the operator -
 * @param position the right position to be reduced
 * @return the new position
 */
Position Position::operator-(const Position &position) {
    return {x - position.x, y - position.y};
}
/**
 * overload the operator <
 * because position instances would be inserted into the map,
 * which would call it.
 * @param position the right position to be compared
 * @return the new position
 */
bool Position::operator<(const Position &position) const {
    return x < position.x || y < position.y;
}
/**
 * update the x of the position
 * @param x1 the x of the position
 */
void Position::setX(int x1) {
    this->x = x1;

}
/**
 * update the y of the position
 * @param y1 the y of the position
 */
void Position::setY(int y1) {
    this->y = y1;
}