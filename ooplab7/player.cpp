#include "player.h"

Player::Player(bool isWhiteV)
{
    isWhite=isWhiteV;
    figures.append(new MoveItem(bishop,isWhite));
    figures.append(new MoveItem(bishop,isWhite));
    figures.append(new MoveItem(knight,isWhite));
    figures.append(new MoveItem(knight,isWhite));
    figures.append(new MoveItem(rook,isWhite));
    figures.append(new MoveItem(rook,isWhite));
}
