#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

#include <string>

#ifndef PLAYER_H
#define PLAYER_H


class player
{
    public:
        player();
        virtual ~player();

        string GetplayerName() { return playerName; }

        char  Getguess( ) { return guess; }
        void  SetGuess( );

        int   GetWins( ) { return wins; }
        int   GetLoses( ) { return loses; }

        void  addWin( );
        void  addLoses( );

    protected:

    private:
        string playerName;
        char  guess;
        int   wins;
        int   loses;
};

#endif // PLAYER_H
