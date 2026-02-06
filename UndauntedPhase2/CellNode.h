#ifndef CELLNODE_H
#define CELLNODE_H

#include "Cell.h"

struct CellNode {
    Cell data;
    CellNode* next;

    CellNode(const Cell& c) : data(c), next(nullptr) {}
};

#endif
