#include "BoardScreen.h"
#include "ui_BoardScreen.h"
#include <QDebug>
#include <QLabel>
#include "Unit.h"
#include "Cell.h"

BoardScreen::BoardScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BoardScreen)
{
    ui->setupUi(this);

    QHBoxLayout* hLayout = new QHBoxLayout(ui->gridContainer_);
    hLayout->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    grid = new QGridLayout();
    grid->setSpacing(2);
    grid->setContentsMargins(0, 0, 0, 0);

    hLayout->addLayout(grid);
}


BoardScreen::~BoardScreen()
{
    delete ui;
}

void BoardScreen::loadDynamicMap(const QString &mapFilePath, const QString &layoutFilePath) {
    if (!m_boardLinkedList.loadMap(mapFilePath)) return;
    m_boardLinkedList.applyLayout(layoutFilePath);

    while (QLayoutItem *item = grid->takeAt(0)) {
        if (item->widget()) item->widget()->deleteLater();
        delete item;
    }

    CellNode* node = m_boardLinkedList.getHead();
    int row = 0, col = 0;
    QString currentLetter;

    while (node) {
        QString letter = node->cell->id().left(1);
        if (currentLetter.isEmpty()) currentLetter = letter;
        if (letter != currentLetter) {
            row++;
            col = 0;
            currentLetter = letter;
        }

        int visualCol = (letter == "B") ? (col * 2 + 1) : (col * 2);

        int shieldValue = node->cell->type();
        QString displayText = QString("%1 (️%2)").arg(node->cell->id()).arg(shieldValue);

        if (node->cell->unit()) {
            Unit* u = node->cell->unit();
            QString uName = (u->type() == UnitType::Scout) ? "Scout" :
                                (u->type() == UnitType::Sniper) ? "Sniper" : "Sergeant";
            displayText += QString("\n%1 (%2)").arg(uName, u->owner());
        }

        QLabel* lbl = new QLabel(displayText, this);
        lbl->setAlignment(Qt::AlignCenter);
        lbl->setMinimumSize(100, 70);

        QString bgColor;
        CellState state = node->cell->state();

        if (state == ControlledP1) {
            bgColor = "#2E5894";
        } else if (state == ControlledP2) {
            bgColor = "#A52A2A";
        } else {
            int shield = node->cell->type();
            bgColor = (shield == 0) ? "#96714e" : (shield == 1) ? "#5c826b" : "#292929";
        }

        QString borderStyle = "0px solid black";

        if (state == ObservedP1) {
            borderStyle = "5px solid #0044ab";
        } else if (state == ObservedP2) {
            borderStyle = "5px solid #0d8500";
        }

        lbl->setStyleSheet(QString("background-color: %1; "
                                   "border: %2; "
                                   "color: white; "
                                   "font-weight: bold; "
                                   "border-radius: 2px;")
                               .arg(bgColor, borderStyle));

        grid->addWidget(lbl, row, visualCol, 1, 2);

        col++;
        node = node->next;
    }
    this->update();
}
