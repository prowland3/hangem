#include "display.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

display::display( bool onLinux )
{
    onlinux = onLinux;


    string img1 = "              \n"
                  "       -----  \n"
                  "       |   |  \n"
                  "           |  \n"
                  "           |  \n"
                  "           |  \n"
                  "           |  \n"
                  "    ----------\n";

   string img2 = "               \n"
                 "        -----  \n"
                 "        |   |  \n"
                 "       ( )  |  \n"
                 "            |  \n"
                 "            |  \n"
                 "            |  \n"
                 "     ----------\n";

   string img3 = "               \n"
                 "        -----  \n"
                 "        |   |  \n"
                 "       ( )  |  \n"
                 "        |   |  \n"
                 "            |  \n"
                 "            |  \n"
                 "     ----------\n";

   string img4 = "               \n"
                 "        -----  \n"
                 "        |   |  \n"
                 "       ( )  |  \n"
                 "       -|   |  \n"
                 "            |  \n"
                 "            |  \n"
                 "     ----------\n";

   string img5 = "               \n"
                 "        -----  \n"
                 "        |   |  \n"
                 "       ( )  |  \n"
                 "       -|-  |  \n"
                 "            |  \n"
                 "            |  \n"
                 "     ----------\n";

   string img6 = "               \n"
                 "        -----  \n"
                 "        |   |  \n"
                 "       ( )  |  \n"
                 "       -|-  |  \n"
                 "       /    |  \n"
                 "            |  \n"
                 "     ----------\n";

   string img7 = "               \n"
                 "        -----  \n"
                 "        |   |  \n"
                 "       ( )  |  \n"
                 "       -|-  |  \n"
                 "       / \\  |  \n"
                 "            |  \n"
                 "     ----------\n";

   images[0]  = img1;
   images[1]  = img2;
   images[2]  = img3;
   images[3]  = img4;
   images[4]  = img5;
   images[5]  = img6;
   images[6]  = img7;
}


void display::mainMenu( )
{
    if ( onlinux ) std::system("clear");
    else std::system("cls");

    cout << setw( 50 ) << "Welcome to...\n\n";

    string logo =  "        '||'  '||'     |     '|.   '|'  ..|'''.|  '||''''|  '||    ||' \n"
                   "         ||    ||     |||     |'|   |  .|'     '   ||  .     |||  |||  \n"
                   "         ||''''||    |  ||    | '|. |  ||    ....  ||''|     |'|..'||  \n"
                   "         ||    ||   .''''|.   |   |||  '|.    ||   ||        | '|' ||  \n"
                   "        .||.  .||. .|.  .||. .|.   '|   ''|...'|  .||.....| .|. | .||. \n\n";

    cout << logo << endl;
}

void display::exitMenu( string playerName, bool win )
{

    //if ( linux ) std::system("clear");
    //else std::system("cls");


    if ( win )
    {
        cout << setw(10) << "\nYou won " << playerName << "!\n";
        cout << setw(10) << "Would you like to play again?\n";
    }
    else
    {
        cout << setw(10) << "\nYou lost! " << playerName << "!\n";
        cout << setw(10) << "It's OK, wanna play again?\n";
    }
}

void display::inGame( int curImg, string wordMask )
{
    if ( onlinux ) std::system("clear");
    else std::system("cls");

    cout << setw(50) << images[ curImg ] << endl;
    cout << "\n" << setw(10) <<  wordMask << endl;
}

display::~display()
{
    //dtor
}
