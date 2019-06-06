//
// Created by asus on 2019/6/5.
//

#ifndef OOP_PJ_POSITION_H
#define OOP_PJ_POSITION_H
class Position {
private:
    int x{};
    int y{};
public:
    Position(int x, int y);
    Position()= default;
    int getX() const;
    int getY() const;
    Position operator+(const Position& position);
    Position operator-(const Position& position);
    bool operator<(const Position& position) const;
    void setX(int x);
    void setY(int y);
};
#endif //OOP_PJ_POSITION_H
