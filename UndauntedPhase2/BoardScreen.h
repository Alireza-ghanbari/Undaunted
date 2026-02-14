#ifndef BOARDSCREEN_H
#define BOARDSCREEN_H

#include <QWidget>
#include <QGridLayout>
#include "BoardLinkedList.h"

namespace Ui { class BoardScreen; }

class BoardScreen : public QWidget
{
    Q_OBJECT
public:
    explicit BoardScreen(QWidget *parent = nullptr);
    ~BoardScreen();
    void loadDynamicMap(const QString &mapFilePath, const QString &layoutFilePath);

private:
    Ui::BoardScreen *ui;
    QGridLayout *grid;
    BoardLinkedList m_boardLinkedList;
};

#endif
