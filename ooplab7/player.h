#ifndef PLAYER_H
#define PLAYER_H
#include "moveitem.h"
#include <QList>

class Player
{
public:
    Player(bool isWhiteV=true);
    bool isWhite;
    QList<MoveItem*> figures;
private:
};

#endif // PLAYER_H
