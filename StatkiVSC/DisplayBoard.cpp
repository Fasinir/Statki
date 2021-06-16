//
// Created by filip on 10.06.2021.
//

#include "DisplayBoard.h"

displayBoard::displayBoard() {
    this->width = 0;
    this->height = 0;
    this->matrix = nullptr;
}

displayBoard::displayBoard(int width, int height) {
    this->matrix = new pointState * [width];
    for (int i = 0; i < width; i++)
    {
        matrix[i] = new pointState[height];
        for (int j = 0; j < height; j++)
        {
            matrix[i][j] = UNKONWN;
        }
    }
    this->width = width;
    this->height = height;

}

displayBoard::~displayBoard() {
    if (matrix != nullptr)
    {
        for (int i = 0; i < width; i++)
        {
            delete[] matrix[i];
        }
        delete[]matrix;
    }

}

displayBoard& displayBoard::operator=(const displayBoard& other) {
    if (this->matrix != nullptr)
    {
        for (int i = 0; i < width; i++)
        {
            delete[] matrix[i];
        }
        delete[]matrix;
    }
    this->height = other.height;
    this->width = other.width;

    matrix = new pointState * [width];
    for (int i = 0; i < width; i++)
    {
        matrix[i] = new pointState[height];
        for (int j = 0; j < height; j++)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

void displayBoard::changePoint(int x, int y, pointState state) {
    if (x < 0 || x >= width)
    {
        return;
    }
    if (y < 0 || y >= height)
    {
        return;
    }
    matrix[x][y] = state;
}

std::ostream& operator<<(std::ostream& ostream, displayBoard& board) {


    for (int j = board.getHeight() - 1; j >= 0; j--)
    {
        ostream << j << " ";
        for (int i = 0; i < board.getWidth(); i++)
        {
            switch (board.matrix[i][j]) {
            case UNKONWN:
                ostream << "? ";
                break;
            case HIT:
                ostream << "X ";
                break;
            case MISSED:
                ostream << "O ";
                break;
            }
        }
        ostream << "\n";
    }
    ostream << "  ";
    for (int i = 0; i < board.getWidth(); i++)
    {
        ostream << i << " ";
    }
    ostream << "\n";
    return ostream;
}

int displayBoard::getWidth() {
    return width;
}

int displayBoard::getHeight() {
    return height;
}

pointState displayBoard::getPoint(int x, int y) {
    if (x < 0 || x >= width)
    {
        return UNKONWN;
    }
    if (y < 0 || y >= height)
    {
        return UNKONWN;
    }
    return matrix[x][y];
}
