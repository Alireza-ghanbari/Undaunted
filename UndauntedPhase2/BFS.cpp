#include "BFS.h"
#include "Cell.h"
#include <QQueue>
#include <QSet>

QVector<Cell*> BFS::traverse(Cell *start)
{
    QVector<Cell*> result;
    QQueue<Cell*> queue;
    QSet<Cell*> visited;

    queue.enqueue(start);
    visited.insert(start);

    while (!queue.isEmpty()) {
        Cell *c = queue.dequeue();
        result.append(c);

        for (Cell *n : c->neighbors()) {
            if (n && !visited.contains(n)) {
                visited.insert(n);
                queue.enqueue(n);
            }
        }
    }
    return result;
}
