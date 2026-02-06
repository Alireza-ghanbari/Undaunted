#ifndef BFS_H
#define BFS_H

#include <QVector>

class Cell;

class BFS
{
public:
    static QVector<Cell*> traverse(Cell *start);
    static QVector<Cell*> path(Cell *start, Cell *end);
};

#endif
