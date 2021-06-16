//
// Created by filip on 10.06.2021.
//

#include "Player.h"
#include <iostream>
#include <ostream>
using namespace std;

player::player(bool isHuman, string name) {
    this->isHuman1 = isHuman;
    myName = name;
}

void player::enterMove(int& x, int& y, int width, int height) {
    if (isHuman1) {
        cout << "Wprowadz ruch" << endl;
        cin >> x >> y;
    }
    else
    {
        x = rand() % width;
        y = rand() % height;
    }
}

void player::placeShip(int& x, int& y, int& orientation, int width, int height) {
    if (isHuman1)
    {
        cin >> x >> y >> orientation;
    }
    else
    {
        x = rand() % width;
        y = rand() % height;
        orientation = rand() % 2;
    }
}

bool player::isHuman() {
    return isHuman1;
}

string player::getName() {
    return this->myName;
}
