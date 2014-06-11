#include "fileio.h"
#include "player.h"
#include "display.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    bool onlinux = 1;

    /* IGNORE 

    char yes;

    cout << "Are you running this on linux? (y/n)" << endl;
    yes = getchar( );
    while ( yes != 'y' && yes != 'n' ) { yes = getchar(); }

    if ( yes == 'y') { onlinux = 1; }

    cin.ignore( 1000, '\n' );

    */

    game* hangem = new game( onlinux );

    if ( hangem->getGameState( ) == INGAME )
    {
        hangem->gameLoop( );
    }

    return 0;
}
