#ifndef CELL_H
#define CELL_H

#include <QString>
#include <QList>

class Unit;

enum CellState {
    Neutral,
    ObservedP1,
    ObservedP2,
    ControlledP1,
    ControlledP2
};

class Cell
{
public:
    Cell();
    Cell(const QString &id, int type);

    QString id() const { return m_id; }
    int type() const { return m_type; }

    void addNeighbor(Cell* c);
    QList<Cell*> neighbors() const;

    void setUnit(Unit* u);
    Unit* unit() const;

    void setState(CellState s);
    CellState state() const;

private:
    QString m_id;
    int m_type;

    QList<Cell*> m_neighbors;
    Unit* m_unit = nullptr;
    CellState m_state = Neutral;
};

#endif
