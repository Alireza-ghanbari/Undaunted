#include "Cell.h"

Cell::Cell() : m_type(0) {}

Cell::Cell(const QString &id, int type)
    : m_id(id), m_type(type)
{
}
