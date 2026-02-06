#ifndef UNIT_H
#define UNIT_H

#include <QString>

class Cell;
class Player;

enum class UnitType {
    Scout,
    Sniper,
    Sergeant
};

class Unit
{
public:
    Unit(UnitType type, Player *owner);

    UnitType type() const;
    int hp() const;

    void setCell(Cell *cell);
    Cell* cell() const;

    Player* owner() const;

private:
    UnitType m_type;
    int m_hp;
    Cell *m_cell = nullptr;
    Player *m_owner = nullptr;
};

#endif
