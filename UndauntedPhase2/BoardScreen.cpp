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
        QString displayText = node->cell->id();

        if (node->cell->unit()) {
            Unit* u = node->cell->unit();
            QString uName = (u->type() == UnitType::Scout) ? "SCT" :
                                (u->type() == UnitType::Sniper) ? "SNP" : "SRG";

            displayText += QString("\n%1 (%2)").arg(uName, u->owner());
        }

        QLabel* lbl = new QLabel(displayText, this);
        lbl->setAlignment(Qt::AlignCenter);
        lbl->setMinimumSize(100, 60);

        QString bgColor;
        if (node->cell->state() == ControlledP1) bgColor = "#2E5894";
        else if (node->cell->state() == ControlledP2) bgColor = "#A52A2A";
        else {
            int shield = node->cell->type();
            bgColor = (shield == 0) ? "#ad5603" : (shield == 1) ? "#1e693b" : "#171c19";
        }

        QString border = "1px solid black";
        if (node->cell->state() == ObservedP1) border = "4px solid #00FFFF";
        else if (node->cell->state() == ObservedP2) border = "4px solid #FFA500";

        lbl->setStyleSheet(QString("background:%1; border:%2; color:white; font-weight:bold;").arg(bgColor, border));
        grid->addWidget(lbl, row, visualCol, 1, 2);

        col++;
        node = node->next;
    }
    this->update();
}
