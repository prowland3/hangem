#include <string>

using namespace std;

#ifndef DISPLAY_H
#define DISPLAY_H

class display
{
    public:
        display( bool onLinux );
        virtual ~display();

        void mainMenu( );
        void exitMenu( string playerName, bool win );

        void inGame( int curImg, string wordMask );

    protected:
    private:
        string images[7];
        bool onlinux;

};

#endif // DISPLAY_H
