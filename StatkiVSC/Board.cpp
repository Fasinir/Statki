//
// Created by filip on 10.06.2021.
//

#include "Board.h"
#include "iostream"

using namespace std;
board::board(int width, int height) {
    this->matrix = new int* [width];
    this->HP = 0;
    for (int i = 0; i < width; i++)
    {
        this->matrix[i] = new int[height];
        for (int j = 0; j < height; j++)
        {
            this->matrix[i][j] = -1;
        }
    }
    this->width = width;
    this->height = height;
}
board::~board() {
    if (this->matrix != nullptr)
    {
        for (int i = 0; i < width; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

board::board() {
    this->HP = 0;
    this->matrix = nullptr;
    this->width = 0;
    this->height = 0;
}

board& board::operator=(board const& other) {
    if (this->matrix != nullptr)
    {
        for (int i = 0; i < width; i++)
        {
            delete matrix[i];
        }
        delete matrix;
    }
    this->matrix = nullptr;
    this->width = other.width;
    this->height = other.height;

    this->matrix = new int* [width];
    for (int i = 0; i < width; i++)
    {
        this->matrix[i] = new int[height];
        for (int j = 0; j < height; j++)
        {
            this->matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

bool board::shoot(int x, int y) {
    if (x < 0 || x >= width)
    {
        return false;
    }
    if (y < 0 || y >= height)
    {
        return false;
    }
    if (this->matrix[x][y] >= 0)
    {
        matrix[x][y] = -1;
        HP--;
        return true;
    }
    return false;
}

int board::getHeight() {
    return height;
}

int board::getWidth() {
    return width;
}

std::ostream& operator<<(std::ostream& ostream, board& board1) {
    for (int j = board1.getHeight() - 1; j >= 0; j--)
    {
        ostream << j << " ";
        for (int i = 0; i < board1.getWidth(); i++)
        {
            ostream << board1.matrix[i][j]<<" ";
        }
        ostream << "\n";
    }
    ostream << "  ";
    for (int i = 0; i < board1.getWidth(); i++)
    {
        ostream << i << " ";
    }
    ostream << "\n";
    return ostream;
}

int board::getHP() {
    return HP;
}

void board::placeShipRandom(int length) {
    bool placed = false;
    while (!placed)
    {
        int x = rand() % width;
        int y = rand() % height;
        int orientation = rand() % 2;
        if (isAvailable(x, y, length, orientation))
        {
            placeShip(x, y, length, orientation);
            placed = true;
        }
    }
}

bool board::isAvailable(int x, int y, int length, int orientation) {
    if (orientation == VERTICAL)
    {
        if (y + length > height)
        {
            return false;
        }
        for (int i = y; i < y + length; i++)
        {
            if (this->matrix[x][i] != -1)
            {
                return false;
            }
        }
    }
    else if (orientation == HORIZONTAL)
    {
        if (x + length > width) {
            return false;
        }
        for (int i = x; i < x + length; i++)
        {
            if (this->matrix[i][y] != -1)
            {
                return false;
            }
        }
    }
    return true;
}

void board::placeShip(int x, int y, int length, int orientation) {
    if (isAvailable(x, y, length, orientation))
    {
        if (orientation == VERTICAL)
        {
            for (int i = y; i < y + length; i++)
            {
                matrix[x][i] = length;
            }
        }
        else if (orientation == HORIZONTAL)
        {
            for (int i = x; i < x + length; i++)
            {
                matrix[i][y] = length;
            }
        }
    }
    HP += length;

}

board::board(const board& other) {
    if (this->matrix != nullptr)
    {
        for (int i = 0; i < width; i++)
        {
            delete matrix[i];
        }
        delete matrix;
    }
    this->matrix = nullptr;
    this->width = other.width;
    this->height = other.height;

    this->matrix = new int* [width];
    for (int i = 0; i < width; i++)
    {
        this->matrix[i] = new int[height];
        for (int j = 0; j < height; j++)
        {
            this->matrix[i][j] = other.matrix[i][j];
        }
    }
}
