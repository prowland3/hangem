#include "game.h"
#include "player.h"
#include "display.h"
#include "fileio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

game::game( bool onlinux )
{
    char filePath[] = "dictionary.txt";

    mFile = new fileIO( filePath, 0 );

    words = mFile->Getwords( );

    srand ( time(NULL) );

    int i = rand() % mFile->GetnumWords();

    mDisplay = new display( onlinux );

    curWord = words[ i ];

    wordMask = curWord;

    for ( unsigned int x = 0; x < wordMask.length( ); x++ )
    {
        wordMask[x] = '/';
    }

    fails = 0;

    mDisplay->mainMenu( );

    gameState = MAINMENU;

    mPlayer = new player( );

    gameState = INGAME;
}

void game::updateWordMask( char unMask )
{
    bool fail = 1;
    for( unsigned int i = 0; i < curWord.length(); i++ )
    {
        if ( curWord[i] == unMask )
        {
            wordMask[i] = unMask;
            fail = 0;
        }
    }
    if ( fail ) { fails += 1; }
}

void game::reset( )
{
    int i = rand() % mFile->GetnumWords();

    curWord = words[ i ];

    wordMask = curWord;

    for ( unsigned int x = 0; x < wordMask.length( ); x++ )
    {
        wordMask[x] = '/';
    }

    fails = 0;

    gameState = INGAME;
}

void game::gameLoop( )
{
    mDisplay->inGame( fails, wordMask );
    mPlayer->SetGuess( );
    while ( !quit )
    {
        if ( ( fails < 6 ) && ( curWord != wordMask ) )
        {
            updateWordMask(  mPlayer->Getguess( ) );
            mDisplay->inGame( fails, wordMask );
            if ( fails == 6 ) { continue; }
            if ( curWord == wordMask ) { continue; }
            mPlayer->SetGuess( );
        }
        else if ( ( fails < 6 ) && ( curWord == wordMask ) )
        {
            mDisplay->exitMenu( mPlayer->GetplayerName( ), 1 );
            char yes;
            yes = getchar();
            while ( yes == '\n' ) { yes = getchar(); }
            if ( yes != 'y' && yes != 'Y' )
            {
                quit = 1;
            }
            else
            {
                reset( );
                mDisplay->inGame( fails, wordMask );
                mPlayer->SetGuess( );
            }
        }
        else
        {
            mDisplay->exitMenu( mPlayer->GetplayerName( ), 0 );
            char yes;
            yes = getchar();
            while ( yes == '\n' ) { yes = getchar(); }
            if ( yes != 'y' && yes != 'Y' )
            {
                quit = 1;
            }
            else
            {
                reset( );
                mDisplay->inGame( fails, wordMask );
                mPlayer->SetGuess( );
            }
        }
    }
}

game::~game()
{
    delete mPlayer;
    delete mFile;
    delete mDisplay;
    delete words;
}
