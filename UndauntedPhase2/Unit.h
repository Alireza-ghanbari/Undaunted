#ifndef UNIT_H
#define UNIT_H

#include <QString>

class Cell;

enum class UnitType { Scout, Sniper, Sergeant };

class Unit {
public:
    Unit(UnitType type, QString ownerName)
        : m_type(type), m_ownerName(ownerName), m_hp(1), m_currentCell(nullptr) {}

    QString owner() const { return m_ownerName; }
    UnitType type() const { return m_type; }
    int hp() const { return m_hp; }
    void setHp(int value) { m_hp = value; }

    Cell* cell() const { return m_currentCell; }
    void setCell(Cell* c) { m_currentCell = c; }

private:
    UnitType m_type;
    QString m_ownerName;
    int m_hp;
    Cell* m_currentCell;
};

#endif
