#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>

class GameState;
class Unit;
class Cell;

class GameController : public QObject
{
    Q_OBJECT

public:
    explicit GameController(GameState *state, QObject *parent = nullptr);

    void onCellClicked(Cell *cell);

signals:
    void boardUpdated();

private:
    GameState *m_state;
};

#endif
