#include "Cell.h"

Cell::Cell() : m_type(0), m_unit(nullptr), m_state(Neutral) {}
Cell::Cell(const QString &id, int type) : m_id(id), m_type(type) {}

void Cell::addNeighbor(Cell *c) {
    m_neighbors.append(c);
}

QList<Cell*> Cell::neighbors() const {
    return m_neighbors;
}

void Cell::setUnit(Unit *u) {
    m_unit = u;
}

Unit* Cell::unit() const {
    return m_unit;
}

void Cell::setState(CellState s) {
    m_state = s;
}

CellState Cell::state() const {
    return m_state;
}
