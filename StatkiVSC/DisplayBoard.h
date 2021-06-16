//
// Created by filip on 10.06.2021.
//

#ifndef STATKI2_DISPLAYBOARD_H
#define STATKI2_DISPLAYBOARD_H
#include <ostream>
enum pointState
{
    UNKONWN,
    HIT,
    MISSED
};

class displayBoard {
private:
    pointState** matrix;
    int width, height;
    int HP;
public:
    displayBoard();
    displayBoard(int width, int height);
    ~displayBoard();
    displayBoard& operator =(displayBoard const& other);
    void changePoint(int x, int y, pointState state);
    int getWidth();
    int getHeight();
    friend std::ostream& operator<<(std::ostream& ostream, displayBoard& board);
    pointState getPoint(int x, int y);
};


#endif //STATKI2_DISPLAYBOARD_H
