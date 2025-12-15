#ifndef BOARDLINKEDLIST_H
#define BOARDLINKEDLIST_H

#include "CellNode.h"
#include <QString>

class BoardLinkedList
{
public:
    BoardLinkedList();
    ~BoardLinkedList();

    bool loadMap(const QString &mapName);
    CellNode* getHead() const { return head; }
    void clear();

private:
    CellNode* head;
};

#endif
