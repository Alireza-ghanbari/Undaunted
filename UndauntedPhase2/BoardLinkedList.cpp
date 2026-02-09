#include "BoardLinkedList.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

BoardLinkedList::BoardLinkedList() : head(nullptr) {}

BoardLinkedList::~BoardLinkedList()
{
    clear();
}

bool BoardLinkedList::loadMap(const QString &mapName)
{
    clear();

    QString filePath = ":/maps/" + mapName + ".txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot load map:" << filePath;
        return false;
    }

    QTextStream in(&file);
    CellNode* last = nullptr;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split("|", Qt::SkipEmptyParts);

        for (const QString &p : parts) {
            QStringList data = p.trimmed().split(":");
            if (data.size() != 2) continue;

            Cell* cell = new Cell(data[0], data[1].toInt());
            CellNode* node = new CellNode(cell);

            if (!head) {
                head = node;
                last = node;
            } else {
                last->next = node;
                last = node;
            }
        }
    }

    return true;
}

void BoardLinkedList::clear()
{
    CellNode* current = head;
    while (current) {
        CellNode* temp = current;
        current = current->next;

        delete temp->cell;
        delete temp;
    }
    head = nullptr;
}

void BoardLinkedList::buildNeighbors()
{
    CellNode* a = head;

    while (a) {
        CellNode* b = head;

        while (b) {
            if (a == b) { b = b->next; continue; }

            QString id1 = a->cell->id();
            QString id2 = b->cell->id();

            QString row1 = id1.left(1);
            int col1 = id1.mid(1).toInt();

            QString row2 = id2.left(1);
            int col2 = id2.mid(1).toInt();

            if (row1 == row2 && qAbs(col1 - col2) == 1)
                a->cell->addNeighbor(b->cell);

            if (qAbs(row1[0].unicode() - row2[0].unicode()) == 1 && col1 == col2)
                a->cell->addNeighbor(b->cell);

            b = b->next;
        }
        a = a->next;
    }
}

