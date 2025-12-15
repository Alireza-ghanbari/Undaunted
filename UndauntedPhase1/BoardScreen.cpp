#include "BoardScreen.h"
#include "ui_BoardScreen.h"
#include <QDebug>
#include <QLabel>

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


void BoardScreen::loadMap(const QString &mapName)
{
    if (!m_boardLinkedList.loadMap(mapName)) {
        qDebug() << "Failed to load map:" << mapName;
        return;
    }

    while (QLayoutItem *item = grid->takeAt(0)) {
        if (item->widget()) item->widget()->deleteLater();
        delete item;
    }

    CellNode* node = m_boardLinkedList.getHead();
    int row = 0;
    int col = 0;
    QString currentLetter;

    while (node) {
        QString letter = node->data.id().left(1);
        if (currentLetter.isEmpty()) currentLetter = letter;

        if (letter != currentLetter) {
            row++;
            col = 0;
            currentLetter = letter;
        }

        int visualCol = col * 2;

        if (letter == "B")
            visualCol += 1;


        QString text = QString("%1 (%2)").arg(node->data.id()).arg(node->data.type());
        QLabel* lbl = new QLabel(text, this);
        lbl->setAlignment(Qt::AlignCenter);
        lbl->setMinimumSize(140, 70);

        QString color = (node->data.type() == 0) ? "#ad5603" :
                            (node->data.type() == 1) ? "#1e693b" :
                            "#171c19";

        lbl->setStyleSheet(QString("background:%1; border:1px solid black;").arg(color));
        grid->addWidget(lbl, row, visualCol, 1, 2);

        col++;
        node = node->next;
    }
}

