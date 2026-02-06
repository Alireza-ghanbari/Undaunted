#ifndef CELL_H
#define CELL_H

#include <QString>

class Cell
{
public:
    Cell();
    Cell(const QString &id, int type);

    QString id() const { return m_id; }
    int type() const { return m_type; }

private:
    QString m_id;
    int m_type;
};

#endif
