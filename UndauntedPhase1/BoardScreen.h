#ifndef BOARDSCREEN_H
#define BOARDSCREEN_H

#include <QWidget>
#include "Board.h"
#include "QGridLayout"

namespace Ui {
class BoardScreen;
}

class BoardScreen : public QWidget
{
    Q_OBJECT

public:
    explicit BoardScreen(QWidget *parent = nullptr);
    ~BoardScreen();

    void loadMap(const QString &mapName);

private:
    Ui::BoardScreen *ui;

    Board m_board;
    QGridLayout *grid;
};

#endif // BOARDSCREEN_H
