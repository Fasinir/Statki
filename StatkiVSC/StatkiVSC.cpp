#include <iostream>
#include "Player.h"
#include <ostream>
#include "DisplayBoard.h"
#include <time.h>
#include "Board.h"
#include "Game.h"
#include "bass/c/bass.h"
/*
* ASSETS:
* https://opengameart.org/content/tiny-naval-battle-sounds-set
* https://opengameart.org/content/gb-victory-stinger-and-game-over-man
*/
int main() {
    srand(time(NULL));
    player playerOne(true, "Student");

    player playerTwo(false, "Bot");
    int ships[] = { 2,2 };

    BASS_Init(-1, 44100, 0, 0, NULL);
    BASS_SetVolume(0.01);

    game(&playerOne,&playerTwo,4,4,2,ships);
    
    
    
    
     
    

    system("pause");
    return 0;
}
