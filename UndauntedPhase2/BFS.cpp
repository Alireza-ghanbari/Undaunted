#include "BFS.h"
#include "Cell.h"
#include <QQueue>
#include <QSet>
#include <QMap>

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

QVector<Cell*> BFS::path(Cell *start, Cell *end)
{
    QQueue<Cell*> queue;
    QMap<Cell*, Cell*> parent;
    QSet<Cell*> visited;

    queue.enqueue(start);
    visited.insert(start);
    parent[start] = nullptr;

    while (!queue.isEmpty()) {
        Cell *current = queue.dequeue();

        if (current == end)
            break;

        for (Cell *n : current->neighbors()) {
            if (n && !visited.contains(n)) {
                visited.insert(n);
                parent[n] = current;
                queue.enqueue(n);
            }
        }
    }

    QVector<Cell*> path;
    if (!parent.contains(end))
        return path;

    for (Cell *c = end; c != nullptr; c = parent[c])
        path.prepend(c);

    return path;
}
