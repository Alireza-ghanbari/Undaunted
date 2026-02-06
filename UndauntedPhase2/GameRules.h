#ifndef GAMERULES_H
#define GAMERULES_H

#include <Unit.h>
#include <Player.h>

class GameRules
{
public:
    GameRules();
    static int attackPower(Unit *attacker, Unit *target);
    static bool checkWin(Player *player);
};

#endif // GAMERULES_H
