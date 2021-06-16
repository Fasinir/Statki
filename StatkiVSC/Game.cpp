//
// Created by filip on 10.06.2021.
//

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "bass/c/bass.h"
#include <Windows.h>

using namespace std;
game::game(player* player1, player* player2, int width, int height, int shipNum, int shipLengths[]) {
    if (rand() % 2 == 0)
    {
        firstPlayer = player1;
        secondPlayer = player2;
    }
    else
    {
        firstPlayer = player2;
        secondPlayer = player1;
    }
    announcePlayers();
    firstBoard = board(width, height);
    secondBoard = board(width, height);
    firstDisplayBoard = displayBoard(width, height);
    secondDisplayBoard = displayBoard(width, height);
    this->height = height;
    this->width = width;
    placeShips(shipNum, shipLengths);
    start();
}

void game::start() {

    while (firstBoard.getHP() > 0 && secondBoard.getHP() > 0)
    {
        system("cls");
        cout << "Widok dla " << firstPlayer->getName() << endl;
        cout << firstDisplayBoard << endl;
        cout << "Widok dla " << secondPlayer->getName() << endl;
        cout << secondDisplayBoard << endl;

        requestMove(firstPlayer, secondBoard, firstDisplayBoard);
        if (secondBoard.getHP() <= 0)
        {
            break;
        }
        requestMove(secondPlayer, firstBoard, secondDisplayBoard);

        Sleep(2000);

    }
    if (firstBoard.getHP() <= 0)
    {
        cout << "Wygrywa " << secondPlayer->getName() << "!" << endl;
    } if (secondBoard.getHP() <= 0)
    {
        cout << "Wygrywa " << firstPlayer->getName() << "!" << endl;
    }
    playSound(victorySound);
    //system("pause");
}

void game::placeShips(int shipNum, int* shipLengths) {
    int idx = 0;
    while (idx < shipNum)
    {
        int length = shipLengths[idx];
        requestShipPlacement(firstPlayer, firstBoard, length);
        requestShipPlacement(secondPlayer, secondBoard, length);
        idx++;
    }
}

void game::announcePlayers() {
    cout << "Witaj " << firstPlayer->getName() << "! Jestes pierwszym graczem" << endl;
    cout << "Witaj " << secondPlayer->getName() << "! Jestes drugim graczem" << endl;
    Sleep(5000);
}

//will call "placeShip" on player
void game::requestShipPlacement(player* player1, board& board1, int length) {
    int x, y, orientation;
    cout << player1->getName() << " ustaw statek o dlugosci " << length << "\n" << endl;
    cout << "x y 0/1 0-poziomo 1-pionowo" << endl;
    if (player1->isHuman())
    {
        cout << board1 << endl;
    }
    do {
        player1->placeShip(x, y, orientation, width, height);
        //cout<<x<<" "<<y<<" "<<orientation<<endl;
    } while (!board1.isAvailable(x, y, length, orientation));

    board1.placeShip(x, y, length, orientation);
    if (player1->isHuman())
    {
        cout << board1 << endl;
    }
    Sleep(3000);
    system("cls");
}

void game::requestMove(player* player, board& enemyBoard, displayBoard& playerDisplayBoard) {
    int x, y;
    player->enterMove(x, y, width, height);
    cout << player->getName() << " zagral ruch " << x << " " << y << endl;
    if (enemyBoard.shoot(x, y))
    {
        cout << "Trafiony!" << endl;
        if (playerDisplayBoard.getPoint(x, y) == UNKONWN)
        {
            playerDisplayBoard.changePoint(x, y, HIT);
        }
        playSound(hitSound);

    }
    else
    {
        cout << "Pudlo!" << endl;
        if (playerDisplayBoard.getPoint(x, y) == UNKONWN)
        {
            playerDisplayBoard.changePoint(x, y, MISSED);
        }
        playSound(missedSound);
    }
    cout << playerDisplayBoard << endl;
    Sleep(2000);
}

void game::playSound(const char* soundPath)
{
    HSAMPLE sample = BASS_SampleLoad(false, soundPath, 0, 0, 1, BASS_SAMPLE_MONO);
    HCHANNEL channel = BASS_SampleGetChannel(sample, FALSE);
    BASS_ChannelPlay(channel, FALSE);
}


