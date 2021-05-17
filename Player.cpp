#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
    cout << "Player create" << endl;
}

void Player::getInfo()
{
    cout << "Player position: " << posX << ", " << posY << endl;
}

int Player::setPos(int x, int y)
{
    posX = x;
    posY = y;

    return posX, posY; 
}

int Player::getPos(string axis)
{
    if (axis == "x") return posX;
    else return posY;
}

int Player::move(string key)
{
    if (key == "w") return posY--;
    else if (key == "a") return posX--;
    else if (key == "s") return posY++;
    else if (key == "d") return posX++;
    else return 0;
}
