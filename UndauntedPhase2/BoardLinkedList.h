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
    bool applyLayout(const QString &layoutFilePath);
    void clear();
    CellNode* getHead() const { return head; }
    Cell* findCellById(const QString &id) const;

private:
    void buildNeighbors();
    void parseStatusLine(const QString &line);
    CellNode* head;
};

#endif
