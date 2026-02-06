#include "Cell.h"
#include "Unit.h"

Cell::Cell() {}

Cell::Cell(const QString &id, int type)
    : m_id(id), m_type(type)
{}

QString Cell::id() const { return m_id; }
int Cell::type() const { return m_type; }

void Cell::setUnit(Unit *unit)
{
    m_unit = unit;
}

Unit* Cell::unit() const
{
    return m_unit;
}

void Cell::addNeighbor(Cell *cell)
{
    if (cell && !m_neighbors.contains(cell))
        m_neighbors.append(cell);
}

const QList<Cell*>& Cell::neighbors() const
{
    return m_neighbors;
}
