#include "Unit.h"

Unit::Unit(UnitType type, Player *owner)
    : m_type(type), m_owner(owner)
{
    switch (type) {
    case UnitType::Scout:     m_hp = 5; break;
    case UnitType::Sniper:   m_hp = 4; break;
    case UnitType::Sergeant: m_hp = 3; break;
    }
}

UnitType Unit::type() const { return m_type; }
int Unit::hp() const { return m_hp; }

void Unit::setCell(Cell *cell) { m_cell = cell; }
Cell* Unit::cell() const { return m_cell; }

Player* Unit::owner() const { return m_owner; }
