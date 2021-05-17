#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player
{
    public:
        Player();

        void getInfo();

        int setPos(int x, int y);

        int getPos(string axis);

        int move(string key);
    protected:
    private:
        int posX;
        int posY;
};

#endif // PLAYER_H
