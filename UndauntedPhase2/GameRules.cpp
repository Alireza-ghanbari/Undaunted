#include "GameRules.h"
#include "Unit.h"
#include "Cell.h"
#include "BFS.h"

bool GameRules::canMove(Unit *unit, Cell *target)
{
    if (!unit || !target)
        return false;

    if (target->unit() != nullptr)
        return false;

    auto path = BFS::path(unit->cell(), target);

    int maxDistance = 0;
    switch (unit->type()) {
    case UnitType::Scout:     maxDistance = 4; break;
    case UnitType::Sniper:   maxDistance = 2; break;
    case UnitType::Sergeant: maxDistance = 3; break;
    }

    return path.size() - 1 <= maxDistance;
}

bool GameRules::canAttack(Unit *attacker, Unit *defender)
{
    if (!attacker || !defender)
        return false;

    auto path = BFS::path(attacker->cell(), defender->cell());

    int range = (attacker->type() == UnitType::Sniper) ? 4 : 1;
    return path.size() - 1 <= range;
}
