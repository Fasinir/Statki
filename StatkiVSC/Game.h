//
// Created by filip on 10.06.2021.
//

#ifndef STATKI2_GAME_H
#define STATKI2_GAME_H
#include "Player.h"
#include "Board.h"
#include "DisplayBoard.h"

class game {
private:
    const char* missedSound = "assets/missed.wav";
    const char* hitSound = "assets/hit.wav";
    const char* victorySound = "assets/victory.mp3";
    //for random player moves
    int width, height;
    player* firstPlayer;
    player* secondPlayer;
    board firstBoard;
    board secondBoard;
    displayBoard firstDisplayBoard;
    displayBoard secondDisplayBoard;
public:
    game(player* player1, player* player2, int width, int height, int shipNum, int shipLengths[]);
    void start();
    void placeShips(int shipNum, int shipLengths[]);
private:
    void announcePlayers();
    void requestShipPlacement(player* player1, board& board1, int length);
    void requestMove(player* player1, board& enemyBoard, displayBoard& playerDisplayBoard);
    void playSound(const char* soundPath);
};


#endif //STATKI2_GAME_H
