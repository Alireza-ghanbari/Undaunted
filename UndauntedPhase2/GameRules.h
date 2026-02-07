#ifndef GAMERULES_H
#define GAMERULES_H

#include <Unit.h>
#include <Player.h>

class Unit;
class Cell;

class GameRules
{
public:
    GameRules();
    static int attackPower(Unit *attacker, Unit *target);
    static bool checkWin(Player *player);
    static bool canMove(Unit *unit, Cell *target);
    static bool canAttack(Unit *attacker, Unit *defender);
};

#endif // GAMERULES_H
