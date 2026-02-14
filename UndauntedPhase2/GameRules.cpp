#include "GameRules.h"
#include "Unit.h"
#include "Cell.h"
#include "Player.h"

int GameRules::attackPower(Unit *attacker, Unit *target)
{
    if (!attacker || !target) return 0;

    int base = 0;
    switch (attacker->type()) {
    case UnitType::Scout:     base = 2; break;
    case UnitType::Sniper:    base = 4; break;
    case UnitType::Sergeant:  base = 3; break;
    }

    return base;
}

bool GameRules::checkWin(Player *player)
{
    if (!player) return false;

    const QVector<Unit*>& playerUnits = player->units();
    if (playerUnits.isEmpty()) return false;

    for (Unit *u : playerUnits) {
        if (u->hp() > 0) return false;
    }

    return true;
}

bool GameRules::canMove(Unit *unit, Cell *target)
{
    if (!unit || !target) return false;
    if (target->unit() != nullptr) return false;

    Cell* current = unit->cell();
    if (!current) return false;

    return current->neighbors().contains(target);
}

bool GameRules::canAttack(Unit *attacker, Unit *defender)
{
    if (!attacker || !defender) return false;
    if (attacker->owner() == defender->owner()) return false;

    return true;
}
