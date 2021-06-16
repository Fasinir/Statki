//
// Created by filip on 10.06.2021.
//

#ifndef STATKI2_PLAYER_H
#define STATKI2_PLAYER_H
#include <ostream>
using namespace std;
class player {
private:
    bool  isHuman1;
    string myName;
public:
    player(bool isHuman, string name);
    ~player() = default;
    void enterMove(int& x, int& y, int width, int height);
    void placeShip(int& x, int& y, int& orientation, int width, int height);
    bool isHuman();
    string getName();
};


#endif //STATKI2_PLAYER_H
