#include "player.h"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

player::player()
{
    cout << "\nPlease enter in your name:\n";
    getline( cin, playerName );

    wins = loses = 0;

    guess = '0';
}

void player::SetGuess()
{
    cout << "\nPlease enter in a guess:\n";
    guess = getchar();
    while ( guess == '\n' ) { guess = getchar(); }
}

void player::addWin( )
{
    wins +=1;
}

void player::addLoses( )
{
    loses +=1;
}

player::~player()
{

}
