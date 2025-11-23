#include "BoardScreen.h"
#include "ui_BoardScreen.h"
#include <QDebug>
#include <QLabel>

BoardScreen::BoardScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BoardScreen)
{
    ui->setupUi(this);

    grid = new QGridLayout(ui->gridContainer_);
    grid->setSpacing(2);
    grid->setContentsMargins(15, 15, 15, 15);
}

BoardScreen::~BoardScreen()
{
    delete ui;
}


void BoardScreen::loadMap(const QString &mapName)
{
    if (!m_board.loadMap(mapName)) {
        qDebug() << "Failed to load map:" << mapName;
        return;
    }

    while (QLayoutItem *item = grid->takeAt(0)) {
        if (item->widget())
            item->widget()->deleteLater();
        delete item;
    }

    const auto &cells = m_board.cells();

    int row = 0;
    int col = 0;

    QString currentLetter = cells[0].id().left(1);

    for (int i = 0; i < cells.size(); i++)
    {
        const Cell &c = cells[i];
        QString letter = c.id().left(1);

        if (letter != currentLetter) {
            row++;
            col = 0;
            currentLetter = letter;
        }

        int visualCol = col;
        if (letter == "B")
            visualCol += 1;

        QString text = QString("%1 (%2)")
                           .arg(c.id())
                           .arg(c.type());

        QLabel *lbl = new QLabel(text, this);

        lbl->setAlignment(Qt::AlignCenter);
        lbl->setMinimumSize(60, 60);

        QString color =
            (c.type() == 0) ? "#ad5603" :
                (c.type() == 1) ? "#1e693b" :
                "#171c19";

        lbl->setStyleSheet(
            QString("background:%1; border:1px solid black;").arg(color)
            );

        grid->addWidget(lbl, row, visualCol);

        col++;
    }
}

