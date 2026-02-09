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

        delete temp->cell;   // مهم
        delete temp;
    }
    head = nullptr;
}
