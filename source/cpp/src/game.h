#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "display.h"
#include "fileio.h"

enum GAMESTATES { MAINMENU, INGAME, ENDGAME };

using namespace std;

class game
{
    public:
        game( bool onlinux );
        virtual ~game();

        void gameLoop( );

        int getGameState( ) { return gameState; }

        void updateWordMask( char unMask );

        void reset( );

    protected:
    private:
        fileIO* mFile;
        player* mPlayer;
        display* mDisplay;
        string* words;
        string curWord;
        string wordMask;
        int gameState;
        int fails;
        bool quit;
};

#endif // GAME_H
