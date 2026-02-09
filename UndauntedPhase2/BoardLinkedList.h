#ifndef BOARDLINKEDLIST_H
#define BOARDLINKEDLIST_H

#include "Cell.h"

struct CellNode {
    Cell* cell;
    CellNode* next;

    CellNode(Cell* c) : cell(c), next(nullptr) {}
};

class BoardLinkedList {
public:
    BoardLinkedList();
    ~BoardLinkedList();

    bool loadMap(const QString &mapName);
    void clear();

    void buildNeighbors();
    CellNode* head;
};

#endif
