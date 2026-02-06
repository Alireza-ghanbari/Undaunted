#ifndef CELL_H
#define CELL_H

#include <QString>
#include <QList>

class Unit;

class Cell
{
public:
    Cell();
    Cell(const QString &id, int type);

    QString id() const;
    int type() const;

    // ---- فاز ۲ ----
    void setUnit(Unit *unit);
    Unit* unit() const;

    void addNeighbor(Cell *cell);
    const QList<Cell*>& neighbors() const;

private:
    QString m_id;
    int m_type;

    Unit *m_unit = nullptr;
    QList<Cell*> m_neighbors;
};

#endif
