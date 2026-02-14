#include "BoardLinkedList.h"
#include "Unit.h"
#include <QFile>
#include <QTextStream>

BoardLinkedList::BoardLinkedList() : head(nullptr) {}

BoardLinkedList::~BoardLinkedList() {
    clear();
}

void BoardLinkedList::clear() {
    CellNode* current = head;
    while (current) {
        CellNode* temp = current;
        current = current->next;
        delete temp->cell;
        delete temp;
    }
    head = nullptr;
}

Cell* BoardLinkedList::findCellById(const QString &id) const {
    CellNode* curr = head;
    while (curr) {
        if (curr->cell->id() == id) return curr->cell;
        curr = curr->next;
    }
    return nullptr;
}

bool BoardLinkedList::loadMap(const QString &mapFilePath) {
    clear();
    QFile file(mapFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;

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
            if (!head) head = node;
            else last->next = node;
            last = node;
        }
    }
    buildNeighbors();
    return true;
}

bool BoardLinkedList::applyLayout(const QString &layoutFilePath) {
    QFile file(layoutFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty() || line.startsWith("[")) continue;
        parseStatusLine(line);
    }
    return true;
}

void BoardLinkedList::parseStatusLine(const QString &line) {
    QStringList parts = line.split(":");
    if (parts.size() < 2) return;

    Cell* target = findCellById(parts[0]);
    if (!target) return;

    QStringList details = parts[1].split(",");
    if (details.size() < 2) return;

    QString player = details[0].trimmed();
    QString type = details[1].trimmed().toLower();

    if (type == "control") {
        if (player == "A") target->setState(ControlledP1);
        else if (player == "B") target->setState(ControlledP2);
    }
    else if (type == "mark") {
        if (player == "A") target->setState(ObservedP1);
        else if (player == "B") target->setState(ObservedP2);
    }
    else {
        UnitType uType;
        if (type.contains("scout")) uType = UnitType::Scout;
        else if (type.contains("sniper")) uType = UnitType::Sniper;
        else uType = UnitType::Sergeant;

        Unit* newUnit = new Unit(uType, player);
        target->setUnit(newUnit);
        newUnit->setCell(target);
    }
}

void BoardLinkedList::buildNeighbors() {
    CellNode* a = head;
    while (a) {
        CellNode* b = head;
        while (b) {
            if (a == b) { b = b->next; continue; }
            QString id1 = a->cell->id();
            QString id2 = b->cell->id();
            QChar r1 = id1[0];
            int c1 = id1.mid(1).toInt();
            QChar r2 = id2[0];
            int c2 = id2.mid(1).toInt();

            if ((r1 == r2 && qAbs(c1 - c2) == 1) ||
                (qAbs(r1.unicode() - r2.unicode()) == 1 && c1 == c2)) {
                a->cell->addNeighbor(b->cell);
            }
            b = b->next;
        }
        a = a->next;
    }
}
