//
// Created by filip on 10.06.2021.
//

#ifndef STATKI2_BOARD_H
#define STATKI2_BOARD_H
#include <ostream>
#define VERTICAL 1
#define HORIZONTAL 0

class board {
private:
    int** matrix;
    int width, height;
    int HP;
public:
    board();
    board(board const& other);
    board(int width, int height);
    ~board();
    board& operator =(board const& other);

    bool shoot(int x, int y);
    int getHeight();
    int getWidth();
    friend std::ostream& operator<<(std::ostream& ostream, board& board1);
    int getHP();
    void placeShipRandom(int length);
    void placeShip(int x, int y, int length, int orientation);
    bool isAvailable(int x, int y, int length, int orientation);

};


#endif //STATKI2_BOARD_H
